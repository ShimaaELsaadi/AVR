/*
 * EXTERNAL.c
 *
 *  Created on: Jul 30, 2023
 *      Author: shim
 */
#include "EXTERNAL.h"

/**
 1-Sense control
 2-peripheral interrupt enable */

void EXTERNAL_Init(u8 inturrupt_number){

	switch (inturrupt_number) {

	case 0:/*INT0*/
		SET_BIT(MCUCR, ISC01);
		CLR_BIT(MCUCR, ISC00);
		SET_BIT(GICR, INT0);
		break;

	case 1:

		SET_BIT(MCUCR, ISC01);
		CLR_BIT(MCUCR, ISC00);
		SET_BIT(GICR, INT1);

		break;
	case 2:
		SET_BIT(MCUCR, ISC01);
		CLR_BIT(MCUCR, ISC00);
		SET_BIT(GICR, INT2);
		break;
	}
}


/*void __vector_1(void)__attribute__((signal));
void __vector_1(void){

	}
void __vector_2(void)__attribute__((signal));

void __vector_2(void){

	}

void __vector_3(void)__attribute__((signal));

void __vector_3(void){

	}*/
