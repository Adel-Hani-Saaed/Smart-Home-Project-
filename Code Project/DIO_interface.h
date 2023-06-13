/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: DIO			  *******************/
/*************** Date: 28/1/2023 	  *******************/
/*************** Version: 2.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

typedef enum                 //it should be before functions prototypes
 {
	DIO_NOK,
	DIO_OK
 }DIO_ErrorStatus;


/********************************************************/
/******************* Public Macros **********************/
/********************************************************/
//  Port Macros
#define DIO_PORTA    0
#define DIO_PORTB    1
#define DIO_PORTC    2
#define DIO_PORTD    3

//  Pin Macros
#define DIO_PIN0     0
#define DIO_PIN1     1
#define DIO_PIN2     2
#define DIO_PIN3     3
#define DIO_PIN4     4
#define DIO_PIN5     5
#define DIO_PIN6     6
#define DIO_PIN7     7

// DIO direction
#define DIO_INPUT    0
#define DIO_OUTPUT   1

//  DIO status
#define DIO_HIGH     1
#define DIO_LOW      0

//DIO Port Direction
#define DIO_PORT_OUTPUT 0xff
#define DIO_PORT_INPUT  0x00     

//DIO Port Status
#define DIO_PORT_HIGH  0xff
#define DIO_PORT_LOW   0x00

//Pull UP in Register SFIOR_REG if Write 1 is Disable Pull_up 
//even if the DDRn and PORTx Registers are configured to enable
#define PUD   2


/*****************************************************************/
/******************** Public Function for Pin ********************/
/*****************************************************************/

/* Description : this Function is to set pin direction
 * \input :  Copy_u8Port    		 , Range : DIO_PORTA ~ DIO_PORTD
 *           Copy_u8Pin     		 , Range : DIO_PIN   ~ DIO_PIN7
 *           Copy_u8Direction        , Range : DIO_INPUT , DIO_OUTPUT
 * Return  : EnumStatus
 */
DIO_ErrorStatus	DIO_enumSetPinDirection(u8 Copy_u8Port ,u8 Copy_u8Pin , u8 Copy_u8Direction );


/* Description : this Function is to set pin Value
 * \input :  Copy_u8Port    		 , Range : DIO_PORTA ~ DIO_PORTD
 *           Copy_u8Pin     		 , Range : DIO_PIN   ~ DIO_PIN7
 *           Copy_u8Direction        , Range : DIO_HIGH , DIO_LOW
 * Return  : EnumStatus
 */
DIO_ErrorStatus DIO_enumSetPinValue(u8  Copy_u8Port ,u8 Copy_u8Pin , u8 Copy_u8Value);


/* Description : this Function is to Get pin Value
 * \input :  Copy_u8Port    		 , Range : DIO_PORTA ~ DIO_PORTD
 *           Copy_u8Pin     		 , Range : DIO_PIN   ~ DIO_PIN7
 * Return  : EnumStatus and receive Pin Value in pointer
 */
DIO_ErrorStatus DIO_enumGetPinValue(u8  Copy_u8Port ,u8 Copy_u8Pin , u8* Copy_pu8Value);


/* Description : This Function Toggle the Value of the Pin
 * \input :  Copy_u8Port    		 , Range : DIO_PORTA ~ DIO_PORTD
 *           Copy_u8Pin     		 , Range : DIO_PIN   ~ DIO_PIN7
 * Return  : EnumStatus
 */
DIO_ErrorStatus DIO_enumTogglePinValue( u8 Copy_u8Port, u8 Copy_u8Pin );



/*****************************************************************/
/******************** Public Function for Port *******************/
/*****************************************************************/

/* Description : this Function is to set Port direction
 * \input :  Copy_u8Port    		 , Range : DIO_PORTA ~ DIO_PORTD
 *           Copy_u8Direction        , Range : DIO_INPUT , DIO_OUTPUT
 * Return  : EnumStatus
 */
DIO_ErrorStatus DIO_enumSetPortDirection(u8 Copy_u8Port , u8 Copy_u8Direction);


/* Description : this Function is to set Port Value
 * \input :  Copy_u8Port    		 , Range : DIO_PORTA ~ DIO_PORTD
 *           Copy_u8Direction        , Range : DIO_HIGH , DIO_LOW
 * Return  : EnumStatus
 */
DIO_ErrorStatus DIO_enumSetPortValue(u8  Copy_u8Port , u8 Copy_u8Value);


/* Description : This Function Toggle Port the Value
 * \input :  Copy_u8Port    		 , Range : DIO_PORTA ~ DIO_PORTD
 * Return  : EnumStatus
 */
DIO_ErrorStatus DIO_enumTogglePortValue( u8 Copy_u8Port );



/*****************************************************************/
/******************** Public Function for Nibble *****************/
/******************** 		 high   low			 *****************/
/********************  		 xxxx   xxxx 		 *****************/
/*****************************************************************/

/* Description : this Function is to set HighNibble direction
 * \input :  Copy_u8Port    		 , Range : DIO_PORTA ~ DIO_PORTD
 *           Copy_u8Direction        , Range : DIO_INPUT , DIO_OUTPUT
 * Return  : EnumStatus
 */
DIO_ErrorStatus DIO_enumSetHighNibbleDirection(u8 Copy_u8Port , u8 Copy_u8Direction);


/* Description : this Function is to set HighNibble Value
 * \input :  Copy_u8Port    		 , Range : DIO_PORTA ~ DIO_PORTD
 *           Copy_u8Direction        , Range : DIO_HIGH , DIO_LOW
 * Return  : EnumStatus
 */
DIO_ErrorStatus DIO_enumSetHighNibbleValue(u8  Copy_u8Port  , u8 Copy_u8Value);


/* Description : this Function is to set LowNibble direction
 * \input :  Copy_u8Port    		 , Range : DIO_PORTA ~ DIO_PORTD
 *           Copy_u8Direction        , Range : DIO_INPUT , DIO_OUTPUT
 * Return  : EnumStatus
 */
DIO_ErrorStatus DIO_enumSetLowNibbleDirection(u8 Copy_u8Port , u8 Copy_u8Direction);


/* Description : this Function is to set LowNibble Value
 * \input :  Copy_u8Port    		 , Range : DIO_PORTA ~ DIO_PORTD
 *           Copy_u8Direction        , Range : DIO_HIGH , DIO_LOW
 * Return  : EnumStatus
 */
DIO_ErrorStatus DIO_enumSetLowNibbleValue(u8  Copy_u8Port , u8 Copy_u8Value);

#endif 
