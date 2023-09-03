/*
 * GccApplication1.c
 *
 * Created: 9/2/2023 6:03:57 PM
 * Author : Mohamed
 */ 

#include <avr/io.h>
#define  F_CPU 8000000UL
#include <util/delay.h>
#include "Utils.h"



int main(void)
{
	// 	port a is output as DDRA = 1
	DDRA = 0b11111111;
	PORTA = 0b00000000;
	// Set_Bit(DDRA, 0);
	// Reset_Bit(PORTA, 0);
	
	
	// port c 1 is input    as DDRC = 0,  PORTC = 1   to open led
	Reset_Bit(DDRC, 0);
	Set_Bit(PORTC, 0);
	
	// port c 2 is input    as DDRC = 0,  PORTC = 1  to close led
	Reset_Bit(DDRC, 1);
	Set_Bit(PORTC, 1);
	
	char count_up = 0;
	char count_down = 0;
    while (1) 
    {
		if (Read_Bit(PINC, 0) == 0)
		{
			Set_Bit(PORTA, count_up);
			count_up++;
			
			if (count_up ==8)
			{
				count_up = 0;
			}
			
			_delay_ms(250);
		}
		
		if (Read_Bit(PINC, 1) == 0)
		{
			Reset_Bit(PORTA, count_down);
			count_down++;
			
			if (count_down ==8)
			{
				count_down = 0;
			}
			
			_delay_ms(250);
		}
    }
}

