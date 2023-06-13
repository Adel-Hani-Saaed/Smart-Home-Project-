/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: HAL			  *******************/
/*************** SWC: LED			  *******************/
/*************** Date: 2/2/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/


#include "BIT_Math.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "Led_interface.h"



/*****************************************************************/
/******************* Public Function for Pin LED *****************/
/*****************************************************************/

void LED_voidPinInit( LED_T *LED_Configuration )
{
	DIO_enumSetPinDirection(LED_Configuration->Port,LED_Configuration->Pin,LED_OUTPUT);
}

void LED_voidPinTurnOn( LED_T *LED_Configuration )
{
	if (LED_Configuration->Conn_T == LED_SOURCE)
	{
		DIO_enumSetPinValue(LED_Configuration->Port,LED_Configuration->Pin,LED_HIGH);
	}
	else if (LED_Configuration->Conn_T == LED_SINK)
	{
		DIO_enumSetPinValue(LED_Configuration->Port,LED_Configuration->Pin,LED_LOW);
	}
}


void LED_voidPinTurnOff( LED_T *LED_Configuration )
{
	if (LED_Configuration->Conn_T == LED_SOURCE)
	{
		DIO_enumSetPinValue(LED_Configuration->Port,LED_Configuration->Pin,LED_LOW);
	}
	else if (LED_Configuration->Conn_T == LED_SINK)
	{
		DIO_enumSetPinValue(LED_Configuration->Port,LED_Configuration->Pin,LED_HIGH);
	}

}



void LED_voidPinToggle( LED_T *LED_Configuration )
{
	DIO_enumTogglePinValue(LED_Configuration->Port,LED_Configuration->Pin);
}





/*****************************************************************/
/******************* Public Function for Port LED ****************/
/*****************************************************************/


void LED_voidPortInit( LED_Port_T *LED_Configuration )
{
	DIO_enumSetPortDirection(LED_Configuration->Port,LED_PORT_OUTPUT);
}

void LED_voidPortTurnOn( LED_Port_T *LED_Configuration )
{
	if (LED_Configuration->Conn_T == LED_SOURCE)
	{
		DIO_enumSetPortValue(LED_Configuration->Port,LED_PORT_HIGH);
	}
	else if (LED_Configuration->Conn_T == LED_SINK)
	{
		DIO_enumSetPortValue(LED_Configuration->Port,LED_PORT_LOW);
	}
}

void LED_voidPortTurnOff( LED_Port_T *LED_Configuration )
{

	if (LED_Configuration->Conn_T == LED_SOURCE)
	{
		DIO_enumSetPortValue(LED_Configuration->Port,LED_PORT_LOW);
	}
	else if (LED_Configuration->Conn_T == LED_SINK)
	{
		DIO_enumSetPortValue(LED_Configuration->Port,LED_PORT_HIGH);
	}
}

void LED_voidPortToggle( LED_Port_T *LED_Configuration )
{
	DIO_enumTogglePortValue(LED_Configuration->Port);
}


void LED_voidPortSetValue( LED_Port_T *LED_Configuration , u8 Copy_u8Value)
{
	if (LED_Configuration->Conn_T == LED_SOURCE)
	{
		DIO_enumSetPortValue(LED_Configuration->Port,Copy_u8Value);
	}
	else if (LED_Configuration->Conn_T == LED_SINK)
	{
		DIO_enumSetPortValue(LED_Configuration->Port,Copy_u8Value);
	}
}




