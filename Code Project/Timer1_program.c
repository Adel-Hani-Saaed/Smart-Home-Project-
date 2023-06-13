/********************************************************/
/********************************************************/
/*************** Author: Adel_Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: Timer1		  *******************/
/*************** Date: 31/3/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/


#include "BIT_Math.h"
#include "STD_TYPES.h"

#include "Timer1_config.h"
#include "Timer1_interface.h"
#include "Timer1_private.h"  				//Hint: must include the file private before file configuration
#include "Timer1_register.h"



static void (*Timer1_pvCallBackFuncOverFlowMode)(void) = NULL;
static void (*Timer1_pvCallBackFuncCTCModeChannel_A)(void) = NULL;
static void (*Timer1_pvCallBackFuncCTCModeChannel_B)(void) = NULL;

static void (*ICU_pvCallBackFunc)(void) = NULL;


void TIMER1_voidInit(void)
{
	/*Set Configurable Modes*/
#if TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_NORMAL_MODE

	/*Set Waveform generation mode as Normal mode */
	CLR_BIT(TCCR1A_REG,TCCR1A_WGM10);
	CLR_BIT(TCCR1A_REG,TCCR1A_WGM11);
	CLR_BIT(TCCR1B_REG,TCCR1B_WGM12);
	CLR_BIT(TCCR1B_REG,TCCR1B_WGM13);

	/*Set the require Pr_eload Value*/
	TCNT1_REG = TIMER1_PRELOAD_VAL ;

	/*Timer1 Overflow Interrupt Enable*/
#if TIMER1_OVERFLOW_INTERRUPT == DISABLE
	CLR_BIT(TIMSK_REG , TIMSK_TOIE1) ;
#elif TIMER1_OVERFLOW_INTERRUPT == ENABLE
	SET_BIT(TIMSK_REG , TIMSK_TOIE1) ;
#else
#error "Wrong TIMER1_OVERFLOW_INTERRUPT Config"
#endif

#elif (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_CTC_OCR1A_MODE) || (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_CTC_ICR1_MODE)

	/*Set Waveform generation mode as CTC modes */
#if TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_CTC_ICR1_MODE
	CLR_BIT(TCCR1A_REG,TCCR1A_WGM10);
	CLR_BIT(TCCR1A_REG,TCCR1A_WGM11);
	SET_BIT(TCCR1B_REG,TCCR1B_WGM12);
	SET_BIT(TCCR1B_REG,TCCR1B_WGM13);
#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_CTC_OCR1A_MODE
	CLR_BIT(TCCR1A_REG,TCCR1A_WGM10);
	CLR_BIT(TCCR1A_REG,TCCR1A_WGM11);
	SET_BIT(TCCR1B_REG,TCCR1B_WGM12);
	CLR_BIT(TCCR1B_REG,TCCR1B_WGM13);
#else
#error "Wrong TIMER1_WAVEFORM_GENERATION_MODE Config"
#endif

	/*Set the require CTC Values*/
	OCR1A_REG = TIMER1_CTCA_VAL ;
	OCR1B_REG = TIMER1_CTCB_VAL ;

	/*Set ICR1 if TIMER1_CTC_OCR1A_MODE = TIMER1_CTC_ICR1_MODE*/
#if TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_CTC_ICR1_MODE
	ICR1_REG = TIMER1_ICR1_VAL ;

#if TIMER1_ICR_EDGE == RISING_EDGE
	SET_BIT(TCCR1B_REG , TCCR1B_ICES1) ;
#elif TIMER1_ICR_EDGE == FALLING_EDGE
	CLR_BIT(TCCR1B_REG , TCCR1B_ICES1) ;
#else
#error "Wrong TIMER1_ICR_EDGE Config"
#endif

#else
	/*Do nothing*/
#endif

	/*Set OCR1A mode*/
#if TIMER1_OCR1A_MODE == TIMER_OC_DISCONNECTED
	CLR_BIT(TCCR1A_REG , TCCR1A_COM1A0) ;
	CLR_BIT(TCCR1A_REG , TCCR1A_COM1A1) ;
