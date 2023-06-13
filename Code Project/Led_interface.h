/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: HAL			  *******************/
/*************** SWC: LED			  *******************/
/*************** Date: 2/2/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

/********************************************************/
/******************* Public Macros **********************/
/********************************************************/
//  LED Port Macros
#define LED_PORTA    0
#define LED_PORTB    1
#define LED_PORTC    2
#define LED_PORTD    3

//  LED Pin Macros
#define LED_PIN0     0
#define LED_PIN1     1
#define LED_PIN2     2
#define LED_PIN3     3
#define LED_PIN4     4
#define LED_PIN5     5
#define LED_PIN6     6
#define LED_PIN7     7

//  LED direction
#define LED_INPUT    0
#define LED_OUTPUT   1

//  LED Connection Type
#define LED_SOURCE   1
#define LED_SINK	 0

//  LED State
#define LED_HIGH   1
#define LED_LOW	   0


// Port LED Direction
#define LED_PORT_OUTPUT		 0xff
#define LED_PORT_INPUT 		 0x00

//  Port LED State
#define LED_PORT_HIGH   	 0xff
#define LED_PORT_LOW	     0x00

/* Structure for Pin LED must Passing object as pointer to function
 * 	the Members is 1- Port.
 * 				   2- Pin.
 * 	 			   3- Connection type (Source or Sink).
 * */
typedef struct{
	u8 Port         ;
	u8 Pin          ;
	u8 Conn_T		;
}LED_T;


/* Structure for Port LED must Passing object as pointer to function
 * 	the Members is 1- Port.
 * 	 			   2- Connection type (Source or Sink).
 * */
typedef struct{
	u8 Port         ;
	u8 Conn_T		;
}LED_Port_T;


/*****************************************************************/
/******************* Public Function for Pin LED *****************/
/*****************************************************************/

/* Description : this Function is to set Pin_LED direction
 * \input :  LED_T LED_Configuration , Range : LED_Configuration-> LED_PORTA ~ LED_PORTD
 *             						 , Range : LED_Configuration-> LED_PIN   ~ LED_PIN7
 *           		 		         , Range : LED_Configuration-> LED_OUTPUT
 * Return  : nothing
 */

void LED_voidPinInit( LED_T *LED_Configuration );


/* Description : this Function is to Turn on Pin_Led
 * \input :  LED_T LED_Configuration , Range : LED_Configuration-> LED_PORTA ~ LED_PORTD
 *             						 , Range : LED_Configuration-> LED_PIN   ~ LED_PIN7
 *           		 		         , Range : LED_Configuration-> LED_SOURCE ~ LED_SINK
 * Return  : nothing
 */
void LED_voidPinTurnOn( LED_T *LED_Configuration );



/* Description : this Function is to Turn off Pin_Led
 * \input :  LED_T LED_Configuration , Range : LED_Configuration-> LED_PORTA ~ LED_PORTD
 *             						 , Range : LED_Configuration-> LED_PIN   ~ LED_PIN7
 *           		 		         , Range : LED_Configuration-> LED_SOURCE ~ LED_SINK
 * Return  : nothing
 */
void LED_voidPinTurnOff( LED_T *LED_Configuration );



/* Description : this Function is to toggle Pin_Led
 * \input :  LED_T LED_Configuration , Range : LED_Configuration-> LED_PORTA ~ LED_PORTD
 *             						 , Range : LED_Configuration-> LED_PIN   ~ LED_PIN7
 * Return  : nothing
 */
void LED_voidPinToggle( LED_T *LED_Configuration );





/*****************************************************************/
/******************* Public Function for Port LED *****************/
/*****************************************************************/

/* Description : this Function is to set Pert_LED direction
 * \input :  LED_T LED_Configuration , Range : LED_Configuration-> LED_PORTA ~ LED_PORTD
 *           		 		         , Range : LED_Configuration-> LED_OUTPUT
 * Return  : nothing
 */
void LED_voidPortInit( LED_Port_T *LED_Configuration );



/* Description : this Function is to Turn On Pert_LED
 * \input :  LED_T LED_Configuration , Range : LED_Configuration-> LED_PORTA ~ LED_PORTD
 *           		 		         , Range : LED_Configuration-> LED_OUTPUT
 * Return  : nothing
 */
void LED_voidPortTurnOn( LED_Port_T *LED_Configuration );



/* Description : this Function is to Pert_LED Set value
 * \input :  LED_T LED_Configuration , Range : LED_Configuration-> LED_PORTA ~ LED_PORTD
 *           		 		         , Range : LED_Configuration-> LED_OUTPUT
 *
 *           Copy_u8Value			 , Range : 0 ~ 255
 * Return  : nothing
 */
void LED_voidPortSetValue( LED_Port_T *LED_Configuration , u8 Copy_u8Value);


/* Description : this Function is to Turn off Pert_LED
 * \input :  LED_T LED_Configuration , Range : LED_Configuration-> LED_PORTA ~ LED_PORTD
 *           		 		         , Range : LED_Configuration-> LED_OUTPUT
 * Return  : nothing
 */
void LED_voidPortTurnOff( LED_Port_T *LED_Configuration );



/* Description : this Function is to Toggle Port_LED
 * \input :  LED_T LED_Configuration , Range : LED_Configuration-> LED_PORTA ~ LED_PORTD
 *           		 		         , Range : LED_Configuration-> LED_OUTPUT
 * Return  : nothing
 */
void LED_voidPortToggle( LED_Port_T *LED_Configuration );


#endif /* LED_INTERFACE_H_ */
