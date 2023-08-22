/*
 * CA.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Mohamed
 */

#include "CA.h"



// Variables
int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;


// State Pointer to function
void (*CA_state)();


void US_Set_Distance(int d){
	CA_distance = d;
	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_State_Waiting)) : (CA_state = STATE(CA_State_Driving));

	printf("\nUS --------distance = %d-----------> CA\n", CA_distance);
}




STATE_define(CA_State_Waiting)
{
	//	state name
	CA_State_ID = CA_State_Waiting;
	printf("CA_Waiting State: distance = %d , speed = %d\n", CA_distance, CA_speed);

	//	state action
	CA_speed = 0;
	DC_Set_Speed(CA_speed);
}


STATE_define(CA_State_Driving)
{
	//	state name
	CA_State_ID = CA_State_Waiting;
	printf("CA_Driving State: distance = %d , speed = %d\n", CA_distance, CA_speed);

	//	state action
	CA_speed = 30;
	DC_Set_Speed(CA_speed);
}
