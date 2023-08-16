/*
 * lifo.c
 *
 *  Created on: Aug 12, 2023
 *      Author: Mohamed
 */
#include "lifo.h"


LIFO_STATUS_EN LIFO_INIT(LIFO_Buf_st *STACK, element_type *Buf, element_type Length) {
    if (STACK == NULL || Buf == NULL || Length == 0) {
        printf("STACK Init Failed, Make Sure That The Arguments Are Right \n");
        return LIFO_NULL;
    }

    STACK->base = Buf;
    STACK->head = Buf;
    STACK->length = Length;
    STACK->count = 0;
    printf("STACK Init is Done \n\n");
    return LIFO_No_Error;
}




LIFO_STATUS_EN LIFO_ADD(LIFO_Buf_st* STACK, element_type item){
	if(STACK->base == NULL || STACK->head == NULL){
		printf("STACK Doesn't Exist, Please Enter Valid LIFO\n\n");
		return LIFO_NULL;
	}


	if(STACK->count == STACK->length){
		printf("STACK Is Full, Failed To Add Number %d \n", item);
		return LIFO_FULL;
	}

    *(STACK->head) = item;
    STACK->head++;
    STACK->count++;
    printf("Adding Number %u in Stack is Done\n", item);
	return LIFO_No_Error;
}


LIFO_STATUS_EN LIFO_POP(LIFO_Buf_st* STACK, element_type* item){
	if(STACK->base == NULL || STACK->head == NULL){
		printf("STACK Doesn't Exist, Please Enter Valid LIFO\n\n");
		return LIFO_NULL;
	}
	if(STACK->count == 0){
		printf("STACK Is Empty\n");
		return LIFO_EMPTY;
	}

    STACK->head--;
     *item = *(STACK->head);
    STACK->count--;
    printf("Popping Number %d from Stack is Done\n", *item);
	return LIFO_No_Error;
}




LIFO_STATUS_EN LIFO_GET_TOP(LIFO_Buf_st* STACK, element_type* item){
	if(STACK->base == NULL || STACK->head == NULL){
		printf("STACK Doesn't Exist, Please Enter Valid LIFO\n\n");
		return LIFO_NULL;
	}
	if(STACK->count == 0){
		printf("STACK Is Empty, There is no Top\n");
		return LIFO_EMPTY;
	}
	*item = *(STACK->head - 1);
	printf("The Top of The Stack is %d\n", *item);
	return LIFO_No_Error;
}



LIFO_STATUS_EN LIFO_IS_FULL(LIFO_Buf_st* STACK){
	if(STACK->base == NULL || STACK->head == NULL){
		printf("STACK Doesn't Exist, Please Enter Valid LIFO\n\n");
		return LIFO_NULL;
	}
	if(STACK->count == STACK->length){
		printf("STACK Is Full\n");
		return LIFO_FULL;
	}
	else{
		printf("STACK Is Not Full\n");
		return LIFO_NOT_FULL;
	}
}


LIFO_STATUS_EN LIFO_IS_EMPTY(LIFO_Buf_st* STACK){
	if(STACK->base == NULL || STACK->head == NULL){
		printf("STACK Doesn't Exist, Please Enter Valid LIFO\n\n");
		return LIFO_NULL;
	}
	if(STACK->count == 0){
		printf("STACK Is Empty\n");
		return LIFO_EMPTY;
	}
	else{
		printf("STACK Is Not Empty\n");
		return LIFO_NOT_EMPTY;
	}
}


void LIFO_PRINT(LIFO_Buf_st* STACK){
	if(STACK->base == NULL || STACK->head == NULL){
		printf("STACK Doesn't Exist, Please Enter Valid LIFO\n\n");
	}
	printf("STACK Contains:");
	for(int i = 0; i < STACK->count; i++){
		printf(" %d", *(STACK->base + i));
	}
}



void LIFO_CLEAR(LIFO_Buf_st* STACK){
	if(STACK->base == NULL || STACK->head == NULL){
		printf("STACK Doesn't Exist, Please Enter Valid LIFO\n\n");
	}
	for(int i = 0; i < STACK->count; i++){
		*(STACK->base + i) = 0;
	}
	STACK->head = STACK->base;
	STACK->count = 0;
	printf("STACK Clearing Is Done, The STACK Is Empty Now\n");
}
