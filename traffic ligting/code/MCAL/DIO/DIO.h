/*
 * DIO.h
 *
 *  Created on: Jul 22, 2023
 *      Author: shim
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_
#include "../../utils/STD_TYPES.h"
#include "../../utils/BIT_MATH.h"
#include "DIO_Cfg.h"
#include "DIO_TYPES.h"
#include "DIO_Reg.h"

#define defult_size    8
#define ZERO    	   0
#define ONE    		   1


void Dio_Init(void);
void Dio_WriteChannel(PIN_Channel_Type channel, PIN_Status_Type status);
PIN_Status_Type Dio_ReadChannel(PIN_Channel_Type channel);
void DIO_setPinDirection(PIN_Channel_Type channel,PIN_DIRECTION_TYPE DIRECTION);
void DIO_PULL_RES(PIN_Channel_Type channel,RESISTOR_Type Pull);
void DIO_SetPortValue (PORT_Type  Port,u8 u8PortVal);

#endif /* MCAL_DIO_DIO_H_ */
