/*
 * lifo.h
 *
 *  Created on: Aug 12, 2023
 *      Author: Mohamed
 */

#ifndef LIFO_H_
#define LIFO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


// User Configuration ==================
// Select Element Type (uint8_t, uint16_t, uint32_t, ......)
#define element_type uint32_t


typedef struct{
	element_type length;
	element_type count;
	element_type* head;
	element_type* base;
} LIFO_Buf_st;

typedef enum{
	LIFO_No_Error,
	LIFO_FULL,
	LIFO_NOT_FULL,
	LIFO_EMPTY,
	LIFO_NOT_EMPTY,
	LIFO_NULL
} LIFO_STATUS_EN;

LIFO_STATUS_EN LIFO_INIT(LIFO_Buf_st* STACK, element_type* Buf, element_type Length);
LIFO_STATUS_EN LIFO_ADD(LIFO_Buf_st* STACK, element_type item);
LIFO_STATUS_EN LIFO_POP(LIFO_Buf_st* STACK, element_type* item);
LIFO_STATUS_EN LIFO_GET_TOP(LIFO_Buf_st* STACK, element_type* item);
LIFO_STATUS_EN LIFO_IS_FULL(LIFO_Buf_st* STACK);
LIFO_STATUS_EN LIFO_IS_EMPTY(LIFO_Buf_st* STACK);
void LIFO_PRINT(LIFO_Buf_st* STACK);
void LIFO_CLEAR(LIFO_Buf_st* STACK);





#endif /* LIFO_H_ */
