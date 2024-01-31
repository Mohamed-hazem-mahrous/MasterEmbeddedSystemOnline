/*
 * main.c
 *
 *  Created on: Jan 31, 2024
 *      Author: Mahmoud
 */

#define F_CPU 1000000
#define atoi(num) #num

#include "ADC.h"
#include "Lcd/lcd.h"

int main()
{
	LCD_INIT();
	ADC_Init(VREF_AVCC, ADC_SCALER_64);
	_delay_ms(50);
	int data;

	LCD_clear_screen();
	LCD_WRITE_STRING("Temperature is :");

	while (1) {
		data = ADC_Read(CH_0);
		LCD_GOTO_XY(2, 0);
		LCD_WRITE_STRING(atoi(data));
		LCD_WRITE_STRING(" C");
	}
}



















