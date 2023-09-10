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





#endif /* UART_H_ */