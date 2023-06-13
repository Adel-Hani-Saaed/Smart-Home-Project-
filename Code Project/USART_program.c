/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: USART			  *******************/
/*************** Date: 15/4/2023 	  *******************/
/*************** Version: 2.00		  *******************/
/********************************************************/
/********************************************************/

#include "BIT_Math.h"
#include "STD_TYPES.h"

#define F_CUP 8000000UL
#include <util/delay.h>

#include "USART_config.h"
#include "USART_private.h"
#include "USART_register.h"
#include "USART_register.h"

/*Global variable to carry the Transmit Data*/
static pu8 USART_pu8String = NULL;

/*Global variable to carry the Receive Data*/
static pu8  USART_pu8ReceiveData = NULL ;

/*Global variable to carry the buffer size*/
static u8 USART_u8BufferSize ;

/*Global pointer to function to carry the notification function called by ISR*/
static void(* USART_pvCallBackNotificationFunc)(void) = NULL;

/*Global flag for the USART Busy State*/
static u8 USART_u8State= USART_IDEL ;

/*Global variable to indicate for the current Data index of the buffer*/
static u8 USART_u8Index;

void USART_voidInit (void)
{
	/* We will adjust this value according to the configrations then store it in UCSRC in one operation */
	u8 Local_u8UCSRC= 0 ;


	/*Check 3 Modes*/
#if (USART_MODE == ASYNCHRONOUS) && (USART_SYSTEM_SPEED == USART_NORMAL_SPEED)

	/*Calculate The Baud Rate From The Equation */
	u16 Local_u16UBRR = (u16)((SYSTEM_FREQUENCY / (16 * USART_BAUD_RATE)) - 1) ;

	/*
		Set Baud Rate
		Hint : UBRRH then UBRRL to avoid problems
	 */
	UBRRH_REG = (u8)(Local_u16UBRR >> 8) ; /* MSBs at Local_u16UBRR */
	UBRRL_REG = (u8)Local_u16UBRR ;

	/*Clear the Bit double speed*/
	CLR_BIT(UCSRA_REG , UCSRA_U2X) ;

	/*Clear Mode selct Bit to selet the Asychn operation*/
	CLR_BIT(Local_u8UCSRC , UCSRC_UMSEL) ;

#elif (USART_MODE == ASYNCHRONOUS) && (USART_SYSTEM_SPEED == USART_DOUBLE_SPEED)

	/*Calculate The Baud Rate From The Equation */
	u16 Local_u16UBRR = (u16)((SYSTEM_FREQUENCY / (8 * USART_BAUD_RATE)) - 1) ;

	/*
		Set Baud Rate
		Hint : UBRRH then UBRRL to avoid problems
	 */
	UBRRH_REG = (u8)(Local_u16UBRR >> 8) ; /* MSBs at Local_u16UBRR */
	UBRRL_REG = (u8)Local_u16UBRR ;

	/*Set the Douple speed*/
	SET_BIT(UCSRA_REG , UCSRA_U2X) ;

	/*Clear Mode selct Bit to selet the Asychn operation*/
	CLR_BIT(Local_u8UCSRC , UCSRC_UMSEL) ;

#elif (USART_MODE == SYNCHRONOUS)

	/*Calculate The Baud Rate From The Equation */
	u16 Local_u16UBRR = (u16)((SYSTEM_FREQUENCY / (2 * USART_BAUD_RATE)) - 1) ;
	/*
		Set Baud Rate
		Hint : UBRRH then UBRRL to avoid problems
	 */
	UBRRH_REG = (u8)(Local_u16UBRR >> 8) ; /* MSBs at Local_u16UBRR */
	UBRRL_REG = (u8)Local_u16UBRR ;

	/*Set Mode selct Bit to selet the sychn operation*/
	SET_BIT(Local_u8UCSRC , UCSRC_UMSEL) ;

	/*Clock Polarity (for SYNCHRONOUS mode only)*/
#if USART_CLOCK_POLARITY == XCK_RISING_TX_XCH_FALLING_RX
	CLR_BIT(Local_u8UCSRC , UCSRC_UCPOL) ;
#elif USART_CLOCK_POLARITY == XCK_RISING_RX_XCH_FALLING_TX
	SET_BIT(Local_u8UCSRC , UCSRC_UCPOL) ;
#else
#error "Wrong USART_STOP_BIT config"
#endif


#else
#error "Wrong USART_MODE or USART_SYSTEM_SPEED config"
#endif


	/*Multi-Processor Communication mode*/
#if USART_MPCM == DISABLE
	CLR_BIT(UCSRA_REG , UCSRA_MPCM) ;
#elif USART_MPCM == ENABLE
	SET_BIT(UCSRA_REG , UCSRA_MPCM) ;
#else
#error "Wrong USART_MPCM config"
#endif


	/*Config Register UCSRC  Important the register control*/
	/*Parity Mode Frame*/
#if USART_PARITY_MODE == DISABLE
	CLR_BIT(Local_u8UCSRC , UCSRC_UPM0) ;
	CLR_BIT(Local_u8UCSRC , UCSRC_UPM1) ;
#elif USART_PARITY_MODE == EVEN_PARITY
	CLR_BIT(Local_u8UCSRC , UCSRC_UPM0) ;
	SET_BIT(Local_u8UCSRC , UCSRC_UPM1) ;
#elif USART_PARITY_MODE == ODD_PARITY
	SET_BIT(Local_u8UCSRC , UCSRC_UPM0) ;
	SET_BIT(Local_u8UCSRC , UCSRC_UPM1) ;
#else
#error "Wrong USART_PARITY_MODE config"
#endif


	/*Stop Bit Frame*/
#if USART_STOP_BIT == STOP_BIT_1
	CLR_BIT(Local_u8UCSRC , UCSRC_USBS);
#elif USART_STOP_BIT == STOP_BIT_2
	SET_BIT(Local_u8UCSRC, UCSRC_USBS);
#else
#error "Wrong USART_STOP_BIT Config"
#endif



	/*Data Size Frame*/
#if USART_DATA_SIZE == DATA_SIZE_5_BIT
	CLR_BIT(Local_u8UCSRC , UCSRC_UCSZ0) ;
	CLR_BIT(Local_u8UCSRC , UCSRC_UCSZ1) ;
	CLR_BIT(UCSRB_REG , UCSRB_UCSZ2) ;
#elif USART_DATA_SIZE == DATA_SIZE_6_BIT
	SET_BIT(Local_u8UCSRC , UCSRC_UCSZ0) ;
	CLR_BIT(Local_u8UCSRC , UCSRC_UCSZ1) ;
	CLR_BIT(UCSRB_REG , UCSRB_UCSZ2) ;
#elif USART_DATA_SIZE == DATA_SIZE_7_BIT
	CLR_BIT(Local_u8UCSRC , UCSRC_UCSZ0) ;
	SET_BIT(Local_u8UCSRC , UCSRC_UCSZ1) ;
	CLR_BIT(UCSRB_REG , UCSRB_UCSZ2) ;
#elif USART_DATA_SIZE == DATA_SIZE_8_BIT
	SET_BIT(Local_u8UCSRC , UCSRC_UCSZ0) ;
	SET_BIT(Local_u8UCSRC , UCSRC_UCSZ1) ;
	CLR_BIT(UCSRB_REG , UCSRB_UCSZ2) ;
#elif USART_DATA_SIZE == DATA_SIZE_9_BIT
	SET_BIT(Local_u8UCSRC , UCSRC_UCSZ0) ;
	SET_BIT(Local_u8UCSRC , UCSRC_UCSZ1) ;
	SET_BIT(UCSRB_REG , UCSRB_UCSZ2) ;
#else
#error "Wrong USART_DATA_SIZE config"
#endif



	/*Set UCSRC Mode Register must set */
	SET_BIT(Local_u8UCSRC , UCSRC_URSEL) ;

	/*Store the value in UCSRC Register (one operation) */
	UCSRC_REG = Local_u8UCSRC ;



	/*Config Register UCSRB  Enables components*/

	/*RX Complete Interrupt Enable*/
#if USART_RX_COMPLETE_INTERRUPT == DISABLE
	CLR_BIT(UCSRB_REG , UCSRB_RXCIE) ;
#elif USART_RX_COMPLETE_INTERRUPT == ENABLE
	SET_BIT(UCSRB_REG , UCSRB_RXCIE) ;
#else
#error "Wrong USART_RX_COMPLETE_INTERRUPT config"
#endif

	/*TX Complete Interrupt Enable*/
#if USART_TX_COMPLETE_INTERRUPT == DISABLE
	CLR_BIT(UCSRB_REG , UCSRB_TXCIE) ;
#elif USART_TX_COMPLETE_INTERRUPT == ENABLE
	SET_BIT(UCSRB_REG , UCSRB_TXCIE) ;
#else
#error "Wrong USART_TX_COMPLETE_INTERRUPT config"
#endif

	/*UDR Empty Interrupt Enable*/
#if USART_UDR_EMPTY_INTERRUPT == DISABLE
	CLR_BIT(UCSRB_REG , UCSRB_UDRIE) ;
#elif USART_UDR_EMPTY_INTERRUPT == ENABLE
	SET_BIT(UCSRB_REG , UCSRB_UDRIE) ;
#else
#error "Wrong USART_UDR_EMPTY_INTERRUPT config"
#endif

	/*Receive Enable*/
#if USART_RECEIVER_ENABLE == DISABLE
	CLR_BIT(UCSRB_REG , UCSRB_RXEN) ;
#elif USART_RECEIVER_ENABLE == ENABLE
	SET_BIT(UCSRB_REG , UCSRB_RXEN) ;
#else
#error "Wrong USART_RECEIVER_ENABLE config"
#endif

	/*Transmitter Enable*/
#if USART_TRANSMITTER_ENABLE == DISABLE
	CLR_BIT(UCSRB_REG , UCSRB_TXEN) ;
#elif USART_TRANSMITTER_ENABLE == ENABLE
	SET_BIT(UCSRB_REG , UCSRB_TXEN) ;
#else
#error "Wrong USART_TRANSMITTER_ENABLE config"
#endif

}


