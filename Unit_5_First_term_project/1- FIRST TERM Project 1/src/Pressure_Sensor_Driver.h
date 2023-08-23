/*
 * Pressure_Sensor_Driver.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Mohamed
 */


#ifndef PRESSURE_SENSOR_DRIVER_H_
#define PRESSURE_SENSOR_DRIVER_H_

#include "driver.h"
#include "state.h"

//Define States
enum{
	pSensore_Waiting,
	pSensore_Reading
}pSensor_State_ID;



// Declare States Functions pressure sensor
STATE_define(pSensore_Waiting);
STATE_define(pSensore_Reading);

void pSensor_INIT();

// State Pointer to function
extern void (*pSensor_state)();



#endif /* PRESSURE_SENSOR_DRIVER_H_ */
