/*
 * LCD.c
 *
 *  Created on: Jul 23, 2023
 *      Author: shim
 */
#include "LCD.h"
#include <util/delay.h>
const unsigned char lineAddresses[] = {0x00, 0x40, 0x14, 0x54};

/*-----------------------private functions--------------*/

static void priwriteHalfPort(u8 value){
	Dio_WriteChannel(LCD_D4,GET_BIT(value,0));
	Dio_WriteChannel(LCD_D5,GET_BIT(value,1));
	Dio_WriteChannel(LCD_D6,GET_BIT(value,2));
	Dio_WriteChannel(LCD_D7,GET_BIT(value,3));
}

static void Enable()
{
	Dio_WriteChannel(LCD_EN,HIGH);
	_delay_ms(1);
	Dio_WriteChannel(LCD_EN,LOW);
}
/*********************************************************************************************/


/*------------------------APIs Functions-----------------------------*/

void LCD_Init(void){

#if(LCD_Mode==four_mode)
	{

	//init lcd as data sheet
	_delay_ms(35);
	Dio_WriteChannel(LCD_RS,LOW);
	priwriteHalfPort(0b0010);
	Enable();
	LCD_SendCommand(0b00101000);
	_delay_us(45);
	/*display on cursor on*/
	LCD_SendCommand(0x0C);
	_delay_us(45);
	//clear display
	LCD_SendCommand(0b00000001);
	_delay_ms(2);
	//Entry Mode
	LCD_SendCommand(0b00000110);
	}

#elif(LCD_Mode==eight_mode)
	{
	_delay_us(30);
	LCD_SendCommand(00110000);
	_delay_us(39);
	LCD_SendCommand(00001000);
	_delay_us(39);
	LCD_SendCommand(00000001);
	_delay_ms(1.53);
	LCD_SendCommand(00000100);
	}
#endif
}

void LCD_SendCommand(u8 u8_copy_command){
#if(LCD_Mode==eight_mode)
	{	Dio_WriteChannel(LCD_RS,LOW);
		 Enable();
		priwriteHalfPort(u8_copy_command);

	}
#elif(LCD_Mode==four_mode)
	{	//SET RS PIN AS COMMAND -ACTIVE LOW-
		Dio_WriteChannel(LCD_RS,LOW);
		priwriteHalfPort((u8_copy_command)>>shift_bit);
		Enable();
		priwriteHalfPort((u8_copy_command));
		Enable();
	}
#endif
}

void LCD_SendData(u8 u8_copy_data){

#if(LCD_Mode==eight_mode)
	{
		Dio_WriteChannel(LCD_RS,HIGH);
		Enable();
		priwriteHalfPort(u8_copy_data);

	}
#elif(LCD_Mode==four_mode)
	{
		//SET RS PIN AS DATA
		Dio_WriteChannel(LCD_RS,HIGH);
		priwriteHalfPort((u8_copy_data)>>shift_bit);
		Enable();
		priwriteHalfPort((u8_copy_data));
		Enable();

	}
#endif
}
void LCD_SEND_STRING(const char *value){
int i=0;
	while (value[i]!='\0')
	{
		LCD_SendData(value[i]);
		i++;
	}
}

void LCD_CLEAR(void)
{
	LCD_SendCommand (0x01);		/* clear display */
	_delay_ms(2);
	LCD_SendCommand (0x80);		/* cursor at home position */
}

void LCD_Gotoxy(u8 X,u8 Y){
	/*Check valid range*/
	if (Y < 20 && X < 4) {
	        unsigned char address = lineAddresses[X] + Y;
	        /*Set DDRAM address command*/
	        LCD_SendCommand(0x80 | address);
	    }
}

void LCD_SendNumber(u8 num){

	u8 data =num+'0';
	LCD_SendData(data);
}

/*
void LCD_WriteSpecialChar(u8 Y,u8 X)
{
    u8 iteration1,iteration2;
    /*DDRAM-->CGRAM
/*
    LCD_SendCommand(64);
	for(iteration1=0 ; iteration1<64 ; iteration1++)
	{
		//LCD_SendData(ExtraChars[iteration1]);
	}
	/*CGRAM-->DDRAM*/
/*	LCD_SendCommand(128);
	Gotoxy(Y,X);
	/*First eight character which saved at CGRAM*/
/*	for (iteration2=0; iteration2<=7 ; iteration2++)
	{
		/* Write bytes of DDRAM */
/*		LCD_SendData(iteration2);

		_delay_ms(5);
	}
}






/*********************************************************************************/


