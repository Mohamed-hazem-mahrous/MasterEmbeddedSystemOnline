#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define SET_BIT(address, bit) address |= (1<<bit)
#define RESET_BIT(address, bit) address &= ~(1<<bit)
#define TOGGLE_BIT(address, bit) address ^= (1<<bit)
#define READ_BIT(address, bit) ((address & (1<<bit))>>bit)

int main(){
	//	Set INT0 any logical change
	SET_BIT(MCUCR, 0);
	RESET_BIT(MCUCR, 1);

	//	set INT1 as rising edge
	SET_BIT(MCUCR, 2);
	SET_BIT(MCUCR, 3);

	//	set INT2 as Faling edge
	SET_BIT(MCUSR, 6);

	//	Enable Interrupts
	SET_BIT(GICR, 5);
	SET_BIT(GICR, 6);
	SET_BIT(GICR, 7);

	SET_BIT(DDRD, 5);
	SET_BIT(DDRD, 6);
	SET_BIT(DDRD, 7);

	sei();

	while(1)
	{
		RESET_BIT(PORTD, 5);
		RESET_BIT(PORTD, 6);
		RESET_BIT(PORTD, 7);
	}


	return 0;
}


ISR(INT0_VECT)
{
	SET_BIT(PORTD, 5);
	_delay_ms(1000);
}



ISR(INT1_VECT)
{
	SET_BIT(PORTD, 6);
	_delay_ms(1000);
}


ISR(INT2_VECT)
{
	SET_BIT(PORTD, 7);
	_delay_ms(1000);
}
