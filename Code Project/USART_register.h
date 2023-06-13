/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: USART			  *******************/
/*************** Date: 15/4/2023 	  *******************/
/*************** Version: 2.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef USART_REGISTER_H_
#define USART_REGISTER_H_


#define UDR_REG       		*((volatile u8 *)0x2C)		/*UART I/O Data Register*/


#define UCSRA_REG	  		*((volatile u8 *)0x2B)		/*UART Control and Status Register_A*/

#define UCSRA_MPCM   		0							/*Multi_processor Communication Mode*/
#define UCSRA_U2X    		1							/*Double the UART Transmission Speed*/
#define UCSRA_PE      	    2							/*Parity Error*/
#define UCSRA_DOR     		3							/*Data OverRun*/
#define UCSRA_FE      		4							/*Frame Error*/
#define UCSRA_UDRE    		5							/*UART Data Register Empty*/
#define UCSRA_TXC     		6							/*UART Transmit Complete*/
#define UCSRA_RXC     		7							/*UART Receive Complete*/



#define UCSRB_REG	  		*((volatile u8 *)0x2A)		/*UART Control and Status Register_B*/

#define UCSRB_TXB8   		0							/*Transmit Data Bit 8*/
#define UCSRB_RXB8    		1                           /*Receive Data Bit 8*/
#define UCSRB_UCSZ2   		2                           /*Character Size Bit 3*/
#define UCSRB_TXEN    		3                           /*Transmitter Enable*/
#define UCSRB_RXEN    		4                           /*Receiver Enable*/
#define UCSRB_UDRIE   		5                           /*UART Data Register Empty Interrupt Enable*/
#define UCSRB_TXCIE   		6                           /*TX Complete Interrupt Enable*/
#define UCSRB_RXCIE   		7                           /*RX Complete Interrupt Enable*/



#define UCSRC_REG			*((volatile u8 *)0x40)		/*UART Control and Status Register_C*/

#define UCSRC_UCPOL   		0							/*Clock Polarity*/
#define UCSRC_UCSZ0   		1                           /*Character Size Bit 1*/
#define UCSRC_UCSZ1   		2                           /*Character Size Bit 2*/
#define UCSRC_USBS    		3                           /*Stop Bit Select*/
#define UCSRC_UPM0    		4                           /*Parity Mode Bit 1*/
#define UCSRC_UPM1    		5                           /*Parity Mode Bit 2*/
#define UCSRC_UMSEL   		6                           /*UART Mode Select*/
#define UCSRC_URSEL   		7                           /*Register Select*/


/*USART Baud Rate Registers  UBRRL and UBRRH*/
#define UBRRL_REG			*((volatile u8 *)0x29)
#define UBRRH_REG			*((volatile u8 *)0x40)





#endif /* USART_REGISTER_H_ */
