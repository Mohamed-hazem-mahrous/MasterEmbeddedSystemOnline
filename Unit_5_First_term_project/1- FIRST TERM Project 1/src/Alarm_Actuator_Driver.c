/*
 * Alarm_Actuator_Driver.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Mohamed
 */

#include "Alarm_Actuator_Driver.h"

// State Pointer to function
void (*AA_state)();

void AA_INIT(){
    // printf("Alarm Monitor Init is done");
}

void Start_Alarm(){
    AA_state = STATE(AA_Alarm_on);
}

void Stop_Alarm(){
    AA_state = STATE(AA_Alarm_off);
}

STATE_define(AA_Alarm_on){
    // State name
    AA_State_ID = AA_Alarm_on;

    // alarm on
    Set_Alarm_actuator(0);
}

STATE_define(AA_Alarm_off){
    // State name
    AA_State_ID = AA_Alarm_off;

    // alarm off
    Set_Alarm_actuator(1);
}