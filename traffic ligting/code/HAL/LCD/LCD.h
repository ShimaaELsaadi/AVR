/*
 * LCD.h
 *
 *  Created on: Jul 23, 2023
 *      Author: shim
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

/*LIB includes*/
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/DIO/DIO_Cfg.h"
#include "LCD_private.h"





#define shift_bit        4


/*Functions Prototypes*/
void LCD_Init(void);
void LCD_SendCommand(u8 u8_copy_command);
void LCD_SendData(u8 u8_copy_Data);
void LCD_SEND_STRING(const char *value);
void LCD_CLEAR(void);
void LCD_Gotoxy(u8 X,u8 Y);
void LCD_SendNumber(u8 num);
void LCD_WriteSpecialChar(u8 Y,u8 X);

#endif /* HAL_LCD_LCD_H_ */
