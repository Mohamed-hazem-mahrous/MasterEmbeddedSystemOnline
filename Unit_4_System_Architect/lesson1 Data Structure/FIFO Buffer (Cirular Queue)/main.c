/*
 ============================================================================
 Name        : FIFO_Buffer.c
 Author      : Mohamed Hazem
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "stdio.h"
#include "stdint.h"
#include "fifo.h"

#define QUEUE_LEN 5

FIFO_Queue_st QUEUE_UART, QUEUE_TEST;

unsigned int UART_BUF[QUEUE_LEN];


int main(void)
{

	unsigned int i, temp;

	unsigned int UART_BUF_TEST[1];
	FIFO_INIT(&QUEUE_TEST, UART_BUF_TEST, 1);
	printf("=========== QUEUE Enqueueing ========\n");
	FIFO_ENQUEUE(&QUEUE_TEST, 5);
	printf("=========== Peek Front ========\n");
	FIFO_PEEK_FRONT(&QUEUE_TEST, &i);
	printf("=========== Is Full ========\n");
	FIFO_IS_FULL(&QUEUE_TEST);
	printf("=========== Is Empty ========\n");
	FIFO_IS_EMPTY(&QUEUE_TEST);

	printf("\n\n=========== New QUEUE ===========\n");
	FIFO_INIT(&QUEUE_UART, UART_BUF, QUEUE_LEN);
	printf("=========== QUEUE Enqueueing ========\n");
	for (i = 0; i < QUEUE_LEN + 2; i++) {
	    FIFO_ENQUEUE(&QUEUE_UART, i);
	}

	printf("=========== QUEUE Printing ========\n");
	FIFO_PRINT(&QUEUE_UART);

	printf("\n=========== QUEUE Dequeueing ========\n");
	for (i = 0; i < QUEUE_LEN + 2; i++) {
	    FIFO_DEQUEUE(&QUEUE_UART, &temp);
	}


	return 0;
}
