/*
 * GccApplication1.c
 *
 * Created: 9/2/2023 6:03:57 PM
 * Author : Mohamed
 */ 

#include <avr/io.h>
#define  F_CPU 8000000UL
#include <util/delay.h>



int main(void)
{
	DDRA = 0b11111111;
	PORTA = 0;
	int i;
    while (1) 
    {
		for (i= 0; i<8; i++)
		{
			PORTA |= (1<<i);
			_delay_ms(250);
		}
		for (i= 7; i>=0; i--)
		{
			PORTA &= ~(1<<i);
			_delay_ms(250);
		}
    }
}

