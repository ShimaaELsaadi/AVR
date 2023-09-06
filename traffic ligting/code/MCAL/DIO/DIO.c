/*
 * dio.c
 *
 *  Created on: Jul 21, 2023
 *      Author: shim
 */
#include "DIO.h"

/*____________________APIs Functions________________________*/
/************************************************************************************
* Service Name: Dio_Init
* Description: Function to Initialize the Dio module.
************************************************************************************/
void Dio_Init(void){
	int i;
	for (i = 0; i < (sizeof(PIN_cfg) / sizeof(PIN_cfg[0])); i++) {
		switch (PIN_cfg[i].Port) {
		case Port_A:
			if (PIN_cfg[i].DIRECTION == DIO_INPUT) {
				CLR_BIT(DDR_A, PIN_cfg[i].Pin_Num);
			}
			else if (PIN_cfg[i].DIRECTION == DIO_OUTPUT)
			{
				SET_BIT(DDR_A, PIN_cfg[i].Pin_Num);

			}
			break;
		case Port_B:
			if (PIN_cfg[i].DIRECTION == DIO_INPUT) {
				CLR_BIT(DDR_B, PIN_cfg[i].Pin_Num);
			}
						else if (PIN_cfg[i].DIRECTION == DIO_OUTPUT)
						{
							SET_BIT(DDR_B, PIN_cfg[i].Pin_Num);
//							if(PIN_cfg[i].PULL == PULL_UP)
//							SET_BIT(PORT_B, PIN_cfg[i].Pin_Num);
//							else if(PIN_cfg[i].PULL == PULL_DOWEN)
//							CLR_BIT(PORT_B, PIN_cfg[i].Pin_Num);
						}
			break;
		case Port_C:
			if (PIN_cfg[i].DIRECTION == DIO_INPUT) {
							CLR_BIT(DDR_C, PIN_cfg[i].Pin_Num);
						}
						else if (PIN_cfg[i].DIRECTION == DIO_OUTPUT)
						{
							SET_BIT(DDR_C, PIN_cfg[i].Pin_Num);
//							if(PIN_cfg[i].PULL == PULL_UP)
//							SET_BIT(PORT_C, PIN_cfg[i].Pin_Num);
//							else if(PIN_cfg[i].PULL == PULL_DOWEN)
//							CLR_BIT(PORT_C, PIN_cfg[i].Pin_Num);
						}
			break;
		case Port_D:
			if (PIN_cfg[i].DIRECTION == DIO_INPUT) {
							CLR_BIT(DDR_D, PIN_cfg[i].Pin_Num);
						}
						else if (PIN_cfg[i].DIRECTION == DIO_OUTPUT)
						{
							SET_BIT(DDR_D, PIN_cfg[i].Pin_Num);
//							if(PIN_cfg[i].PULL == PULL_UP)
//							SET_BIT(PORT_D, PIN_cfg[i].Pin_Num);
//							else if(PIN_cfg[i].PULL == PULL_DOWEN)
//							CLR_BIT(PORT_D, PIN_cfg[i].Pin_Num);
						}
			break;

		}
	}

}

