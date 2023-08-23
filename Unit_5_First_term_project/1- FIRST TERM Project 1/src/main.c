/*
 * main.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Mohamed
 */

#include "driver.h"
#include "Pressure_Sensor_Driver.h"
#include "Alarm_Actuator_Driver.h"
#include "Alarm_Monitor.h"

void setup(){
	GPIO_INITIALIZATION();
	pSensor_INIT();
	AM_INIT();
	AA_INIT();
	// states
	pSensor_state = STATE(pSensore_Reading);
	AM_state = STATE(AM_Alarm_Waiting);
	AA_state = STATE(AA_Alarm_off);
}

int Pressure_Threshold = 20;

void Set_Pressure_Val(int pVal){
	if (pVal > Pressure_Threshold){
		High_Pressure_Detect();
	}
}
int main()
{
	setup();
	while (1)
	{
		pSensor_state();
		AM_state();
		AA_state();
	}
	return 0;
}