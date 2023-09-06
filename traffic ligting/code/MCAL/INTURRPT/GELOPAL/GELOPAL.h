/*
 * GELOPAL.h
 *
 *  Created on: Aug 2, 2023
 *      Author: shim
 */

#ifndef MCAL_INTURRPT_GELOPAL_GELOPAL_H_
#define MCAL_INTURRPT_GELOPAL_GELOPAL_H_




#include "../../../utils/BIT_MATH.h"
#include "../../../utils/STD_TYPES.h"
#include "../../DIO/DIO.h"




#define SREG_I       7




void GELOPAL_INTERRUPT_ENABLE(void);
void GELOPAL_INTERRUPT_DISABLE(void);


#endif /* MCAL_INTURRPT_GELOPAL_GELOPAL_H_ */
