/*
 ============================================================================
 Name        : LIFO_LIB.c
 Author      : Mohamed Hazem
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "lifo.h"

#define LIFO_LEN 5

LIFO_Buf_st LIFO_UART, LIFO_TEST;

unsigned int UART_BUF[LIFO_LEN];

int main(void) {

	unsigned int i, temp;

	unsigned int UART_BUF_TEST[1];
	LIFO_INIT(&LIFO_TEST, UART_BUF_TEST, 1);
	printf("=========== STACK Adding ========\n");
	LIFO_ADD(&LIFO_TEST, 5);
	printf("=========== Get Top ========\n");
	LIFO_GET_TOP(&LIFO_TEST, &i);
	printf("=========== Is Full ========\n");
	LIFO_IS_FULL(&LIFO_TEST);
	printf("=========== Is Empty ========\n");
	LIFO_IS_EMPTY(&LIFO_TEST);
	printf("=========== Clear Stack ========\n");
	LIFO_CLEAR(&LIFO_TEST);
	printf("=========== Is Empty ========\n");
	LIFO_IS_EMPTY(&LIFO_TEST);

	printf("\n\n=========== New STack ===========\n");
	LIFO_INIT(&LIFO_UART, UART_BUF, LIFO_LEN);
    printf("=========== STACK Writing ========\n");
    for (i = 0; i < LIFO_LEN +2; i++) {
    	LIFO_ADD(&LIFO_UART, i);
    }

    printf("=========== STACK Printing ========\n");
    LIFO_PRINT(&LIFO_UART);

    printf("\n=========== STACK Reading ========\n");
    for (i = 0; i < LIFO_LEN + 2; i++) {
    	LIFO_POP(&LIFO_UART, &temp);
    }








	return EXIT_SUCCESS;
}
