/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: USART			  *******************/
/*************** Date: 15/4/2023 	  *******************/
/*************** Version: 2.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

#define USART_IDEL								1
#define USART_BUSY								0

#define DISABLE				                    0
#define ENABLE				                    1

#define USART_NORMAL_SPEED			            1
#define USART_DOUBLE_SPEED			            2

#define ASYNCHRONOUS		                    0
#define SYNCHRONOUS 		                    1

#define EVEN_PARITY			                    0
#define ODD_PARITY 			                    1

#define STOP_BIT_1			                    0
#define STOP_BIT_2			                    1

#define DATA_SIZE_5_BIT		                    0
#define DATA_SIZE_6_BIT		                    1
#define DATA_SIZE_7_BIT		                    2
#define DATA_SIZE_8_BIT		                    3
#define DATA_SIZE_9_BIT		                    4

#define XCK_RISING_TX_XCH_FALLING_RX			0
#define XCK_RISING_RX_XCH_FALLING_TX			1

#define UBRRL_MAX								256


#endif /* USART_PRIVATE_H_ */
