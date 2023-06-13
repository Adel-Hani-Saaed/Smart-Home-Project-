/********************************************************/
/********************************************************/
/*************** Author: Adel_Hani	  *******************/
/*************** Layer: HAL			  *******************/
/*************** SWC: Servo			  *******************/
/*************** Date: 31/3/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/


#include "BIT_Math.h"
#include "STD_TYPES.h"
#include "Mapping_interface.h"

#include "Servo_interface.h"

#include "DIO_interface.h"
#include "Timer1_interface.h"


void SERVO_voidInit(u8 Copy_u8IDPin)
{
	TIMER1_voidInit();

	if (Copy_u8IDPin == SERVO_OC1B_PIN4)
	{
		DIO_enumSetPinDirection(SERVO_PORTD, SERVO_OC1B_PIN4, SERVO_OUTPUT);
	}

	else if (Copy_u8IDPin == SERVO_OC1A_PIN5)
	{
		DIO_enumSetPinDirection(SERVO_PORTD, SERVO_OC1A_PIN5, SERVO_OUTPUT);
	}
}



void SERVO_voidSetDegreeRotate(u8 Copy_u8IDPin ,u8 Copy_u8AngleValue)
{

	if (Copy_u8IDPin == SERVO_OC1A_PIN5)
	{
		TIMER1_voidSetValueCompMatchChannel_A(MAPPING_s32GetOutput(MIN_ANGLE, MAX_ANGLE, MIN_TIME_ON, MAX_TIME_ON, Copy_u8AngleValue));
	}

	else if (Copy_u8IDPin == SERVO_OC1B_PIN4)
	{
		TIMER1_voidSetValueCompMatchChannel_B(MAPPING_s32GetOutput(MIN_ANGLE, MAX_ANGLE, MIN_TIME_ON, MAX_TIME_ON, Copy_u8AngleValue));
	}

}
