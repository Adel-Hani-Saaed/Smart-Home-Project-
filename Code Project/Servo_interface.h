/********************************************************/
/********************************************************/
/*************** Author: Adel_Hani	  *******************/
/*************** Layer: HAL			  *******************/
/*************** SWC: Servo			  *******************/
/*************** Date: 31/3/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

//  Port Macros
#define SERVO_PORTA    0
#define SERVO_PORTB    1
#define SERVO_PORTC    2
#define SERVO_PORTD    3


/*Pin Id*/
#define SERVO_OC1B_PIN4	   4
#define SERVO_OC1A_PIN5	   5

// DIO direction
#define SERVO_INPUT    	   0
#define SERVO_OUTPUT       1


#define MAX_ANGLE	       180
#define MIN_ANGLE 	   	   0

#define MAX_TIME_ON		   2600
#define MIN_TIME_ON		   650


void SERVO_voidInit(u8 Copy_u8IDPin);


void SERVO_voidSetDegreeRotate(u8 Copy_u8IDPin ,u8 Copy_u8AngleValue);


#endif /* SERVO_INTERFACE_H_ */
