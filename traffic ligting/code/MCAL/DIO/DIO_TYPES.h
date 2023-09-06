/*
 * DIO_TYPES.h
 *
 *  Created on: Jul 22, 2023
 *      Author: shim
 */

#ifndef MCAL_DIO_DIO_TYPES_H_
#define MCAL_DIO_DIO_TYPES_H_

typedef enum {
	/*PORTA*/
	PINA_0,
	PINA_1,
	PINA_2,
	PINA_3,
	PINA_4,
	PINA_5,
	PINA_6,
	PINA_7,
	/*PORTB*/
	PINB_0,
	PINB_1,
	PINB_2,
	PINB_3,
	PINB_4,
	PINB_5,
	PINB_6,
	PINB_7,
	/*PORTC*/
	PINC_0,
	PINC_1,
	PINC_2,
	PINC_3,
	PINC_4,
	PINC_5,
	PINC_6,
	PINC_7,
	/*PORT D*/
	PIND_0,
	PIND_1,
	PIND_2,
	PIND_3,
	PIND_4,
	PIND_5,
	PIND_6,
	PIND_7,
	}PIN_Channel_Type;
typedef enum
{
	LOW,
	HIGH,
}PIN_Status_Type;

typedef enum
{
DIO_INPUT,
DIO_OUTPUT,
}PIN_DIRECTION_TYPE;

typedef enum
{
DIO_PIN0,
DIO_PIN1,
DIO_PIN2,
DIO_PIN3,
DIO_PIN4,
DIO_PIN5,
DIO_PIN6,
DIO_PIN7,
}DIO_PIN_TYPE;

typedef enum {
	bit_0,
	bit_1,
	bit_2,
	bit_3,
} bit_num;


typedef enum
{
	Port_A,
	Port_B,
	Port_C,
	Port_D,
}PORT_Type;


typedef enum
{
	PULL_UP,
	PULL_DOWEN,
}RESISTOR_Type;
#endif /* MCAL_DIO_DIO_TYPES_H_ */
