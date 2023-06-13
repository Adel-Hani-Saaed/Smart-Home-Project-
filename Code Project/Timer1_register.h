/********************************************************/
/********************************************************/
/*************** Author: Adel_Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: Timer1		  *******************/
/*************** Date: 31/3/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef TIMER1_REGISTER_H_
#define TIMER1_REGISTER_H_


#define TIMSK_REG			*((volatile u8*)0X59)		/*Timer/Counter Interrupt Mask Register*/
#define TIMSK_TICIE1		5							/*Timer/Counter1, Input Capture Interrupt Enable*/
#define TIMSK_OCIE1A		4                           /*Timer/Counter1, Output Compare A Match Interrupt Enable*/
#define TIMSK_OCIE1B		3                           /*Timer/Counter1, Output Compare B Match Interrupt Enable*/
#define TIMSK_TOIE1			2                           /*Timer/Counter1, Overflow Interrupt Enable*/

#define TIFR_REG			*((volatile u8*)0X58)		/*Timer/Counter Interrupt Flag Register*/


#define TCCR1A_REG			*((volatile u8*)0X4F)		/*Timer/Counter1 Control Register A – TCCR1A*/
#define TCCR1A_COM1A1		7							/*Compare Output Mode for Channel A*/
#define TCCR1A_COM1A0		6							/*Compare Output Mode for Channel A*/
#define TCCR1A_COM1B1		5							/*Compare Output Mode for Channel B*/
#define TCCR1A_COM1B0		4							/*Compare Output Mode for Channel B*/
#define TCCR1A_FOC1A		3							/* Force Output Compare for Channel A*/
#define TCCR1A_FOC1B		2							/* Force Output Compare for Channel B*/
#define TCCR1A_WGM11		1							/*Waveform Generation Mode*/
#define TCCR1A_WGM10		0							/*Waveform Generation Mode*/



#define TCCR1B_REG			*((volatile u8*)0X4E)		/*Timer/Counter1 Control Register B – TCCR1B*/
#define TCCR1B_ICNC1		7                           /*Input Capture Noise Canceler*/
#define TCCR1B_ICES1		6                           /*Input Capture Edge Select*/
#define TCCR1B_WGM13		4                           /*Waveform Generation Mode*/
#define TCCR1B_WGM12		3                           /*Waveform Generation Mode*/
#define TCCR1B_CS12			2							/*Clock Selection Bit_3*/
#define TCCR1B_CS11			1							/*Clock Selection Bit_2*/
#define TCCR1B_CS10			0							/*Clock Selection Bit_1*/


#define TCNT1L_REG          *((volatile u8 *)0x4C)
#define TCNT1H_REG          *((volatile u8 *)0x4D)


#define TCNT1_REG			*((volatile u16*)0X4C)     /* u16 for HIGH & LOW */


#define OCR1A_REG			*((volatile u16*)0X4A)	   /*Output Compare Register 1 A – OCR1AH and OCR1AL u16 for HIGH & LOW */
#define OCR1AL_REG          *((volatile u8 *)0x4A)
#define OCR1AH_REG          *((volatile u8 *)0x4B)



#define OCR1B_REG			*((volatile u16*)0X48)		/*Output Compare Register 1 B – OCR1BH and OCR1BL  u16 for HIGH & LOW */
#define OCR1BL_REG          *((volatile u8 *)0x48)
#define OCR1BH_REG          *((volatile u8 *)0x49)



#define ICR1_REG			*((volatile u16*)0X46)      /*Input Capture Register 1 – ICR1H and ICR1L u16 for HIGH & LOW */
#define ICR1L_REG           *((volatile u8 *)0x46)
#define ICR1H_REG           *((volatile u8 *)0x47)





#endif /* TIMER1_REGISTER_H_ */
