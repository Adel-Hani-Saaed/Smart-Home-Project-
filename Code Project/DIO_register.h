/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: DIO			  *******************/
/*************** Date: 28/1/2023 	  *******************/
/*************** Version: 2.00		  *******************/
/********************************************************/
/********************************************************/

		/*Guard File*/
#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

/* Group Port A Registers */
#define 	PORTA_REG		*((volatile u8*)0X3B)
#define 	DDRA_REG		*((volatile u8*)0X3A)
#define 	PINA_REG		*((volatile u8*)0X39)

/* Group Port A Registers */
#define 	PORTB_REG		*((volatile u8*)0X38)
#define 	DDRB_REG		*((volatile u8*)0X37)
#define 	PINB_REG		*((volatile u8*)0X36)

 /* Group Port A Registers */
#define 	PORTC_REG		*((volatile u8*)0X35)
#define 	DDRC_REG		*((volatile u8*)0X34)
#define 	PINC_REG		*((volatile u8*)0X33)

/* Group Port A Registers */
#define 	PORTD_REG		*((volatile u8*)0X32)
#define 	DDRD_REG		*((volatile u8*)0X31)
#define 	PIND_REG		*((volatile u8*)0X30)



/*PULL UP (in Bit 2 Write 0 to enable Pull_UP is (OPTIONAL) )
#define 	SFIOR_REG		*((volatile u8*)0X50)
*/

#endif