#elif TIMER1_OCR1A_MODE == TIMER_OC_TOGGEL
	SET_BIT(TCCR1A_REG , TCCR1A_COM1A0) ;
	CLR_BIT(TCCR1A_REG , TCCR1A_COM1A1) ;
#elif TIMER1_OCR1A_MODE == TIMER_OC_LOW
	CLR_BIT(TCCR1A_REG , TCCR1A_COM1A0) ;
	SET_BIT(TCCR1A_REG , TCCR1A_COM1A1) ;
#elif TIMER1_OCR1A_MODE == TIMER_OC_HIGH
	SET_BIT(TCCR1A_REG , TCCR1A_COM1A0) ;
	SET_BIT(TCCR1A_REG , TCCR1A_COM1A1) ;
#else
#error "Wrong TIMER1_OCR1A_MODE Config"
#endif

	/*Set OCR1B mode*/
#if TIMER1_OCR1B_MODE == TIMER_OC_DISCONNECTED
	CLR_BIT(TCCR1A_REG , TCCR1A_COM1B0) ;
	CLR_BIT(TCCR1A_REG , TCCR1A_COM1B1) ;
#elif TIMER1_OCR1B_MODE == TIMER_OC_TOGGEL
	SET_BIT(TCCR1A_REG , TCCR1A_COM1B0) ;
	CLR_BIT(TCCR1A_REG , TCCR1A_COM1B1) ;
#elif TIMER1_OCR1B_MODE == TIMER_OC_LOW
	CLR_BIT(TCCR1A_REG , TCCR1A_COM1B0) ;
	SET_BIT(TCCR1A_REG , TCCR1A_COM1B1) ;
#elif TIMER1_OCR1B_MODE == TIMER_OC_HIGH
	SET_BIT(TCCR1A_REG , TCCR1A_COM1B0) ;
	SET_BIT(TCCR1A_REG , TCCR1A_COM1B1) ;
#else
#error "Wrong TIMER1_OCR1B_MODE Config"
#endif

	/*Timer1 CTC Interrupt Enable*/
#if TIMER1_CTCA_INTERRUPT == DISABLE
	CLR_BIT(TIMSK_REG , TIMSK_OCIE1A) ;
#elif TIMER1_CTCA_INTERRUPT == ENABLE
	SET_BIT(TIMSK_REG , TIMSK_OCIE1A) ;
#else
#error "Wrong TIMER1_CTCA_INTERRUPT Config"
#endif

#if TIMER1_CTCB_INTERRUPT == DISABLE
	CLR_BIT(TIMSK_REG , TIMSK_OCIE1B) ;
#elif TIMER1_CTCB_INTERRUPT == ENABLE
	SET_BIT(TIMSK_REG , TIMSK_OCIE1B) ;
#else
#error "Wrong TIMER1_CTCB_INTERRUPT Config"
#endif

#elif ((TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_OCR1A_MODE) || (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_ICR1_MODE))

	/*Set Waveform generation mode as PWM modes */
#if TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_OCR1A_MODE
	SET_BIT(TCCR1A_REG,TCCR1A_WGM10);
	SET_BIT(TCCR1A_REG,TCCR1A_WGM11);
	SET_BIT(TCCR1B_REG,TCCR1B_WGM12);
	SET_BIT(TCCR1B_REG,TCCR1B_WGM13);
#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_ICR1_MODE
	CLR_BIT(TCCR1A_REG,TCCR1A_WGM10);
	SET_BIT(TCCR1A_REG,TCCR1A_WGM11);
	SET_BIT(TCCR1B_REG,TCCR1B_WGM12);
	SET_BIT(TCCR1B_REG,TCCR1B_WGM13);

#else
#error "Wrong TIMER1_WAVEFORM_GENERATION_MODE Config"
#endif

	/*Set the require CTC Values*/
	OCR1A_REG = TIMER1_CTCA_VAL ;
	OCR1B_REG = TIMER1_CTCB_VAL ;


	/*Set ICR1*/
#if TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_ICR1_MODE
	ICR1_REG = TIMER1_ICR1_VAL ;

#endif

	/*Set OCR1A mode*/
