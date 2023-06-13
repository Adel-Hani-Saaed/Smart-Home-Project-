/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: USART			  *******************/
/*************** Date: 15/4/2023 	  *******************/
/*************** Version: 2.00		  *******************/
/********************************************************/
/********************************************************/


#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_


/* Description : this Function is to  Init the USART
 * \input : nothing
 * Return  : nothing
 */
void USART_voidInit (void);


/* Description : this Function is to Send  Char
 * \input :  Copy_u8Data    				 , Range :  'Char' or any Ascii Data
 * Return  : ErrorStatus
 */
u8   USART_u8SendData (u8 Copy_u8Data);


/* Description : this Function is to Received Char
 * \input :   *Copy_u8ReceviedData     		 , Range : 	Pointer stored data
 * Return  : ErrorStatus
 */
u8   USART_u8RecevieData (u8 * Copy_u8ReceviedData);
u8 USART_voidGetChar(void);


/* Description : this Function is to Send   String Synchronous Function
 * \input :  *Copy_pchString    				, Range :  String (Array of Char)
 * Return  : ErrorStatus
 */
u8   USART_u8SendStringSynch (const char * Copy_pchString);


/* Description : this Function is to Send  String ASynchronous Function
 * \input :  *Copy_pchString    		     			, Range :  String (Array of Char)
 *           void(*Copy_PvNotificationFunction)(void)   , Range :  Function to pointer to Notification the Send or Recived is Finished
 * Return  : ErrorStatus
 */
u8   USART_u8SendStringAsynch (const char * Copy_pchString , void (* Copy_PvNotificationFunction)(void));

/* Description : this Function is to Recived String Synchronous Function
 * \input :  *Copy_pchString    		    , Range :  Array to Stored the Data Received
 *           Copy_uint32BufferSize          , Range :  Number of Size Array Send
 * Return  : ErrorStatus
 */
void USART_voidReceiveString(u8 *Copy_pchString);
u8   USART_u8ReceiveBufferSynch (u8 * Copy_pchString , u32 Copy_uint32BufferSize);


/* Description : this Function is to Recived String ASynchronous Function
 * \input :  *Copy_pchString    		   			    , Range :  Array to Stored the Data Received
 *           Copy_uint32BufferSize          			, Range :  Number of Size Array Send
 *           void(*Copy_PvNotificationFunction)(void)   , Range :  Function to pointer to Notification the Send or Recived is Finished
 *
 * Return  : ErrorStatus
 */
u8   USART_u8ReceiveBufferAsynch (u8 * Copy_pchString , u32 Copy_uint32BufferSize , void (* Copy_PvNotificationFunction)(void));


#endif /* USART_INTERFACE_H_ */
