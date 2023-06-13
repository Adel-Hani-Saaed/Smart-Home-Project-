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
#include "App_interface.h"

int main (void)
{
	/*Call the Func System*/
	App_voidInit();

	return 0;
}


