/*
 * uart.c
 *
 * Created: 9/9/2023 7:36:08 PM
 *  Author: Mohamed
 */ 


#include "uart.h"



void UART_Init(void)
{
	// Baud Rate
	UBRRL = 51;
	// normal mode
	Reset_Bit(UCSRA, U2X);
	
	// Frame
	// no Barity + 8 bit data
	Set_Bit(UCSRC, UCSZ0);
	Set_Bit(UCSRC, UCSZ1);
	Reset_Bit(UCSRB, UCSZ2);
	
	// Enable 
	Set_Bit(UCSRB, TXEN);
	Set_Bit(UCSRB, RXEN);
}







void UART_Send(uint8_t data)
{
	while(!Read_Bit(UCSRA, UDRE));
	UDR = data;
}








uint8_t UART_Receive(void)
{
	while(!Read_Bit(UCSRA, RXC));
	return UDR;
}






void UART_Send_Number(uint32_t Num)
{
	uint8_t *p=&Num;
	UART_Send(p[0]);
	UART_Send(p[1]);
	UART_Send(p[2]);
	UART_Send(p[3]);
}


uint32_t UART_Receive_Number(void)
{
	uint32_t num;
	uint8_t *p=&num;
	p[0] = UART_Receive();
	p[1] = UART_Receive();
	p[2] = UART_Receive();
	p[3] = UART_Receive();
	return num;
}




void UART_SendString(char* str) {
	while (*str != '\0') {
		UART_Send(*str);
		str++;
	}
	//to indicate end
	UART_Send('\r');
}


void UART_ReceiveString(char *Buffer)
{
	
	*Buffer = UART_Receive();
	while (*Buffer != '\r') {
		Buffer++;
		*Buffer = UART_Receive();
	}
	*Buffer = '\0';
}