#if TIMER1_OCR1A_MODE == TIMER_OC_DISCONNECTED
	CLR_BIT(TCCR1A_REG , TCCR1A_COM1A0) ;
	CLR_BIT(TCCR1A_REG , TCCR1A_COM1A1) ;
#elif TIMER1_OCR1A_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
	CLR_BIT(TCCR1A_REG , TCCR1A_COM1A0) ;
	SET_BIT(TCCR1A_REG , TCCR1A_COM1A1) ;
#elif TIMER1_OCR1A_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
	SET_BIT(TCCR1A_REG , TCCR1A_COM1A0) ;
	SET_BIT(TCCR1A_REG , TCCR1A_COM1A1) ;
#else
#error "Wrong TIMER1_OCR1A_MODE Config"
#endif

	/*Set OCR1B mode*/
#if TIMER1_OCR1B_MODE == TIMER_OC_DISCONNECTED
	CLR_BIT(TCCR1A_REG , TCCR1A_COM1B0) ;
	CLR_BIT(TCCR1A_REG , TCCR1A_COM1B1) ;
#elif TIMER1_OCR1B_MODE == TIMER_CLR_ON_CTC_COUNTING_UP_SET_ON_CTC_COUNTING_DWON
	CLR_BIT(TCCR1A_REG , TCCR1A_COM1B0) ;
	SET_BIT(TCCR1A_REG , TCCR1A_COM1B1) ;
#elif TIMER1_OCR1B_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
	SET_BIT(TCCR1A_REG , TCCR1A_COM1B0) ;
	SET_BIT(TCCR1A_REG , TCCR1A_COM1B1) ;
#else
#error "Wrong TIMER1_OCR1B_MODE Config"
#endif

	/*Timer1 PWM Interrupt Enable*/
#if TIMER1_OVERFLOW_INTERRUPT == DISABLE
	CLR_BIT(TIMSK_REG , TIMSK_TOIE1) ;
#elif TIMER1_OVERFLOW_INTERRUPT == ENABLE
	SET_BIT(TIMSK_REG , TIMSK_TOIE1) ;
#else
#error "Wrong TIMER1_OVERFLOW_INTERRUPT Config"
#endif

#if TIMER1_CTCA_INTERRUPT == DISABLE
	CLR_BIT(TIMSK_REG , TIMSK_OCIE1A) ;
#elif TIMER1_CTCA_INTERRUPT == ENABLE
	SET_BIT(TIMSK_REG , TIMSK_OCIE1A) ;
#else
#error "Wrong TIMER1_CTCA_INTERRUPT Config"
#endif

#if TIMER1_CTCB_INTERRUPT == DISABLE
	CLR_BIT(TIMSK_REG , TIMSK_OCIE1B) ;
#elif TIMER1_CTCB_INTERRUPT == ENABLE
	SET_BIT(TIMSK_REG , TIMSK_OCIE1B) ;
#else
#error "Wrong TIMER1_CTCB_INTERRUPT Config"
#endif

#if TIMER1_ICR_INTERRUPT == DISABLE
	CLR_BIT(TIMSK_REG , TIMSK_TICIE1) ;
#elif TIMER1_ICR_INTERRUPT == ENABLE
	SET_BIT(TIMSK_REG , TIMSK_TICIE1) ;
#else
#error "Wrong TIMER1_ICR1_INTERRUPT Config"
#endif


#else
#error "Wrong TIMER1_WAVEFORM_GENERATION_MODE Config"
#endif

	/*Set the Required Pre_scaler*/
	TCCR1B_REG &=TIMER_PRESCALER_MASK;
	TCCR1B_REG |=TIMER1_PRESCALER;

}
void TIMER1_voidSetPreloadValue (u16 Copy_u16PreloadValue)
{
	TCNT1_REG = Copy_u16PreloadValue;
}

void TIMER1_voidSetICR1 (u16 Copy_u16ICR1)
{
	ICR1_REG = Copy_u16ICR1;
}


void TIMER1_voidSetValueCompMatchChannel_A (u16 Copy_u16CTCA)
{
	OCR1A_REG = Copy_u16CTCA;
}

