/*
 * fifo.h
 *
 *  Created on: Aug 12, 2023
 *      Author: Mohamed
 */

#ifndef FIFO_H_
#define FIFO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



// User Configuration ==================
// Select Element Type (uint8_t, uint16_t, uint32_t, ......)
#define element_type uint32_t


typedef struct {
	element_type length;
	element_type count;
	element_type* head;
	element_type* tail;
	element_type* base;
} FIFO_Queue_st;

typedef enum {
    FIFO_No_Error,
    FIFO_FULL,
    FIFO_NOT_FULL,
    FIFO_EMPTY,
    FIFO_NOT_EMPTY,
    FIFO_NULL
} FIFO_STATUS_EN;

FIFO_STATUS_EN FIFO_INIT(FIFO_Queue_st* QUEUE, element_type* Buf, element_type Length);
FIFO_STATUS_EN FIFO_ENQUEUE(FIFO_Queue_st* QUEUE, element_type item);
FIFO_STATUS_EN FIFO_DEQUEUE(FIFO_Queue_st* QUEUE, element_type* item);
FIFO_STATUS_EN FIFO_PEEK_FRONT(FIFO_Queue_st* QUEUE, element_type* item);
FIFO_STATUS_EN FIFO_IS_FULL(FIFO_Queue_st* QUEUE);
FIFO_STATUS_EN FIFO_IS_EMPTY(FIFO_Queue_st* QUEUE);
void FIFO_PRINT(FIFO_Queue_st* QUEUE);
void FIFO_CLEAR(FIFO_Queue_st* QUEUE);

#endif /* FIFO_H_ */
