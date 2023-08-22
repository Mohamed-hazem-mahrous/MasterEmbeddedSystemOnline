/*
 * main.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Mohamed
 */

#include "CA.h"
#include "US.h"
#include "DC.h"

void setup()
{
	US_Init();
	DC_Init();
	CA_state = STATE(CA_State_Waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);
}

int main(){

	volatile int d;
	setup();

	while(1)
	{
		US_state();
		CA_state();
		DC_state();

//		delay
		for(d=0; d<1000000; d++);
	}


	return 0;
}