u8 USART_u8SendData (u8 Copy_u8Data)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	/*Counter TimeOut*/
	u32 Local_u32TimerCounterOut = 0;

	/*HINT:*****************
	 * is Safety for the Function is run and interrupt happen and call function again */
	if(USART_u8State == USART_IDEL)
	{
		/*Make USART is now Busy*/
		USART_u8State = USART_BUSY;

		/*
			Hint : TIMEOUT to avoid infinity loop
		 */
		/*Polling (Busy waiting) until The  transmit complete flag is set or Counter reaching Timeout_Value */
		while (((GET_BIT(UCSRA_REG , UCSRA_UDRE)) == 0) && (Local_u32TimerCounterOut != USART_u32TIMEOUT))
		{
			Local_u32TimerCounterOut++ ;
		}

		if (Local_u32TimerCounterOut == USART_u32TIMEOUT)
		{
			/*Loop is broken because the timeout is reaching*/
			Local_u8ErrorState = STD_TIMEOUT_STATE ;
		}

		else
		{
			/*Write in Register UDR*/
			UDR_REG = Copy_u8Data ;
		}
		/*Make USART State be IDLE because is finished*/
		USART_u8State = USART_IDEL;
	}

	else
	{
		/*Function is not finished  */
		Local_u8ErrorState = BUSY_FUNC;
	}

	/*Return error state*/
	return Local_u8ErrorState;
}




