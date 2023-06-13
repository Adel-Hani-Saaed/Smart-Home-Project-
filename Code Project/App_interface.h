/********************************************************/
/********************************************************/
/*************** Author: Adel_Hani	  *******************/
/*************** Layer: APP 		  *******************/
/*************** SWC: SmartHome		  *******************/
/*************** Date: 3/5/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/
#ifndef APP_INTERFACE_H_
#define APP_INTERFACE_H_

/*New Data Type AccountUsers_t (Struct) contains two 10-byte arrays named 'UserNameSaved' and 'PasswordSaved'  */
typedef struct
{
	u8 UserNameSaved[10];
	u8 PasswordSaved[10];

}AccountUsers_t;


void App_voidInit(void);

void APP_voidSmartHomeControl(void);

u8 APP_u8Check_Pass( u8 *Copy_u8SaveUser , u8 *Copy_u8EnterUser , u8  Copy_u8SizeUser , u8 *Copy_u8SavePassWord , u8 *Copy_u8EnterPassWord , u8  Copy_u8SizePassWord );

u8 APP_u8GetlengthArr(u8 *Copy_u8Array);


#endif /* APP_INTERFACE_H_ */
