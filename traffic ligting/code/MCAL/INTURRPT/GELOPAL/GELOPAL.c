/*
 * GELOPAL.c
 *
 *  Created on: Aug 2, 2023
 *      Author: shim
 */
#include "GELOPAL.h"

void GELOPAL_INTERRUPT_ENABLE(void){

	SET_BIT(SREG,SREG_I);

	}

void GELOPAL_INTERRUPT_DISABLE(void){

	CLR_BIT(SREG,SREG_I);

	}
