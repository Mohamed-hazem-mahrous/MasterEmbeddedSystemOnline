/*
 * Pressure_Sensor_Driver.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Mohamed
 */

#include "Pressure_Sensor_Driver.h"

// Variables
int pVal = 0;
int pSensor_Pull_Timer = 100;

// State Pointer to function
void (*pSensor_state)();

void pSensor_INIT(){
    // printf("Pressure Sensor Init is done");
}
STATE_define(pSensore_Reading){
    // State Name
    pSensor_State_ID = pSensore_Reading;
    // Get Pressure Value
    pVal = getPressureVal();
    // Set pressure value
    Set_Pressure_Val(pVal);
    // call the waiting state
    pSensor_state = STATE(pSensore_Waiting);
}
STATE_define(pSensore_Waiting){
    // State Name
    pSensor_State_ID = pSensore_Waiting;

    // Delay the sensor before reading again
    Delay(pSensor_Pull_Timer);

    // call the reading state
    pSensor_state = STATE(pSensore_Reading);
}