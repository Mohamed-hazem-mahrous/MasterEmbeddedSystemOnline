/*
 * US.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Mohamed
 */

#include "US.h"

// Variables
int US_distance = 0;


// State Pointer to function
void (*US_state)();
int US_Get_distance(int l, int r, int count);



void US_Init(){
//	init US driver
	printf("US_Init\n");
}



STATE_define(US_busy)
{
	//	state name
	US_State_ID = US_busy;

	//	event check
	//	get the distance
	US_distance = US_Get_distance(45, 55, 1);

	printf("US_Busy State: distance = %d\n", US_distance);

	US_Set_Distance(US_distance);

	US_state = STATE(US_busy);
}






int US_Get_distance(int l, int r, int count){
	int i;
	for(i = 0; i < count; i++){
		int rand_num = (rand() % (r - l + 1)) + 1;
		return rand_num;
	}

	return 1;
}


