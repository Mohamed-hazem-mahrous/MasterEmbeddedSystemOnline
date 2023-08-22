/*
 * US.h
 *
 *  Created on: Aug 21, 2023
 *      Author: Mohamed
 */

#ifndef US_H_
#define US_H_


#include "state.h"

//Define States
enum{
	US_busy
}US_State_ID;


// Declare States Functions CA
STATE_define(US_busy);

void US_Init();


// State Pointer to function
extern void (*US_state)();



#endif /* US_H_ */