/************************************************************************************
* Service Name: Dio_WriteChannel
* Description: Function to set a level of a channel.
************************************************************************************/
void Dio_WriteChannel(PIN_Channel_Type channel, PIN_Status_Type status){
	u8 PORT_NUM = channel / defult_size;
	u8 PIN_NUM = channel % defult_size;
	switch (PORT_NUM) {
	case Port_A:
		SET_BIT(DDR_A, PIN_NUM);
		if (status == LOW) {
			CLR_BIT(PORT_A, PIN_NUM);
		}
		else if (status == HIGH){
			SET_BIT(PORT_A, PIN_NUM);
		}
		break;
	case Port_B:
		SET_BIT(DDR_B, PIN_NUM);
		if (status == LOW) {
			CLR_BIT(PORT_B, PIN_NUM);
		}
		else if (status == HIGH){
			SET_BIT(PORT_B, PIN_NUM);
		}
		break;
	case Port_C:
		SET_BIT(DDR_C, PIN_NUM);
		if (status == LOW) {
			CLR_BIT(PORT_C, PIN_NUM);
		}
		else if (status == HIGH){
			SET_BIT(PORT_C, PIN_NUM);
		}
		break;
	case Port_D:
		SET_BIT(DDR_D, PIN_NUM);
		if (status == LOW) {
			CLR_BIT(PORT_D, PIN_NUM);
		}
		else if (status == HIGH){
			SET_BIT(PORT_D, PIN_NUM);
		}
		break;

	default:
		break;
	}
}
/************************************************************************************
* Service Name: Dio_ReadChannel
* Description: Function to return the value of the specified DIO channel.
************************************************************************************/
PIN_Status_Type Dio_ReadChannel(PIN_Channel_Type channel){
	u8 PORT_NUM = channel / defult_size;
	u8 PIN_NUM = channel % defult_size;
	PIN_Status_Type status;
	switch (PORT_NUM) {
	case Port_A:
		//SET_BIT(DDR_A, PIN_NUM);
		status = GET_BIT(PIN_A, PIN_NUM);
		break;
	case Port_B:
		//SET_BIT(DDR_B, PIN_NUM);
		status = GET_BIT(PIN_B, PIN_NUM);
		break;
	case Port_C:
		//SET_BIT(DDR_C, PIN_NUM);
		status = GET_BIT(PIN_C, PIN_NUM);
		break;
	case Port_D:
		//SET_BIT(DDR_D, PIN_NUM);
		status = GET_BIT(PIN_D, PIN_NUM);
		break;
	}
	return status;
}

void DIO_setPinDirection(PIN_Channel_Type channel,PIN_DIRECTION_TYPE DIRECTION){
	u8 PORT_NUM = channel / defult_size;
	u8 PIN_NUM = channel % defult_size;
	if(DIRECTION==DIO_OUTPUT){
	switch (PORT_NUM){
		case Port_A:
			SET_BIT(DDR_A,PIN_NUM);
			break;
		case Port_B:
			SET_BIT(DDR_B,PIN_NUM);
			break;
		case Port_C:
			SET_BIT(DDR_C,PIN_NUM);
			break;
		case Port_D:
			SET_BIT(DDR_D,PIN_NUM);
			break;
	}
	}
	else if(DIRECTION==DIO_INPUT)
	{
	switch (PORT_NUM) {
	case Port_A:
		CLR_BIT(DDR_A,PIN_NUM);
		break;
	case Port_B:
		CLR_BIT(DDR_B,PIN_NUM);
		break;
	case Port_C:
		CLR_BIT(DDR_C,PIN_NUM);
		break;
	case Port_D:
		CLR_BIT(DDR_D,PIN_NUM);
		break;
	}
	}
}

void DIO_PULL_RES(PIN_Channel_Type channel,RESISTOR_Type Pull){
	u8 PORT_NUM = channel / defult_size;
	u8 PIN_NUM = channel % defult_size;
	switch (PORT_NUM) {
	case Port_A:
   if(Pull == PULL_UP)
	SET_BIT(PORT_A,PIN_NUM);
	else if(Pull == PULL_DOWEN)
	CLR_BIT(PORT_A,PIN_NUM);
   break;
	case Port_B:
	 if(Pull == PULL_UP)
		SET_BIT(PORT_B,PIN_NUM);
		else if(Pull == PULL_DOWEN)
		CLR_BIT(PORT_B,PIN_NUM);
	  break;
	case Port_C:
	if(Pull == PULL_UP)
		SET_BIT(PORT_C,PIN_NUM);
		else if(Pull == PULL_DOWEN)
		CLR_BIT(PORT_C,PIN_NUM);
	  break;
	case Port_D:
	  if(Pull == PULL_UP)
		SET_BIT(PORT_D,PIN_NUM);
		else if(Pull == PULL_DOWEN)
		CLR_BIT(PORT_D,PIN_NUM);
	  break;
	}
}

void DIO_SetPortValue (PORT_Type  Port,u8 u8PortVal)
{
	/* Check on the Required PORT Number */
	switch (Port)
	{
		case     Port_A:
			PORT_A = u8PortVal;
			break;
		case Port_B:
			PORT_B = u8PortVal;
			break;
		case Port_C:
			PORT_C = u8PortVal;
			break;
		case  Port_D:
			PORT_D = u8PortVal;
			break;
		default:
			/* Wrong Port ID */
			break;
	}
}
