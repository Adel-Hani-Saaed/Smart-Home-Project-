/********************************************************/
/********************************************************/
/*************** Author: Adel_Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: Timer1		  *******************/
/*************** Date: 31/3/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_


#define TIMER_PRESCALER_MASK					        0b11111000 /* This Value also could use for bit masking */

#define TIMER_NO_CLOCK_SOURCE                           0
#define TIMER_NO_PRESCALER_FACTOR                       1
#define TIMER_DIVISION_FACTOR_8                         2
#define TIMER_DIVISION_FACTOR_64                        3
#define TIMER_DIVISION_FACTOR_256                       4
#define TIMER_DIVISION_FACTOR_1024                      5
#define TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING          6
#define TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING           7

#define TIMER1_NORMAL_MODE								0
#define TIMER1_PWM_8_BIT_MODE							1
#define TIMER1_PWM_9_BIT_MODE							2
#define TIMER1_PWM_10_BIT_MODE							3
#define TIMER1_CTC_OCR1A_MODE							4
#define TIMER1_FAST_PWM_8_BIT_MODE						5
#define TIMER1_FAST_PWM_9_BIT_MODE 						6
#define TIMER1_FAST_PWM_10_BIT_MODE						7
#define TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE		8
#define TIMER1_PWM_PHASE_AND_FREQ_CORRECT_OCR1A_MODE	9
#define TIMER1_PWM_PHASE_CORRECT_ICR1_MODE				10
#define TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE				11
#define TIMER1_CTC_ICR1_MODE							12
#define TIMER1_FAST_PWM_ICR1_MODE						14			/*important Mode*/
#define TIMER1_FAST_PWM_OCR1A_MODE						15


/*Fast PWM*/
#define TIMER_CLR_ON_CTC_SET_ON_TOP					 2
#define TIMER_SET_ON_CTC_CLR_ON_TOP					 3


/*Phase Correct*/
#define TIMER_CLR_ON_CTC_COUNTING_UP_SET_ON_CTC_COUNTING_DWON			 2
#define TIMER_CLR_ON_CTC_COUNTING_DWON_SET_ON_CTC_COUNTING_UP		     3


#define DISABLE						                 0
#define ENABLE						                 1

#define TIMER_OC_DISCONNECTED					     0
#define TIMER_OC_TOGGEL							     1
#define TIMER_OC_LOW							     2
#define TIMER_OC_HIGH							     3


#define TIMER_ICP_FALLING_EDGE                       0
#define TIMER_ICP_RAISING_EDGE                       1


#endif /* TIMER1_PRIVATE_H_ */
