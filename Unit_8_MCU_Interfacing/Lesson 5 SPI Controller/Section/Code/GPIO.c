#include "GPIO.h"



void MCAL_GPIO_Init (GPIO_typedef* GPIOX , GPIO_PIN_CONFIG * pinconfig){
	
	if(pinconfig->GPIO_Mode == GPIO_MODE_INPUT_FLOAT){
		GPIOX->DDR &= ~(pinconfig->GPIO_Pin_Number);
		GPIOX->PORT &= ~(pinconfig->GPIO_Pin_Number);
	}
	else if(pinconfig->GPIO_Mode == GPIO_MODE_INPUT_PU){
		GPIOX->DDR &= ~(pinconfig->GPIO_Pin_Number);
		GPIOX->PORT |= (pinconfig->GPIO_Pin_Number);
	}
	else{
		GPIOX->DDR |= (pinconfig->GPIO_Pin_Number);
		GPIOX->PORT &= ~(pinconfig->GPIO_Pin_Number);
	}
}


void MCAL_GPIO_DeInit (GPIO_typedef* GPIOX ){
	GPIOX->DDR = 0x00;
	GPIOX->PORT = 0x00;
}

uint8_t MCAL_GPIO_ReadPin(GPIO_typedef* GPIOX , uint8_t PinNumber){
	if (GPIOX->PIN & PinNumber){
		return 1;
	}
	else{
		return 0;
	}
}


uint8_t MCAL_GPIO_ReadPort(GPIO_typedef* GPIOX ){
	return GPIOX->PIN;
}

void MCAL_GPIO_WritePin(GPIO_typedef* GPIOX , uint8_t PinNumber, uint8_t value){
	if(value){
		GPIOX->PORT |= PinNumber;
	}
	else{
		GPIOX->PORT &= ~PinNumber;
	}
}

void MCAL_GPIO_WritePort(GPIO_typedef* GPIOX , uint8_t value){
	GPIOX->PORT = value;
}

void MCAL_GPIO_togglePin(GPIO_typedef* GPIOX , uint8_t PinNumber){
	GPIOX->PORT ^= PinNumber;
}
