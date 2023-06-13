/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: USART			  *******************/
/*************** Date: 15/4/2023 	  *******************/
/*************** Version: 2.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

/****************************************************/
/********** Config BuadRate Selection ***************/
/****************************************************/
/*Set Baud Rate*/
#define USART_BAUD_RATE					9600UL


/*Set Timeout for Your functions*/
#define USART_u32TIMEOUT	         	10000UL


/*Set System Frequency*/
#define SYSTEM_FREQUENCY				8000000UL
/****************************************************/




/****************************************************/
/************* Config Mode Selection ****************/
/****************************************************/
/*Set USART Mode Select
 * 		Choose between
 * 			1. ASYNCHRONOUS
 * 			2. SYNCHRONOUS
 */
#define USART_MODE						ASYNCHRONOUS

/*Set Clock Polarity (for SYNCHRONOUS mode only)
 * 		Choose between
 * 			1. XCK_RISING_TX_XCH_FALLING_RX
 * 			2. XCK_RISING_RX_XCH_FALLING_TX
 */
#define USART_CLOCK_POLARITY			XCK_RISING_TX_XCH_FALLING_RX


/*Set System Speed
 * 		Choose between
 * 			1. USART_NORMAL_SPEED
 * 			2. USART_DOUBLE_SPEED  (Double Speed Mode)
 */
#define USART_SYSTEM_SPEED				USART_NORMAL_SPEED


/*Set Multi-Processor Communication mode
 * 		Choose between
 * 			1. DISABLE
 * 			2. ENABLE
 */
#define USART_MPCM						DISABLE
/****************************************************/




/****************************************************/
/******************* Config the Frame ***************/
/****************************************************/
/*Set Data Size
 * 		Choose between
 * 			1. DATA_SIZE_5_BIT
 * 			2. DATA_SIZE_6_BIT
 * 			3. DATA_SIZE_7_BIT
 * 			4. DATA_SIZE_8_BIT
 * 			5. DATA_SIZE_9_BIT
 */
#define USART_DATA_SIZE					DATA_SIZE_8_BIT

/*Set Parity Mode
 * 		Choose between
 * 			1. DISABLE
 * 			2. EVEN_PARITY
 * 			3. ODD_PARITY
 */
#define USART_PARITY_MODE				DISABLE

/*Set Stop bit
 * 		Choose between
 * 			1. STOP_BIT_1
 * 			2. STOP_BIT_2
 */
#define USART_STOP_BIT					STOP_BIT_1
/****************************************************/





/****************************************************/
/*************** FullDuplex Or HalfDuplex ***********/
/****************************************************/
/*Set Receiver Enable
 * 		Choose between
 * 			1. DISABLE
 * 			2. ENABLE
 */
#define USART_RECEIVER_ENABLE			ENABLE


/*Set Transmitter Enable
 * 		Choose between
 * 			1. DISABLE
 * 			2. ENABLE
 */
#define USART_TRANSMITTER_ENABLE		ENABLE
/****************************************************/




/****************************************************/
/************** Coonfig Interrupts ******************/
/****************************************************/
/*Set RX Complete Interrupt Enable
 * 		Choose between
 * 			1. DISABLE
 * 			2. ENABLE
 */
#define USART_RX_COMPLETE_INTERRUPT		DISABLE


/*Set TX Complete Interrupt Enable
 * 		Choose between
 * 			1. DISABLE
 * 			2. ENABLE
 */
#define USART_TX_COMPLETE_INTERRUPT		DISABLE


/*Set UDR Empty Interrupt Enable
 * 		Choose between
 * 			1. DISABLE
 * 			2. ENABLE
 */
#define USART_UDR_EMPTY_INTERRUPT		DISABLE
/****************************************************/




#endif /* USART_CONFIG_H_ */
