#include "uart.h"

unsigned char string_buffer[100] = "Learn-in-depth: Mohamed Hazem";

void main(void)
{
	
	UART_Send_String(string_buffer);
}