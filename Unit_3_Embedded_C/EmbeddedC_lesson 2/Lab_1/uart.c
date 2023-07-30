#include "uart.h"

#define UART0_DR   *((volatile unsigned int* const) ((unsigned int*) 0x101f1000))  // defining pointer to the data register of UART0 which is at 0x101f1000


void UART_Send_String(unsigned char* P_tx_string)
{
	while(*P_tx_string != '\0')
	{// loop until the end of the string

		UART0_DR = (unsigned int) (*P_tx_string); // transmit character to the uart
		P_tx_string++; // next Char
	}
}








