/*
 * adc.h
 *
 *  Created on: Jan 31, 2024
 *      Author: Mahmoud
 */

#ifndef ADC_H_
#define ADC_H_

#include "UTILS.h"

#define VoltRef 	5000
#define res			1024

typedef enum{
		VREF_AREF,
		VREF_AVCC,
		VREF_256
}ADC_Fref_type;


typedef enum{
		ADC_SCALER_2 = 0,
		ADC_SCALER_4 = 2,
		ADC_SCALER_8,
		ADC_SCALER_16,
		ADC_SCALER_32,
		ADC_SCALER_64,
		ADC_SCALER_128,
}ADC_Scaler_type;


typedef enum{
		CH_0 = 0,
		CH_1,
		CH_2,
		CH_3,
		CH_4,
		CH_5,
		CH_6,
		CH_7,
}ADC_Channel_type;

void ADC_Init(ADC_Fref_type vref, ADC_Scaler_type scaler);

int ADC_Read(ADC_Channel_type ch);







#endif /* ADC_H_ */
