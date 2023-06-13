/********************************************************/
/********************************************************/
/*************** Author: Adel_Hani	  *******************/
/*************** Layer: APP 		  *******************/
/*************** SWC: SmartHome		  *******************/
/*************** Date: 3/5/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/

/*Lib Layer*/
#include "BIT_Math.h"
#include "STD_TYPES.h"
#include "Mapping_interface.h"

#define F_CPU 8000000UL
#include <util/delay.h>

/*Macl*/
#include "DIO_interface.h"
#include "Timer1_interface.h"
#include "USART_interface.h"

/*Hal*/
#include "Led_interface.h"
#include "Buzzer_interface.h"
#include "Servo_interface.h"

/*Application*/
#include "APP_config.h"
#include "App_interface.h"


LED_T LED_Rooms = 	 {LED_PORTD, LED_PIN7 , LED_SOURCE};


void App_voidInit(void)
{
	u8 Local_u8CounterLoop ;	// For Counter the Loop used Check 10 User & Pass
	u8 Local_u8ReturnCheck;		// Var to stored return func Check User & Pass
	u8 Local_u8FlageCheck = 0;	// Flage Correct User & Pass
	u8 Local_u8FlageTrails = 0; // Flage Trails You Have 3 Trails

	/*Array 10_byte of Struct */
	AccountUsers_t AccountsDB[10] = {
			{"Adel"  , "8634" }  ,  {"Ahd"   , "4567"  } ,
			{"Ahmed" , "3215" }  ,  {"Mohed" , "9875"  } ,
			{"Salah" , "98765"}  ,  {"Doaa"  , "86321" } ,
			{"Ibra"  , "7895" }  ,  {"Aliaa" , "64581" } ,
			{"Randa" , "3214" }  ,  {"Naga"  , "32465" } ,  };


	/*Pointer of Struct (AccountUsers_t)  to Pointed the First Element of DataBase(AccountsDB) and can access the elements the DataBase
	  By (PS_DataBase->UserNameSaved) and (PS_DataBase->PasswordSaved) */
	AccountUsers_t *PS_DataBase = AccountsDB;

	/*Arrays to Store User & Password*/
	u8 UserName[10];
	u8 Password[10];

	/*Init the MCAL Layers*/
	USART_voidInit();
	TIMER1_voidInit();


	/*Init HAL Layers*/
	BUZZER_T AlarmBUZZ = {BUZZ_PORTD , BUZZ_PIN6 , BUZZ_SOURCE};
	LED_voidPinInit(&LED_Rooms);
	BUZZ_voidInit(&AlarmBUZZ);
	SERVO_voidInit(SERVO_OC1B_PIN4);
	SERVO_voidSetDegreeRotate(SERVO_OC1B_PIN4, 0);

	/*For DC Motor*/
	DIO_enumSetPinDirection(DIO_PORTD, DIO_PIN2, DIO_OUTPUT);

	/*Welcome massage*/
	USART_u8SendStringSynch("Welcome to Smart Home ");
	_delay_ms(200);

	while(1)
	{

		/*Enter For User Name*/
		USART_u8SendStringSynch("Enter User Name ");
		USART_voidReceiveString(UserName);

		/*Enter the PassWord*/
		USART_u8SendStringSynch("Enter Password ");
		USART_voidReceiveString(Password);


		for (Local_u8CounterLoop = 0 ; Local_u8CounterLoop < 10 ; Local_u8CounterLoop++)
		{
			/*Func return correct or wrong pass & user*/
			Local_u8ReturnCheck = APP_u8Check_Pass(PS_DataBase[Local_u8CounterLoop].UserNameSaved, UserName, APP_u8GetlengthArr(PS_DataBase[Local_u8CounterLoop].UserNameSaved), PS_DataBase[Local_u8CounterLoop].PasswordSaved, Password, APP_u8GetlengthArr(PS_DataBase[Local_u8CounterLoop].PasswordSaved) );

			/*if Valid */
			if (Local_u8ReturnCheck == STD_TYPES_OK)
			{
				Local_u8FlageCheck = 1;
				break;
			}
		}

		/*Correct Pass & User*/
		if (Local_u8FlageCheck == 1)
		{
			USART_u8SendStringSynch("Thing You :)");
			Local_u8FlageTrails = 0 ;
			/*Open door*/
			SERVO_voidSetDegreeRotate(SERVO_OC1B_PIN4, 90);
			/*Func Smart control in Home*/
			APP_voidSmartHomeControl();
			/*break While loop*/
			break;
		}

		else
		{
			Local_u8FlageCheck = 0;
			Local_u8FlageTrails++ ;
		}

		/*Wrong pass or user 3 times*/
		if (Local_u8FlageTrails == 3)
		{
			USART_u8SendStringSynch("Door is Locked,,");
			USART_u8SendStringSynch("Calling Police (:");
			SERVO_voidSetDegreeRotate(SERVO_OC1B_PIN4, 0);
			BUZZ_voidTurnOn(&AlarmBUZZ);
			_delay_ms(5000);
			BUZZ_voidTurnOff(&AlarmBUZZ);
			break; //break While loop
		}
		else
		{
			USART_u8SendStringSynch("Try Again..");
		}
	}
}

