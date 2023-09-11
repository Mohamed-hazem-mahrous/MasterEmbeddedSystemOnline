/*
 * uart.h
 *
 * Created: 9/9/2023 7:36:24 PM
 *  Author: Mohamed
 */ 


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include "../utils.h"


void UART_Init(void);

void UART_Send(uint8_t data);
uint8_t UART_Receive(void);

void UART_Send_Number(uint32_t Num);
uint32_t UART_Receive_Number(void);

void UART_SendString(char* str);
void UART_ReceiveString(char *Buffer);

uint8_t UART_Receive_Periodec_Check(uint8_t* pdata);

void UART_Send_No_Block(uint8_t data);
uint8_t UART_Recieve_No_Block(void);

void UART_RX_Interrupt_Enable();
void UART_RX_Interrupt_Disable();

void UART_TX_Interrupt_Enable();
void UART_TX_Interrupt_Disable();

void UART_ASYCH_Send_String(uint8_t *str);

ISR(USART_TXC_vect);

#endif /* UART_H_ */