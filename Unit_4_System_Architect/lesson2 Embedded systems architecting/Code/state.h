/*
 * state.h
 *
 *  Created on: Aug 21, 2023
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
void US_Set_Distance(int d);
void DC_Set_Speed(int s);


#endif /* STATE_H_ */
