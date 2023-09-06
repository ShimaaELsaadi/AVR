/*
 * DIO_REG.h
 *
 *  Created on: Jul 22, 2023
 *      Author: shim
 */

#ifndef MCAL_DIO_DIO_REG_H_
#define MCAL_DIO_DIO_REG_H_

/* Group A Registers */
#define PORT_A 			 *((volatile u8*)0x3B)
#define DDR_A  			 *((volatile u8*)0x3A)
#define PIN_A   		 *((volatile u8*)0x39)

/* Group B Registers */
#define PORT_B 			 *((volatile u8*)0x38)
#define DDR_B 		     *((volatile u8*)0x37)
#define PIN_B 		     *((volatile u8*)0x36)

/* Group C Registers */
#define PORT_C			 *((volatile u8*)0x35)
#define DDR_C   		 *((volatile u8*)0x34)
#define PIN_C   		 *((volatile u8*)0x33)

/* Group D Registers */
#define PORT_D  		  *((volatile u8*)0x32)
#define DDR_D		   	  *((volatile u8*)0x31)
#define PIN_D 			  *((volatile u8*)0x30)

/*  TIMER0 Registers            */
#define TCCR0    		  *((volatile u8*)0x53)
#define TCNT0    		  *((volatile u8*)0x52)
#define TIFR    		  *((volatile u8*)0x58)
#define TIMSK    		  *((volatile u8*)0x59)
#define OCR0    		  *((volatile u8*)0x5C)

/*INTURRPT Registers */
#define MCUCSR    		  *((volatile u8*)0x54)
#define MCUCR    		  *((volatile u8*)0x55)
#define GICR    		  *((volatile u8*)0x5B)
#define GIFR    		  *((volatile u8*)0x5A)
#define SREG    		  *((volatile u8*)0x5F)

/* TIM1*/

#define TCCR1A    		  *((volatile u8*)0x4F)
#define TCCR1B    		  *((volatile u8*)0x4E)
#define TCNT1    		  *((volatile u16*)0x4C)
#define OCR1A    		  *((volatile u16*)0x4A)
#define OCR1B    		  *((volatile u16*)0x48)
#define ICR1    		  *((volatile u16*)0x46)
/*ADC*/
#define ADMUX    		  *((volatile u8*)0x27)
#define ADCSRA    		  *((volatile u8*)0x26)
#define ADC    	      	  *((volatile u16*)0x24)
/*USART*/
#define UDR    		      *((volatile u8*)0x2C)
#define UCSRA    		  *((volatile u8*)0x2B)
#define UCSRB    		  *((volatile u8*)0x2A)
#define UCSRC    		  *((volatile u8*)0x040)
#define UBRRL    		  *((volatile u8*)0x29)
#define UBRRH    		  *((volatile u8*)0x40)

/*SPI*/
#define SPCR    		  *((volatile u8*)0x2D)
#define SPSR    		  *((volatile u8*)0x2E)
#define SPDR    		  *((volatile u8*)0x2F)
/*TWI*/
#define TWBR    		  *((volatile u8*)0x20)
#define TWCR    		  *((volatile u8*)0x56)
#define TWSR    		  *((volatile u8*)0x21)
#define TWDR    		  *((volatile u8*)0x23)
#define TWAR    		  *((volatile u8*)0x22)
#endif /* MCAL_DIO_DIO_REG_H_ */
