/********************************************************/
/********************************************************/
/*************** Author: Adel_Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: Timer1		  *******************/
/*************** Date: 31/3/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_

/* 	Set Timer0 Waveform Generation Mode
 * 				Choose between
 * 					1. TIMER1_NORMAL_MODE				**
 * 					2. TIMER1_PWM_8_BIT_MODE
 * 					3. TIMER1_PWM_9_BIT_MODE
 *			 		4. TIMER1_PWM_10_BIT_MODE
 *			 		5. TIMER1_CTC_OCR1A_MODE			**
 *			 		6. TIMER1_FAST_PWM_8_BIT_MODE
 *			 		7. TIMER1_FAST_PWM_9_BIT_MODE
 *			 		8. TIMER1_FAST_PWM_10_BIT_MODE
 *			 		9. TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE
 *			 		10.TIMER1_PWM_PHASE_AND_FREQ_CORRECT_OCR1A_MODE
 *			 		11.TIMER1_PWM_PHASE_CORRECT_ICR1_MODE
 *			 		12.TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE
 *			 		13.TIMER1_CTC_ICR1_MODE				**
 *			 		14.TIMER1_FAST_PWM_ICR1_MODE		**
 *			 		15.TIMER1_FAST_PWM_OCR1A_MODE		**
 *
 *
 */
#define TIMER1_WAVEFORM_GENERATION_MODE		TIMER1_FAST_PWM_ICR1_MODE



/*Set the Required Pre_scaler
				Choose between
					1- TIMER_NO_CLOCK_SOURCE
					2- TIMER_NO_PRESCALER_FACTOR
					3- TIMER_DIVISION_FACTOR_8
					4- TIMER_DIVISION_FACTOR_64
					5- TIMER_DIVISION_FACTOR_256
					6- TIMER_DIVISION_FACTOR_1024
					7- TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING
					8- TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING
 */
#define TIMER1_PRESCALER					TIMER_DIVISION_FACTOR_8




/*Set Pre_load Value for Normal Mode*/
#define TIMER1_PRELOAD_VAL					0

/*Set CTCA Value*/
#define TIMER1_CTCA_VAL						550

/*Set CTCB Value*/
#define TIMER1_CTCB_VAL						550

/*Set Input Capture Value*/
#define TIMER1_ICR1_VAL						20000			/*For Period time Servo_motor*/





/*Set Compare Match Output for OCR1A
 * Choose between
 * 		CTC mode					Phase PWM & FAST PWM mode
 * 1. TIMER_OC_DISCONNECTED		|| TIMER_OC_DISCONNECTED
 * 2. TIMER_OC_TOGGEL			||
 * 3. TIMER_OC_LOW				|| TIMER_CLR_ON_CTC_COUNTING_UP_SET_ON_CTC_COUNTING_DWON
 * 4. TIMER_OC_HIGH				|| TIMER_CLR_ON_CTC_COUNTING_DWON_SET_ON_CTC_COUNTING_UP
 */
#define TIMER1_OCR1A_MODE					TIMER_CLR_ON_CTC_COUNTING_UP_SET_ON_CTC_COUNTING_DWON

/*Set Compare Match Output for OCR1B
 * Choose between
 * 		CTC mode					Phase PWM & FAST PWM mode
 * 1. TIMER_OC_DISCONNECTED		|| TIMER_OC_DISCONNECTED
 * 2. TIMER_OC_TOGGEL			||
 * 3. TIMER_OC_LOW				|| TIMER_CLR_ON_CTC_COUNTING_UP_SET_ON_CTC_COUNTING_DWON
 * 4. TIMER_OC_HIGH				|| TIMER_CLR_ON_CTC_COUNTING_DWON_SET_ON_CTC_COUNTING_UP
 */
#define TIMER1_OCR1B_MODE					TIMER_CLR_ON_CTC_COUNTING_UP_SET_ON_CTC_COUNTING_DWON




/*Set Timer1 Overflow Interrupt
 * Choose between
 * 1. DISABLE
 * 2. ENABLE
 */
#define TIMER1_OVERFLOW_INTERRUPT			DISABLE

/*Set Timer1 CTCB Interrupt
 * Choose between
 * 1. DISABLE
 * 2. ENABLE
 */
#define TIMER1_CTCB_INTERRUPT			    DISABLE

/*Set Timer1 CTCA Interrupt
 * Choose between
 * 1. DISABLE
 * 2. ENABLE
 */
#define TIMER1_CTCA_INTERRUPT		       	DISABLE

/*Set Timer1 Input Capture Interrupt
 * Choose between
 * 1. DISABLE
 * 2. ENABLE
 */
#define TIMER1_ICR_INTERRUPT				DISABLE




/* 	For ICU HardWare Trigger
 * 		Choose between
 * 				1.TIMER_ICP_RAISING_EDGE
 * 				2.TIMER_ICP_FALLING_EDGE
 */
#define TIMER_ICP_INIT_STATE      TIMER_ICP_RAISING_EDGE






#endif /* TIMER1_CONFIG_H_ */
