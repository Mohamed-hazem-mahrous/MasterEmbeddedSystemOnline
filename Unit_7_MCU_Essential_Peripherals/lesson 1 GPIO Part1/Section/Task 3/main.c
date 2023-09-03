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

// static unsigned char SegmentNumber[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};


int main(void)
{
	DDRC = 0xFF;
	unsigned char i, j;

    while (1) 
    {
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				PORTC = 0b1011|(i<<4);
				_delay_ms(50);
				PORTC = 0b0111|(j<<4);
				_delay_ms(50);
			}
			_delay_ms(500);
		}
    }
}

