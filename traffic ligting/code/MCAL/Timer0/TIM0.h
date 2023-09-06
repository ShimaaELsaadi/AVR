/*
 * TIM0.h
 *
 *  Created on: Jul 28, 2023
 *      Author: shim
 */

#ifndef MCAL_TIMER0_TIM0_H_
#define MCAL_TIMER0_TIM0_H_
#include "../DIO/DIO.h"
#include "../../utils/STD_TYPES.h"
#include "../../utils/BIT_MATH.h"
#include "../Timer0/timer_TYPES.h"
#include "../Timer0/TIM0_cfj.h"

void TIM0_init();
void TIMO_INTRRUPT_Enable();
void TIM0_CHECK_OVF();
void TIMO_set_callback_OVF(void (*p2v_value)(void));
void TIMO_set_callback_COM(void (*p2v_value)(void));
void OCRO_SET(u8 OCR0_VALUE);
void SET_INIT_VALUE(u8 TCNT0_VALUE);
void duty_cycle_set_FastPWM(u8 copy_duty_cycle) ;
void duty_cycle_set_PhaseCorrect(u8 copy_duty_cycle);



#endif /* MCAL_TIMER0_TIM0_H_ */
