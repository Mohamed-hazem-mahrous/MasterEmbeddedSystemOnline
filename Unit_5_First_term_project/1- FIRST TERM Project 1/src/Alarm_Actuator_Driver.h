/*
 * Alarm_Actuator_Driver.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Mohamed
 */


#ifndef ALARM_ACTUATOR_DRIVER_H_
#define ALARM_ACTUATOR_DRIVER_H_

#include "driver.h"
#include "state.h"

//Define States
enum{
	AA_Alarm_off,
    AA_Alarm_on
}AA_State_ID;

// Declare States Functions Alarm actuator
STATE_define(AA_Alarm_off);
STATE_define(AA_Alarm_on);

void AA_INIT();

// State Pointer to function
extern void (*AA_state)();

#endif /* ALARM_ACTUATOR_DRIVER_H_ */
