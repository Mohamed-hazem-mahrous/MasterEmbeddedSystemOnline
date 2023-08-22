/*
 * DC.h
 *
 *  Created on: Aug 21, 2023
 *      Author: Mohamed
 */

#ifndef DC_H_
#define DC_H_



#include "state.h"

//Define States
enum{
	DC_idle,
	DC_busy
}DC_State_ID;


// Declare States Functions CA
STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_Init();


// State Pointer to function
extern void (*DC_state)();


#endif /* DC_H_ */
