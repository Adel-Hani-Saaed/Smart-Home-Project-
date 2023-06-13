/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: HAL			  *******************/
/*************** SWC: Buzzer		  *******************/
/*************** Date: 11/2/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_


/********************************************************/
/******************* Public Macros **********************/
/********************************************************/

//  BUZZ Connection Type
#define BUZZ_SOURCE   1
#define BUZZ_SINK	  0

//  BUZZ Port Macros
#define BUZZ_PORTA    0
#define BUZZ_PORTB    1
#define BUZZ_PORTC    2
#define BUZZ_PORTD    3

//  BUZZ Pin Macros
#define BUZZ_PIN0     0
#define BUZZ_PIN1     1
#define BUZZ_PIN2     2
#define BUZZ_PIN3     3
#define BUZZ_PIN4     4
#define BUZZ_PIN5     5
#define BUZZ_PIN6     6
#define BUZZ_PIN7     7

//  BUZZ direction
#define BUZZ_PIN_OUTPUT   1
#define BUZZ_PIN_INPUT    0

//  BUZZ State
#define BUZZ_PIN_HIGH   1
#define BUZZ_PIN_LOW	0


/* Structure for Pin BUZZ must Passing object as pointer to function
 * 	the Members is 1- Port.
 * 				   2- Pin.
 * 	 			   3- Connection type (Source or Sink).
 * */
typedef struct
{
	u8 Port         ;
	u8 Pin          ;
	u8 Conn_Type	;
}BUZZER_T;

/* Description : this Function is to set Pin_Buzzer direction
 * \input :  BUZZ_T BUZZ_Configuration 	 , Range : BUZZ_Configuration-> BUZZ_PORTA ~ BUZZ_PORTD
 *             							 , Range : BUZZ_Configuration-> BUZZ_PIN   ~ BUZZ_PIN7
 *           		 		        	 , Range : BUZZ_Configuration-> BUZZ_SOURCE ~ BUZZ_SINK
 * Return  : nothing
 */
void BUZZ_voidInit(BUZZER_T *BUZZ_Configuration);


/* Description : this Function is to Turn on Pin_Buzzer
 * \input :  BUZZ_T BUZZ_Configuration , Range : BUZZ_Configuration-> BUZZ_PORTA ~ BUZZ_PORTD
 *             						 , Range : BUZZ_Configuration-> BUZZ_PIN   ~ BUZZ_PIN7
 *           		 		         , Range : BUZZ_Configuration-> BUZZ_SOURCE ~ BUZZ_SINK
 * Return  : nothing
 */
void BUZZ_voidTurnOn(BUZZER_T *BUZZ_Configuration);


/* Description : this Function is to Turn off Pin_Buzzer
 * \input :  BUZZ_T BUZZ_Configuration , Range : BUZZ_Configuration-> BUZZ_PORTA ~ BUZZ_PORTD
 *             						 , Range : BUZZ_Configuration-> BUZZ_PIN   ~ BUZZ_PIN7
 *           		 		         , Range : BUZZ_Configuration-> BUZZ_SOURCE ~ BUZZ_SINK
 * Return  : nothing
 */
void BUZZ_voidTurnOff(BUZZER_T *BUZZ_Configuration);


/* Description : this Function is to Toggle Pin_Buzzer
 * \input :  BUZZ_T BUZZ_Configuration , Range : BUZZ_Configuration-> BUZZ_PORTA ~ BUZZ_PORTD
 *             						 , Range : BUZZ_Configuration-> BUZZ_PIN   ~ BUZZ_PIN7
 * Return  : nothing
 */
void BUZZ_voidToggle(BUZZER_T *BUZZ_Configuration);

#endif /* BUZZER_INTERFACE_H_ */
