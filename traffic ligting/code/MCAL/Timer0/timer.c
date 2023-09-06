/*
 * timer.c
 *
 *  Created on: Jul 28, 2023
 *      Author: shim
 */

#include "../Timer0/TIM0.h"
#include "../Timer0/TIM0_cfj.h"
#include "../INTURRPT/GELOPAL/GELOPAL.h"

#define NULL         ((void*)0)

volatile u16 counter = 0;

static void (*(TIM0_OVF_Callback))(void) = NULL;
static void (*(TIM0_COM_Callback))(void) = NULL;

void TIM0_init(){
	/*Select MODE OF TIMER */
#if TIM0_Mode==TIM0_Normal_Mode
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
#elif TIM0_Mode==TIM0_CTC
CLR_BIT(TCCR0,WGM00);
SET_BIT(TCCR0,WGM01);
OCRO_SET(INIT_OCR0);
#elif TIM0_Mode==TIM0_PWM
SET_BIT(TCCR0,WGM00);
CLR_BIT(TCCR0,WGM01);
#elif TIM0_Mode==TIM0_Fast_PWM
    SET_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);
#endif
	/*select Compare_Output_Mode*/
#if  Compare_Output_Mode==NON_INVERTING
	SET_BIT(TCCR0, COM01);
	CLR_BIT(TCCR0, COM00);
#elif Compare_Output_Mode==INVERTING
SET_BIT(TCCR0,COM01);
SET_BIT(TCCR0,COM00);
#elif Compare_Output_Mode==Toggle_OC0
SET_BIT(TCCR0,COM01);
SET_BIT(TCCR0,COM00);
#elif Compare_Output_Mode==OC0_disconnected
CLR_BIT(TCCR0, COM01);
CLR_BIT(TCCR0, COM00);
#endif
	/*PRESCALLER*/
#if TM0_PRESCALAR==TM0_No_clock_source
CLR_BIT(TCCR0,CS00);
CLR_BIT(TCCR0,CS01);
CLR_BIT(TCCR0,CS02);
#elif(TM0_PRESCALAR==TM0_NOPRESCALAR)
SET_BIT(TCCR0,CS00);
CLR_BIT(TCCR0,CS01);
CLR_BIT(TCCR0,CS02);
#elif(TM0_PRESCALAR==TM0_PRESCALAR8)
CLR_BIT(TCCR0,CS00);
SET_BIT(TCCR0,CS01);
CLR_BIT(TCCR0,CS02);
#elif(TM0_PRESCALAR==TM0_PRESCALAR64)
SET_BIT(TCCR0,CS00);
SET_BIT(TCCR0,CS01);
CLR_BIT(TCCR0,CS02);
#elif(TM0_PRESCALAR==TM0_PRESCALAR256)
CLR_BIT(TCCR0,CS00);
CLR_BIT(TCCR0,CS01);
SET_BIT(TCCR0,CS02);
#elif(TM0_PRESCALAR==TM0_PRESCALAR1024)
	SET_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	SET_BIT(TCCR0, CS02);
#elif(TM0_PRESCALAR==TM0_External_clk_falling_edge)
	CLR_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	SET_BIT(TCCR0, CS02);
#elif(TM0_PRESCALAR==TM0_External_clk_rising_edge)
	SET_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	SET_BIT(TCCR0, CS02);
#endif
	 /* Clear counter register */
	TCNT0 =0;
}


void TIMO_INTRRUPT_Enable(){
#if TIM0_Mode==TIM0_Normal_Mode
	SET_BIT(TIMSK,TOIE0);
#elif TIM0_Mode==TIM0_CTC
   SET_BIT(TIMSK,OCIE0);
#endif
	/*Enable global interrupts*/
   GELOPAL_INTERRUPT_ENABLE();
}
void TIM0_CHECK_OVF() {
	/* Wait for TOV0 to roll over */
	if (TIFR & (1 << TOV0))
		/* Clear TOV0 flag */
		SET_BIT(TIFR, TOV0);
}

/* Prototype for ISR of TIMER0 OVF */
// Timer0 overflow interrupt service routine
//ISR(TIMER0_OVF_vect) {
//	if (TIM0_OVF_Callback != NULL) {
//		TIM0_OVF_Callback();
//	}
//}
void TIM0_OVF_vCallback(void (*p1v_value)(void)) {
	if (p1v_value != NULL)
		TIM0_COM_Callback = p1v_value;
}
void __vector_11(void)__attribute__((signal));
void __vector_11(void){
	if(TIM0_OVF_Callback!=NULL){
		TIM0_OVF_Callback();
	}
}

void TIMO_set_callback_COM(void (*p2v_value)(void)) {
	if (p2v_value != NULL)
		TIM0_COM_Callback = p2v_value;
}

void __vector_10(void)   __attribute__((signal));
void __vector_10(void){
	if(TIM0_COM_Callback!=NULL){
	   TIM0_COM_Callback();
}
}
// Timer0 overflow interrupt service routine
//ISR(TIMER0_COMP_vect) {
//	if (TIM0_OVF_Callback != NULL) {
//		TIM0_OVF_Callback();
//	}
//}*/

void OCRO_SET(u8 OCR0_VALUE) {

	OCR0 = OCR0_VALUE;
}

void SET_INIT_VALUE(u8 TCNT0_VALUE) {

	TCNT0 = TCNT0_VALUE;
}

void duty_cycle_set_FastPWM(u8 copy_duty_cycle) {
	if (copy_duty_cycle >= 0 && copy_duty_cycle <= 100) {
#if Fast_state==NON_INVERTING
		/*Set the duty cycle using the provided parameter(0-100%)*/
		OCRO_SET((((copy_duty_cycle * 256) / 100) - 1));

#elif Fast_state==INVERTING
	u8 complementary_duty = 100 - copy_duty_cycle;
	OCRO_SET((((complementary_duty * 256) / 100)-1));
#endif
	}
}

void duty_cycle_set_PhaseCorrect(u8 copy_duty_cycle){
	if (copy_duty_cycle >= 0 && copy_duty_cycle <= 100) {
#if Fast_state==NON_INVERTING
		/*Set the duty cycle using the provided parameter(0-100%)*/
		OCRO_SET((((copy_duty_cycle * 256) / 100)));
#elif Fast_state==INVERTING
		u8 complementary_duty = 100 - copy_duty_cycle;
		OCRO_SET((((complementary_duty * 256) / 100)-1));
	#endif
	}
}

