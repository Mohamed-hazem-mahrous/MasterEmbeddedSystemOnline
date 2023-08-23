/*
 * state.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Mohamed
 */


#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>

//Automatic State Function Generator
#define STATE_define(_stateFUNC_) void ST_##_stateFUNC_()
#define STATE(_stateFUNC_) ST_##_stateFUNC_


// States Connection
void Set_Pressure_Val(int pVal);
void High_Pressure_Detect();
void Start_Alarm();
void Stop_Alarm();


#endif /* STATE_H_ */