u8 APP_u8Check_Pass( u8 *Copy_u8SaveUser , u8 *Copy_u8EnterUser , u8  Copy_u8SizeUser , u8 *Copy_u8SavePassWord , u8 *Copy_u8EnterPassWord , u8  Copy_u8SizePassWord )
{
	u8 Local_Return = STD_TYPES_OK;
	u8 Local_counter_1=0 ;
	u8 Local_counter_2=0 ;


	/*For Check User Correct or Wrong*/
	for (Local_counter_1 = 0 ; Local_counter_1 < Copy_u8SizeUser  ; Local_counter_1++)
	{
		if (Copy_u8SaveUser[Local_counter_1] != Copy_u8EnterUser[Local_counter_1])
		{
			Local_Return = STD_TYPES_NOK;
			break;
		}
		else{

		}
	}

	/*For Check PassWord Correct or Wrong*/
	for (Local_counter_2 = 0 ; Local_counter_2 < Copy_u8SizePassWord  ; Local_counter_2++)
	{
		if (Copy_u8SavePassWord[Local_counter_2] != Copy_u8EnterPassWord[Local_counter_2])
		{
			Local_Return = STD_TYPES_NOK;
			break;
		}
	}

	return Local_Return;
}

u8 APP_u8GetlengthArr(u8 *Copy_u8Array)
{
	u8 Lcoal_u8Counter=0;
	u8 Local_u8LengthArr =0;
	while(1)
	{
		Local_u8LengthArr++;
		if( Copy_u8Array[Lcoal_u8Counter] == '\0')
		{
			break;
		}
		Lcoal_u8Counter++;
	}
	return Local_u8LengthArr;
}

void APP_voidSmartHomeControl(void)
{
	u8 Local_u8DataControl ;    // Var to stored the data send by bluotooth

	USART_u8SendStringSynch("Please, Choose Operation .");

	while(1)
	{
		Local_u8DataControl = USART_voidGetChar();

		if (Local_u8DataControl == LED_TURN_ON)
		{
			LED_voidPinTurnOn(&LED_Rooms);
			_delay_ms(500);
			USART_u8SendStringSynch("Light System Turn On");
		}

		else if (Local_u8DataControl == LED_TURN_OFF)
		{
			LED_voidPinTurnOff(&LED_Rooms);
			_delay_ms(500);
			USART_u8SendStringSynch("Light System Turn Off");
		}

		else if (Local_u8DataControl == DOOR_OPEN)
		{
			SERVO_voidSetDegreeRotate(SERVO_OC1B_PIN4, 90);
			_delay_ms(500);
			USART_u8SendStringSynch("Door is open");
		}

		else if (Local_u8DataControl == DOOR_CLOSED)
		{
			SERVO_voidSetDegreeRotate(SERVO_OC1B_PIN4, 0);
			_delay_ms(500);
			USART_u8SendStringSynch("Door is Closed");
		}

		else if (Local_u8DataControl == DC_MOTOR_ON)
		{
			DIO_enumSetPinValue(DIO_PORTD, DIO_PIN2, DIO_HIGH);
			USART_u8SendStringSynch("Fan Is ON");
		}

		else if (Local_u8DataControl == DC_MOTOR_OFF)
		{
			DIO_enumSetPinValue(DIO_PORTD, DIO_PIN2, DIO_LOW);
			USART_u8SendStringSynch("Fan Is OFF");
		}

		else if (Local_u8DataControl == EXIT_APP)
		{
			USART_u8SendStringSynch("System Exit Things :)");
			break;
		}
	}
}
