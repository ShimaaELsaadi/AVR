/*
 * timer.h
 *
 *  Created on: Jul 28, 2023
 *      Author: shim
 */

#ifndef MCAL_TIMER0_TIMER_TYPES_H_
#define MCAL_TIMER0_TIMER_TYPES_H_

#define TIM0_Normal_Mode    			1
#define TIM0_PWM                        2
#define TIM0_CTC						3
#define TIM0_Fast_PWM					4

#define NON_INVERTING                   1
#define INVERTING                       2
#define OC0_disconnected                3
#define Toggle_OC0                      4

#define CS00						0
#define CS01						1
#define CS02						2
#define WGM01						3
#define COM00						4
#define COM01						5
#define WGM00						6
#define FOC0						7

#define TOIE0                       0
#define TOV0                        1
#define OCIE0                       1

#define TM0_No_clock_source  		1
#define TM0_NOPRESCALAR  			2
#define TM0_PRESCALAR8  			3
#define TM0_PRESCALAR64  			4
#define TM0_PRESCALAR256  			5
#define TM0_PRESCALAR1024 			6
#define TM0_External_clk_falling_edge 		7
#define TM0_External_clk_rising_edge 		8



#endif /* MCAL_TIMER0_TIMER_TYPES_H_ */
