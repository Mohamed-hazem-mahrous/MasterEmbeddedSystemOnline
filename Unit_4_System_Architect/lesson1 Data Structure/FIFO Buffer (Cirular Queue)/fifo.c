/*
 * fifo.c
 *
 *  Created on: Aug 12, 2023
 *      Author: Mohamed
 */

#include "fifo.h"

FIFO_STATUS_EN FIFO_INIT(FIFO_Queue_st* QUEUE, element_type* Buf, element_type Length) {
    if (QUEUE == NULL || Buf == NULL || Length == 0) {
        printf("Queue Init Failed, Make Sure That The Arguments Are Right \n");
        return FIFO_NULL;
    }

    QUEUE->base = Buf;
    QUEUE->head = Buf;
    QUEUE->tail = Buf;
    QUEUE->length = Length;
    QUEUE->count = 0;
    printf("Queue Init is Done \n\n");
    return FIFO_No_Error;
}

FIFO_STATUS_EN FIFO_ENQUEUE(FIFO_Queue_st* QUEUE, element_type item) {
    if (QUEUE->base == NULL || QUEUE->head == NULL || QUEUE->tail == NULL) {
        printf("Queue Doesn't Exist, Please Enter Valid FIFO\n\n");
        return FIFO_NULL;
    }

	if(QUEUE->head == QUEUE->base + QUEUE->length ){
		QUEUE->head = QUEUE->base;
	}
    *(QUEUE->head) = item;
    QUEUE->head++;

    if(QUEUE->count != QUEUE->length){
    	QUEUE->count++;
        printf("Enqueueing Number %u in Queue is Done\n", item);
        return FIFO_No_Error;
    }

    printf("Enqueueing Number %u in Queue is Done\n", item);
            return FIFO_No_Error;

}




FIFO_STATUS_EN FIFO_DEQUEUE(FIFO_Queue_st* QUEUE, element_type* item) {
    if (QUEUE->base == NULL || QUEUE->head == NULL || QUEUE->tail == NULL) {
        printf("Queue Doesn't Exist, Please Enter Valid FIFO\n\n");
        return FIFO_NULL;
    }

    if (QUEUE->count == 0) {
        printf("Queue Is Empty\n");
        return FIFO_EMPTY;
    }
	if(QUEUE->tail == QUEUE->base + QUEUE->length ){
		QUEUE->tail = QUEUE->base;
	}

    *item = *(QUEUE->tail);
    *(QUEUE->tail) = 0;
    QUEUE->tail++;
    QUEUE->count--;
    printf("Dequeuing Number %u from Queue is Done\n", *item);
    return FIFO_No_Error;
}

FIFO_STATUS_EN FIFO_PEEK_FRONT(FIFO_Queue_st* QUEUE, element_type* item) {
    if (QUEUE->base == NULL || QUEUE->head == NULL || QUEUE->tail == NULL) {
        printf("Queue Doesn't Exist, Please Enter Valid FIFO\n\n");
        return FIFO_NULL;
    }

    if (QUEUE->count == 0) {
        printf("Queue Is Empty, There is no Front\n");
        return FIFO_EMPTY;
    }

    *item = *(QUEUE->tail);
    printf("The Front of The Queue is %u\n", *item);
    return FIFO_No_Error;
}

FIFO_STATUS_EN FIFO_IS_FULL(FIFO_Queue_st* QUEUE) {
    if (QUEUE->base == NULL || QUEUE->head == NULL || QUEUE->tail == NULL) {
        printf("Queue Doesn't Exist, Please Enter Valid FIFO\n\n");
        return FIFO_NULL;
    }

    if (QUEUE->count == QUEUE->length) {
        printf("Queue Is Full\n");
        return FIFO_FULL;
    } else {
        printf("Queue Is Not Full\n");
        return FIFO_NOT_FULL;
    }
}

FIFO_STATUS_EN FIFO_IS_EMPTY(FIFO_Queue_st* QUEUE) {
    if (QUEUE->base == NULL || QUEUE->head == NULL || QUEUE->tail == NULL) {
        printf("Queue Doesn't Exist, Please Enter Valid FIFO\n\n");
        return FIFO_NULL;
    }

    if (QUEUE->count == 0) {
        printf("Queue Is Empty\n");
        return FIFO_EMPTY;
    } else {
        printf("Queue Is Not Empty\n");
        return FIFO_NOT_EMPTY;
    }
}

void FIFO_PRINT(FIFO_Queue_st* QUEUE) {
    if (QUEUE->base == NULL || QUEUE->head == NULL || QUEUE->tail == NULL) {
        printf("Queue Doesn't Exist, Please Enter Valid FIFO\n\n");
        return;
    }
    element_type* temp = QUEUE->tail;

    printf("Queue Contains:");

	for(int i = 0; i < QUEUE->count; i++){
		if (temp >= QUEUE->base + QUEUE->length){
			temp = QUEUE->base;
			printf(" %d", *temp);
			temp++;
		}else{
			printf(" %d", *temp);
			temp++;
		}
	}
    printf("\n");
}


void FIFO_CLEAR(FIFO_Queue_st* QUEUE){
	if(QUEUE->base == NULL || QUEUE->head == NULL || QUEUE->tail == NULL){
		printf("Queue Doesn't Exist, Please Enter Valid FIFO\n\n");
	}
	for(int i = 0; i < QUEUE->length; i++){
		*(QUEUE->base + i) = 0;
	}
	QUEUE->head = QUEUE->base;
	QUEUE->tail = QUEUE->base;
	QUEUE->count = 0;
	printf("Queue Clearing Is Done, The Queue Is Empty Now\n");
}