u8 USART_u8RecevieData (u8 *Copy_u8ReceviedData)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	/*Counter TimeOut*/
	u32 Local_u32TimerCounterOut = 0;

	if (USART_u8State == USART_IDEL)
	{

		USART_u8State = USART_BUSY;

		/*
			Hint : TIMEOUT to avoid infinity loop
		 */
		/*Polling (Busy waiting) until The  Receiving complete flag is set or Counter reaching Timeout_Value */
		while((GET_BIT(UCSRA_REG , UCSRA_RXC) == 0 ) && (Local_u32TimerCounterOut != USART_u32TIMEOUT))
		{
			Local_u32TimerCounterOut++;
		}

		if (Local_u32TimerCounterOut == USART_u32TIMEOUT)
		{
			/*Loop is broken because the timeout is reaching*/
			Local_u8ErrorState = STD_TIMEOUT_STATE;
		}

		else
		{
			/*Read data*/
			*Copy_u8ReceviedData = UDR_REG;
		}
		/*Make USART State be IDLE because is finished*/
		USART_u8State = USART_IDEL;
	}

	else
	{
		/*Function is not finished  */
		Local_u8ErrorState = BUSY_FUNC;
	}

	/*Return error state*/
	return Local_u8ErrorState;
}

u8 USART_u8SendStringSynch (const char * Copy_pchString)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 Local_u8Counter = 0;

	if (Copy_pchString != NULL)
	{
		while(Copy_pchString[Local_u8Counter] != '\0')
		{
			USART_u8SendData(Copy_pchString[Local_u8Counter]);
			Local_u8Counter++;
		}
	}

	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}


