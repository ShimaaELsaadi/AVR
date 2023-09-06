/*
 * DIO_Cfg.h
 *
 *  Created on: Jul 22, 2023
 *      Author: shim
 */

#ifndef MCAL_DIO_DIO_CFG_H_
#define MCAL_DIO_DIO_CFG_H_
#include "DIO_TYPES.h"
#define MAX_PINS      32
struct PINs{
	PORT_Type Port;
	PIN_Channel_Type Pin_Num;
	PIN_DIRECTION_TYPE DIRECTION;
	RESISTOR_Type  PULL;
};

extern  struct PINs PIN_cfg[MAX_PINS];

#endif /* MCAL_DIO_DIO_CFG_H_ */
