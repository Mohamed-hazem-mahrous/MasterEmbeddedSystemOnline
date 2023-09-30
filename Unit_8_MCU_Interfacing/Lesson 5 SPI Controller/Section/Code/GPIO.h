
#ifndef GPIO_H_
#define GPIO_H_


#include "stdlib.h"
#include "stdint.h"
#include "inc.h"

typedef struct{
	uint8_t   PIN;
	uint8_t   DDR;
	uint8_t   PORT;
	
}GPIO_typedef;

//-----------------------------
//Config structures
//-----------------------------

typedef struct{
	
	uint8_t     GPIO_Pin_Number;        //Specifies the GPIO Pins to be configured
										//This parameter must be set based on @ref GPIO_PINS_define
										
	uint8_t     GPIO_Mode;              //Specifies the Operating mode for the selected pins
	                                    //This parameter can be a value of @ref GPIO_MODE_define
}GPIO_PIN_CONFIG;


//--------------------------------------------------------
//Macros Configuration References
//--------------------------------------------------------

//@ref GPIO_PINS_define

#define  GPIO_PIN0     (uint8_t)(0x01)
#define  GPIO_PIN1     (uint8_t)(0x02)
#define  GPIO_PIN2     (uint8_t)(0x04)
#define  GPIO_PIN3     (uint8_t)(0x08)
#define  GPIO_PIN4     (uint8_t)(0x10)
#define  GPIO_PIN5     (uint8_t)(0x20)
#define  GPIO_PIN6     (uint8_t)(0x40)
#define  GPIO_PIN7     (uint8_t)(0x80)


//@ ref  GPIO_MODE_define

#define GPIO_MODE_INPUT_FLOAT		0
#define GPIO_MODE_INPUT_PU			1
#define GPIO_MODE_OUTPUT			2


/*
 * ===============================================
 * APIs Supported by "MCAL GPIO DRIVER"
 * ===============================================
 */

void MCAL_GPIO_Init (GPIO_typedef* GPIOX , GPIO_PIN_CONFIG * pinconfig);
void MCAL_GPIO_DeInit (GPIO_typedef* GPIOX );

uint8_t MCAL_GPIO_ReadPin(GPIO_typedef* GPIOX , uint8_t PinNumber);
uint8_t MCAL_GPIO_ReadPort(GPIO_typedef* GPIOX );

void MCAL_GPIO_WritePin(GPIO_typedef* GPIOX , uint8_t PinNumber, uint8_t value);
void MCAL_GPIO_WritePort(GPIO_typedef* GPIOX , uint8_t value);

void MCAL_GPIO_togglePin(GPIO_typedef* GPIOX , uint8_t PinNumber);


#endif /* GPIOH_ */