u8 USART_u8SendStringAsynch (const char * Copy_pchString , void (* Copy_PvNotificationFunction)(void))
{
	u8 Local_u8ErrorState= STD_TYPES_OK;
	if (USART_u8State == USART_IDEL)
	{
		if ((Copy_pchString != NULL) && (Copy_PvNotificationFunction != NULL))
		{
			/*Make USART is now Busy
			 * Hint: this function non_reentrant  and  i put State in first line to avoid the corruption data
			 * because not Send and if interrupt call function the Busy state save function
			 * */
			USART_u8State = USART_BUSY;

			/*Assign the USART data globally*/
			USART_pu8String = Copy_pchString;
			USART_pvCallBackNotificationFunc = Copy_PvNotificationFunction;

			/*Set Index to first element*/
			USART_u8Index = 0 ;

			/*Send first Data */
			UDR_REG = USART_pu8String[USART_u8Index] ;

			/* Hint:     if Send the first char in this function you can enable interrupt UDRE Or TXC
			 	    but  if not sending the first char in this function you must enable interrupt UDRE only*/
			/*USART Transmit Interrupt Enable TXC*/
			SET_BIT(UCSRB_REG , UCSRB_TXCIE) ;
		}
		else
		{
			Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC;
	}
	return Local_u8ErrorState;

}

/* ISR for TX complete */
void __vector_15 (void)	__attribute__ ((signal)) ;
void __vector_15 (void)
{
	/*Increment Data index of the buffer*/
	USART_u8Index++ ;

	/*Sending String is Complete*/
	if ( USART_pu8String [USART_u8Index] == '\0' )
	{
		/*Receive Data Complete*/
		USART_u8Index=0;

		/*USART is now IDLE*/
		USART_u8State = USART_IDEL;

		/*Call Notification Function*/
		USART_pvCallBackNotificationFunc() ;

		/*USART Transmit Interrupt Disable*/
		CLR_BIT(UCSRB_REG , UCSRB_TXCIE) ;

	}

	/*Sending String is not Complete*/
	else
	{
		/*Transmit next Data*/
		UDR_REG = USART_pu8String[USART_u8Index] ;
	}
}


u8 USART_voidGetChar(void)
{
	while((GET_BIT(UCSRA_REG , UCSRA_RXC) == 0 ));
	return UDR_REG;
}

void USART_voidReceiveString(u8 *Copy_pchString)
{
	u8 Local_u8Counter = 0;

	Copy_pchString[Local_u8Counter] = USART_voidGetChar();

		while( Copy_pchString[Local_u8Counter] != '\0' )
		{
			Local_u8Counter++;
			Copy_pchString[Local_u8Counter] = USART_voidGetChar();
		}

		Copy_pchString[Local_u8Counter] = '\0' ;
}


u8 USART_u8ReceiveBufferSynch (u8 *Copy_pchString , u32 Copy_uint32BufferSize)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 Local_u8Counter = 0;


		while( Local_u8Counter < Copy_uint32BufferSize )
		{
			USART_u8RecevieData(&Copy_pchString[Local_u8Counter]);
			Local_u8Counter++;
		}



	return Local_u8ErrorState;

}


u8 USART_u8ReceiveBufferAsynch (u8 * Copy_pchString , u32 Copy_uint32BufferSize , void (* Copy_PvNotificationFunction)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if (USART_u8State == USART_IDEL)
	{
		if ((Copy_pchString != NULL) && (Copy_PvNotificationFunction != NULL))
		{
			/*Make USART is now Busy
			 * Hint: this function non_reentrant  and  i put State in first line to avoid the corruption data
			 * because not Send and if interrupt call function the Busy state save function
			 * */
			USART_u8State = USART_BUSY;

			/*Assign the USART data globally*/
			USART_pu8ReceiveData = Copy_pchString;
			USART_u8BufferSize = Copy_uint32BufferSize;
			USART_pvCallBackNotificationFunc = Copy_PvNotificationFunction;

			/*Set Index to first element*/
			USART_u8Index = 0 ;

			/*USART Transmit Interrupt Enable RXC*/
			SET_BIT(UCSRB_REG , UCSRB_RXCIE) ;
		}
		else
		{
			Local_u8ErrorState =STD_TYPES_NOK;
		}
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC;
	}

	return Local_u8ErrorState;
}

/* ISR for RX complete */
void __vector_13 (void)	__attribute__ ((signal)) ;
void __vector_13 (void)
{
	/*Receive next Data*/
	USART_pu8ReceiveData[USART_u8Index] = UDR_REG ;

	/*Increment Data index of the buffer*/
	USART_u8Index++ ;

	/*Send Data Complete*/
	if (USART_u8Index == USART_u8BufferSize)
	{
		USART_u8Index=0;

		/*USART is now IDLE*/
		USART_u8State = USART_IDEL ;

		/*Call Notification Function*/
		USART_pvCallBackNotificationFunc();

		/*USART Recieve Interrupt Disable*/
		CLR_BIT(UCSRB_REG , UCSRB_RXCIE) ;
	}
	else
	{
		/*Do Noting*/
	}
}

