/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: HAL			  *******************/
/*************** SWC: Buzzer		  *******************/
/*************** Date: 11/2/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/


#include "BIT_Math.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "Buzzer_interface.h"



void BUZZ_voidInit(BUZZER_T *BUZZ_Configuration)
{
	DIO_enumSetPinDirection(BUZZ_Configuration->Port,BUZZ_Configuration->Pin,BUZZ_PIN_OUTPUT);
}

void BUZZ_voidTurnOn(BUZZER_T *BUZZ_Configuration)
{
	if (BUZZ_Configuration->Conn_Type == BUZZ_SOURCE)
	{
		DIO_enumSetPinValue(BUZZ_Configuration->Port,BUZZ_Configuration->Pin,BUZZ_PIN_HIGH);
	}
	else if(BUZZ_Configuration->Conn_Type == BUZZ_SINK)
	{
		DIO_enumSetPinValue(BUZZ_Configuration->Port,BUZZ_Configuration->Pin,BUZZ_PIN_LOW);
	}

}

void BUZZ_voidTurnOff(BUZZER_T *BUZZ_Configuration)
{
	if (BUZZ_Configuration->Conn_Type == BUZZ_SOURCE)
	{
		DIO_enumSetPinValue(BUZZ_Configuration->Port,BUZZ_Configuration->Pin,BUZZ_PIN_LOW);
	}
	else if(BUZZ_Configuration->Conn_Type == BUZZ_SINK)
	{
		DIO_enumSetPinValue(BUZZ_Configuration->Port,BUZZ_Configuration->Pin,BUZZ_PIN_HIGH);
	}

}


void BUZZ_voidToggle(BUZZER_T *BUZZ_Configuration)
{
	DIO_enumTogglePinValue(BUZZ_Configuration->Port,BUZZ_Configuration->Pin);
}
