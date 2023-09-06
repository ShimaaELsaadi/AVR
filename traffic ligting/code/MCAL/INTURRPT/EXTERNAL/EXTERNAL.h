/*
 * EXTERNAL.h
 *
 *  Created on: Jul 30, 2023
 *      Author: shim
 */
#ifndef MCAL_INTURRPT_EXTERNAL_EXTERNAL_H_
#define MCAL_INTURRPT_EXTERNAL_EXTERNAL_H_
#include "../../DIO/DIO.h"

/*Bits from MCUCR REGISIER*/
#define ISC00     0
#define ISC01     1
#define ISC10	  2
#define ISC11	  3
#define ISC2      6

/*Bits from GICR REGISIER*/
#define INT2      5
#define INT0      6
#define INT1      7

/*Bits from GIFR REGISIER*/
#define INTF2     5
#define INTF0     6
#define INTF1     7

/*-------------------------------------*/

void EXTERNAL_Init(u8 inturrupt_number);











#endif /* MCAL_INTURRPT_EXTERNAL_EXTERNAL_H_ */
