/*
 * Alarm_Monitor.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Mohamed
 */


#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

#include "driver.h"
#include "state.h"

//Define States
enum{
	AM_Alarm_off,
    AM_Alarm_on,
    AM_Alarm_Waiting
}AM_State_ID;

// Declare States Functions Alarm monitor
STATE_define(AM_Alarm_off);
STATE_define(AM_Alarm_on);
STATE_define(AM_Alarm_Waiting);

void AM_INIT();

// State Pointer to function
extern void (*AM_state)();

#endif /* ALARM_MONITOR_H_ */
