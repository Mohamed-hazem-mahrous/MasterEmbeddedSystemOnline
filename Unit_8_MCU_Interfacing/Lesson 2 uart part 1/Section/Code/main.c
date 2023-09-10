/*
 * unt8_2_sec_uart.c
 *
 * Created: 9/9/2023 7:35:38 PM
 * Author : Mohamed
 */ 


#include "uart/uart.h"
#include "LCD/lcd.h"

#define F_CPU 8000000UL

int main(void)
{
	
	char x;
	char txt[100];
	LCD_INIT();
	LCD_clear_screen();
	_delay_ms(1000);
	LCD_WRITE_STRING("UART test");
	
	UART_Init();
	
	LCD_GOTO_XY(2,0);
	UART_SendString("Mohamed Hazem");
	
	while (1)
	{
		// string
		UART_ReceiveString(txt);
		LCD_WRITE_STRING(txt);
		
		//character
		//x = UART_Receive();
		//LCD_WRITE_CHAR(x);
	}
}
