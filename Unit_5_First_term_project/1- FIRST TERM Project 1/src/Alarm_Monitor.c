/*
 * Alarm_Monitor.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Mohamed
 */

#include "Alarm_Monitor.h"
// Variables
int Alarm_Delay_Duration= 60;

// State Pointer to function
void (*AM_state)();

void AM_INIT(){
    // printf("Alarm Monitor Init is done");
}
void High_Pressure_Detect(){
    AM_state = STATE(AM_Alarm_on);
}
STATE_define(AM_Alarm_on){
    // State Name
    AM_State_ID = AM_Alarm_on;

    // Start tha alarm
    Start_Alarm();
    // call the waiting state
    AM_state = STATE(AM_Alarm_Waiting);
}
STATE_define(AM_Alarm_off){
    // State Name
    AM_State_ID = AM_Alarm_off;

    //stop the alarm
    Stop_Alarm();

    // call the waiting state
    AM_state = STATE(AM_Alarm_off);
}


STATE_define(AM_Alarm_Waiting){
    // State Name
    AM_State_ID = AM_Alarm_Waiting;

    // Delay the sensor before reading again
    Delay(Alarm_Delay_Duration);

    // call the alarm off state
    AM_state = STATE(AM_Alarm_off);
}