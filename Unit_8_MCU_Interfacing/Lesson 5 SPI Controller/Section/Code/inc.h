
#ifndef ATMEGA32_H_
#define ATMEGA32_H_

#define FR_CPU 8000000
//-----------------------
//Includes
//-----------------------

#include "stdlib.h"
#include "stdint.h"

//-----------------------------
//Base addresses for Peripherals
//-----------------------------

#define GPIOA_BASE                 0x39
#define GPIOB_BASE                 0x36
#define GPIOC_BASE                 0x33
#define GPIOD_BASE                 0x30

#define USART_BASE                 0x29

#define SPI_BASE                   0x2D 

#define UCSRC					*((volatile uint8_t*)0x40)  //USART

#define SREG					*((volatile uint8_t*)0x5F)  // Global Interrupt Enable (bit number 7 )

#define GICR					*((volatile uint8_t*)0x5B)  //  Interrupt Enable (bit number 7 and 6 and 5 )



//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral registers
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*-*-*-

typedef struct{
	uint8_t   PIN;
	uint8_t   DDR;
	uint8_t   PORT;
	
}GPIO_typedef;


//-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: USART
//-*-*-*-*-*-*-*-*-*-*-*-*-*-

typedef struct{
	uint8_t   UBRRL;
	uint8_t   UCSRB;
	uint8_t   UCSRA;
	uint8_t   UDR;
	
}USART_typedef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: SPI
//-*-*-*-*-*-*-*-*-*-*-*-*-*-


typedef struct{
	uint8_t   SPCR;
	uint8_t   SPSR;
	uint8_t   SPDR;
	
}SPI_typedef;



//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

#define GPIOA		((GPIO_typedef*)GPIOA_BASE)
#define GPIOB		((GPIO_typedef*)GPIOB_BASE)
#define GPIOC		((GPIO_typedef*)GPIOC_BASE)
#define GPIOD		((GPIO_typedef*)GPIOD_BASE)


#define USART		((USART_typedef*)USART_BASE)

#define SPI		    ((SPI_typedef*)SPI_BASE)



//-*-*-*-*-*-*-*-*-*-*-*-
//EXTI Enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define EXTI_GLOBAL_Enable()							(SREG |=1<<7)
#define EXTI_INT1_Enable()								(GICR |=1<<7)
#define EXTI_INT0_Enable()								(GICR |=1<<6)
#define EXTI_INT2_Enable()								(GICR |=1<<5)

//-*-*-*-*-*-*-*-*-*-*-*-
//EXTI Disable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define EXTI_GLOBAL_Disable()							(SREG &=~(1<<7))
#define EXTI_INT1_Disable()								(GICR &=~(1<<7))
#define EXTI_INT0_Disable()								(GICR &=~(1<<6))
#define EXTI_INT2_Disable()								(GICR &=~(1<<5))

#endif /* ATMEGA32_H_ */