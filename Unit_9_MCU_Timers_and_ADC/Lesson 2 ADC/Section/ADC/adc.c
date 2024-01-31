/*
 * adc.c
 *
 *  Created on: Jan 31, 2024
 *      Author: Mahmoud
 */
#include "adc.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>


void ADC_Init(ADC_Fref_type vref, ADC_Scaler_type scaler)
{
	// Vref
	switch(vref)
	{
		case VREF_AREF:
		Reset_Bit(ADMUX, REFS0);
		Reset_Bit(ADMUX, REFS1);
		break;

		case VREF_AVCC:
		Reset_Bit(ADMUX, REFS0);
		Set_Bit(ADMUX, REFS1);
		break;

		case VREF_256:
		Set_Bit(ADMUX, REFS0);
		Set_Bit(ADMUX, REFS1);
		break;
	}

	// PreScaller
	ADCSRA &= 0xF8;
	ADCSRA |= scaler;
	Set_Bit(ADCSRA, ADEN);
}




int ADC_Read(ADC_Channel_type ch)
{
	// Select channel
	ADMUX &= 0xE0;
	ADMUX |= ch;

	// Start Conversion
	Set_Bit(ADCSRA, ADSC);

	while(Read_Bit(ADCSRA, ADSC));
	return ADC;
}















