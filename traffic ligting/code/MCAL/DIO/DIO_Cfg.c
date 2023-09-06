/*
 * DIO_REG.c
 *
 *  Created on: Jul 22, 2023
 *      Author: shaim
 */

#include "DIO_Cfg.h"
struct PINs PIN_cfg[MAX_PINS] ={

/*PORT A*/
{ Port_A,DIO_PIN0,DIO_INPUT },
{ Port_A,DIO_PIN1,DIO_OUTPUT },
{ Port_A,DIO_PIN2, DIO_OUTPUT },
{ Port_A,DIO_PIN3,DIO_OUTPUT },
{ Port_A,DIO_PIN4, DIO_INPUT },
{ Port_A,DIO_PIN5,DIO_OUTPUT},
{ Port_A,DIO_PIN6, DIO_INPUT },
{ Port_A,DIO_PIN7,DIO_INPUT },

/*PORT B*/
{ Port_B,DIO_PIN0, DIO_OUTPUT },
{ Port_B,DIO_PIN1, DIO_OUTPUT },
{ Port_B,DIO_PIN2, DIO_OUTPUT },
{ Port_B,DIO_PIN3, DIO_INPUT },
{ Port_B,DIO_PIN4, DIO_OUTPUT},
{ Port_B,DIO_PIN5, DIO_OUTPUT},
{ Port_B,DIO_PIN6, DIO_OUTPUT },
{ Port_B,DIO_PIN7, DIO_OUTPUT},

/*PORT C*/
{ Port_C,DIO_PIN0, DIO_INPUT },
{ Port_C,DIO_PIN1, DIO_OUTPUT },
{ Port_C,DIO_PIN2, DIO_OUTPUT},
{ Port_C,DIO_PIN3, DIO_OUTPUT },
{ Port_C,DIO_PIN4, DIO_OUTPUT },
{ Port_C,DIO_PIN5, DIO_OUTPUT },
{ Port_C,DIO_PIN6, DIO_OUTPUT },
{ Port_C,DIO_PIN7, DIO_OUTPUT },

/*PORT D*/
{ Port_D,DIO_PIN0, DIO_OUTPUT },
{ Port_D,DIO_PIN1, DIO_OUTPUT },
{ Port_D,DIO_PIN2, DIO_OUTPUT},
{ Port_D,DIO_PIN3, DIO_INPUT },
{ Port_D,DIO_PIN4, DIO_INPUT },
{ Port_D,DIO_PIN5, DIO_INPUT},
{ Port_D,DIO_PIN6, DIO_INPUT},
{ Port_D,DIO_PIN7, DIO_INPUT },

};

