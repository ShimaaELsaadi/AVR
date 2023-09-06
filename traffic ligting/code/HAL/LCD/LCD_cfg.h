/*
 * LCD_cfg.h
 *
 *  Created on: Jul 23, 2023
 *      Author: shim
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_
#include "../../MCAL/DIO/DIO.h"

#define eight_mode          0
#define four_mode           1
#define LCD_Mode           four_mode


#define LCD_RS   PINA_3
#define LCD_EN   PINA_2
#define LCD_D4   PINB_0
#define LCD_D5   PINB_1
#define LCD_D6   PINB_2
#define LCD_D7   PINB_4

#endif /* HAL_LCD_LCD_CFG_H_ */
