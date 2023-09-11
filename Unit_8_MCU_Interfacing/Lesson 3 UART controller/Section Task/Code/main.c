/*
 * unt8_2_sec_uart.c
 *
 * Created: 9/9/2023 7:35:38 PM
 * Author : Mohamed
 */ 


#include "uart/uart.h"
#include "LCD/lcd.h"

#define F_CPU 8000000UL


// ============================================== Interrupt ==============================================

int main(void)
{
	int x=10;
	char arr[20];
	LCD_INIT();
	UART_Init();
	
	LCD_GOTO_XY(1,0);
	LCD_WRITE_STRING("Interrupt");
	UART_SendString("Mohamed Hazem");
	
	
	
	while (1)
	{
		LCD_GOTO_XY(2,0);
		
		UART_ASYCH_Send_String("tst");
		
		UART_ReceiveString(arr);
		LCD_WRITE_STRING(arr);

	}
}











// ============================================== Periodic Check ==============================================
/*
int main(void)
{
	char x, y;
	char txt[100];
	LCD_INIT();
	UART_Init();
	
	LCD_GOTO_XY(1,0);
	LCD_WRITE_STRING("Periodic Check");
	UART_SendString("Mohamed Hazem");
	
	while (1)
	{
		if (UART_Receive_Periodec_Check(&y))
		{
			LCD_GOTO_XY(2,0);
			LCD_WRITE_CHAR(y);
		}
	}
}
*/




// ============================================== polling ==============================================
/*
int main(void)
{
	char txt[100];
	
	LCD_INIT();
	UART_Init();
	
	LCD_GOTO_XY(1,0);
	LCD_WRITE_STRING("Polling");
	UART_SendString("Mohamed Hazem");
	
	
	while (1)
	{
		LCD_GOTO_XY(2,0);
		UART_ReceiveString(txt);
		LCD_WRITE_STRING(txt);
	}
}
*/