/*
 * testdiodrv.c
 *
 *  Created on: Aug 20, 2023
 *      Author: shim
 */
#include "../MCAL/DIO/DIO.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/KEYPAD/KeyPad.h"
#include "../MCAL/Timer0/TIM0.h"
#include "../MCAL/INTURRPT/GELOPAL/GELOPAL.h"
#include <avr/delay.h>
/*int led_test(){
	Dio_Init();
	Dio_WriteChannel(PINA_5,HIGH);
	_delay_ms(1000);
	Dio_WriteChannel(PINA_5,LOW);
	_delay_ms(1000);
    Dio_WriteChannel(PINC_5,HIGH);
	if (Dio_ReadChannel(PINC_5)==1)
	{
		Dio_WriteChannel(PINA_5,HIGH);
	}
	while(1){

	}
}*/

void traffic_light(void);
u32 count=0;
	u8 remin;


int main(){
	Dio_Init();
    LCD_Init();
    TIM0_init();
    LCD_Gotoxy(0,5);
    LCD_SEND_STRING("Traffic Light ");
    LCD_Gotoxy(1,4);
    LCD_SEND_STRING("Reaming time:");
    LCD_Gotoxy(2,9);
    LCD_SEND_STRING(" Sec");
	TIMO_set_callback_COM(&traffic_light);
    TIMO_INTRRUPT_Enable();
	while(1){

	}

}

void traffic_light(void){
	if(count==0){
		remin=9;
	Dio_WriteChannel(PIND_0,HIGH);

		}
	else if(count==1000){
		remin=4;
		Dio_WriteChannel(PIND_0,LOW);
		Dio_WriteChannel(PIND_1,HIGH);

			}
	else if(count==1500){
		remin=6;
		Dio_WriteChannel(PIND_1,LOW);
		Dio_WriteChannel(PIND_2,HIGH);

			}
	else if(count==2200){
		remin=9;
		Dio_WriteChannel(PIND_2,LOW);
		Dio_WriteChannel(PIND_0,HIGH);
		count=0;
			}
	else{

	}
	if(count%100==0)
	{
        LCD_Gotoxy(2,8);
		LCD_SendNumber(remin);
		remin--;
	}

   count++;
}



