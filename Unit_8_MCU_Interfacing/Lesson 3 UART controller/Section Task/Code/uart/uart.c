/*
 * uart.c
 *
 * Created: 9/9/2023 7:36:08 PM
 *  Author: Mohamed
 */ 


#include "uart.h"

static char flag_send=1;
static char* TX_Str;

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






uint8_t UART_Receive_Periodec_Check(uint8_t* pdata)
{
	if (Read_Bit(UCSRA, RXC))
	{
		*pdata = UDR;
		return 1;
	}
	return 0;
}


void UART_Send_No_Block(uint8_t data)
{
	UDR = data;
}

uint8_t UART_Recieve_No_Block(void)
{
	return UDR;
}

void UART_RX_Interrupt_Enable()
{
	Set_Bit(UCSRB, RXCIE);
}

void UART_RX_Interrupt_Disable()
{
	Reset_Bit(UCSRB, RXCIE);
}

void UART_TX_Interrupt_Enable()
{
	Set_Bit(UCSRB, TXCIE);
}

void UART_TX_Interrupt_Disable()
{
	Reset_Bit(UCSRB, TXCIE);
}

void UART_ASYCH_Send_String(uint8_t *str)
{
	if(flag_send==1)
	{
		UART_TX_Interrupt_Enable();
		UART_Send_No_Block(str[0]);
		TX_Str=str;
		flag_send=0 ;
	}
}


ISR(USART_TXC_vect)
{
	static uint8_t i=1;
	if(TX_Str[i]!=0)
	{
		UART_Send_No_Block(TX_Str[i]);
		i++;
	}
	else
	{
		i=1;
		flag_send=1;
	}
}