void TIMER1_voidSetValueCompMatchChannel_B (u16 Copy_u16CTCB)
{
	OCR1B_REG = Copy_u16CTCB;
}



u16 TIMER1_u16GetTimerCounterValue (void)
{
	return TCNT1_REG ;
}



u8 TIMER1_u8SetCallBackOverFlowMode(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if (Copy_pvCallBackFunc != NULL)
	{
		Timer1_pvCallBackFuncOverFlowMode = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;

	}

	return Local_u8ErrorState;
}

/*TIMER1 Normal Mode ISR*/
void __vector_9 (void) __attribute__((signal));
void __vector_9 (void)
{
	if (Timer1_pvCallBackFuncOverFlowMode != NULL)
	{
		Timer1_pvCallBackFuncOverFlowMode();
	}
}




u8 TIMER1_u8SetCallBackCTCModeChannel_A (void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if (Copy_pvCallBackFunc != NULL)
	{
		Timer1_pvCallBackFuncCTCModeChannel_A = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;

	}

	return Local_u8ErrorState;
}


/*TIMER1 CTC Channel A Mode ISR*/
void __vector_7 (void) __attribute__((signal));
void __vector_7 (void)
{
	if (Timer1_pvCallBackFuncCTCModeChannel_A != NULL)
	{
		Timer1_pvCallBackFuncCTCModeChannel_A();
	}
}


u8 TIMER1_u8SetCallBackCTCModeChannel_B(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if (Copy_pvCallBackFunc != NULL)
	{
		Timer1_pvCallBackFuncCTCModeChannel_B = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;

	}

	return Local_u8ErrorState;
}


/*TIMER1 CTC Channel B Mode ISR*/
void __vector_8 (void) __attribute__((signal));
void __vector_8 (void)
{
	if (Timer1_pvCallBackFuncCTCModeChannel_B != NULL)
	{
		Timer1_pvCallBackFuncCTCModeChannel_B();
	}
}


/**************************************************************************/
/***************************    ICU   *************************************/
/**************************************************************************/


/*Init ICU Function*/
void ICU_voidInit(void)
{
	/*Set Trigger Source */
#if (TIMER_ICP_INIT_STATE == TIMER_ICP_RAISING_EDGE)
	SET_BIT(TCCR1B_REG ,TCCR1B_ICES1);

#elif (TIMER_ICP_INIT_STATE ==TIMER_ICP_FALLING_EDGE)
	CLR_BIT(TCCR1B_REG ,TCCR1B_ICES1);
#endif

	/* Enable Interrupt of ICU (PIE) */
	SET_BIT(TIMSK_REG,TIMSK_TICIE1);
}

/*Change the Trigger Sense in Runtime */
u8 ICU_u8SetTriggerEdge(u8 Copy_u8Edge)
{
	u8 Local_u8ErrorStatud = STD_TYPES_OK;
	if (Copy_u8Edge == ICU_RISING_EDGE)
	{
		SET_BIT(TCCR1B_REG , TCCR1B_ICES1);
	}

	else if (Copy_u8Edge == ICU_FALLING_EDGE)
	{
		CLR_BIT(TCCR1B_REG , TCCR1B_ICES1);
	}

	else
	{
		Local_u8ErrorStatud = STD_TYPES_NOK;
	}

	return Local_u8ErrorStatud;
}

void ICU_voidEnableInterrupt(void)
{
	SET_BIT(TIMSK_REG , TIMSK_TICIE1);
}
void ICU_voidDisableInterrupt(void)
{
	CLR_BIT(TIMSK_REG , TIMSK_TICIE1);

}

u16 ICU_u16GetReadingInputCaptureUnit(void)
{
	return ICR1_REG;
}


u8 ICU_u8SetCallBackRegisterICU(void(*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if (Copy_pvCallBackFunc != NULL)
	{
		ICU_pvCallBackFunc = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

/*Timer/Counter1 Capture Event Mode ISR*/
void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if (ICU_pvCallBackFunc != NULL)
	{
		ICU_pvCallBackFunc();
	}
}

















