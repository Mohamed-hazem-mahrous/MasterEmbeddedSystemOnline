/*
 * DC.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Mohamed
 */
#include "DC.h"



// Variables
int DC_speed = 0;


// State Pointer to function
void (*DC_state)();


void DC_Init(){

	printf("DC_Motor init\n");
}


void DC_Set_Speed(int s){
	DC_speed = s;
	DC_state = STATE(DC_busy);
	printf("\nCA --------speed = %d-----------> DC\n", DC_speed);
}

STATE_define(DC_idle)
{
	//	state name
	DC_State_ID = DC_idle;

	//	state action
	printf("DC_Idle State: speed = %d\n", DC_speed);
}


STATE_define(DC_busy)
{
	//	state name
	DC_State_ID = DC_busy;

	printf("DC_Busy State: speed = %d\n", DC_speed);
	DC_state = STATE(DC_idle);
}























