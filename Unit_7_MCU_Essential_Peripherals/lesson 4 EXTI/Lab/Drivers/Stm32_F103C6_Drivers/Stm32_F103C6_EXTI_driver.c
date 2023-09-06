#include "Stm32_F103C6_EXTI_driver.h"
#include "Stm32_F103C6_gpio_driver.h"
#include "stm32f103x6.h"


//-----------------------------
//Generic Macors
//-----------------------------
#define AFIO_GPIO_EXTI_Mapping(x)	(	(x==GPIOA)?0:\
		(x==GPIOB)?1:\
				(x==GPIOC)?2:\
						(x==GPIOD)?3:0	 )







//-----------------------------
//Generic Variables
//-----------------------------
void(* GP_IRQ_CallBACK[15])(void);











//-----------------------------
//Generic Function
//-----------------------------
void Enable_NVIC(uint16_t IRQ)
{
	switch(IRQ){
		case EXTI0:
			NVIC_IRQ6_EXTI0_Enable;
			break;
		case EXTI1:
			NVIC_IRQ7_EXTI1_Enable;
			break;
		case EXTI2:
			NVIC_IRQ8_EXTI2_Enable;
			break;
		case EXTI3:
			NVIC_IRQ9_EXTI3_Enable;
			break;
		case EXTI4:
			NVIC_IRQ10_EXTI4_Enable;
			break;
		case EXTI5:
		case EXTI6:
		case EXTI7:
		case EXTI8:
		case EXTI9:
			NVIC_IRQ23_EXTI5_9_Enable;
			break;
		case EXTI10:
		case EXTI11:
		case EXTI12:
		case EXTI13:
		case EXTI14:
		case EXTI15:
			NVIC_IRQ40_EXTI10_15_Enable;
			break;
		}
}
void Disable_NVIC(uint16_t IRQ)
{
	switch(IRQ)
		{
		case EXTI0:
			NVIC_IRQ6_EXTI0_Disable;
			break;

		case EXTI1:
			NVIC_IRQ7_EXTI1_Disable;
			break;

		case EXTI2:
			NVIC_IRQ8_EXTI2_Disable;
			break;

		case EXTI3:
			NVIC_IRQ9_EXTI3_Disable;
			break;

		case EXTI4:
			NVIC_IRQ10_EXTI4_Disable;
			break;

		case EXTI5:
		case EXTI6:
		case EXTI7:
		case EXTI8:
		case EXTI9:
			NVIC_IRQ23_EXTI5_9_Disable;
			break;

		case EXTI10:
		case EXTI11:
		case EXTI12:
		case EXTI13:
		case EXTI14:
		case EXTI15:
			NVIC_IRQ40_EXTI10_15_Disable;
			break;
		}
}










void Update_EXTI(EXTI_PinConfig_t* EXTI_Config)
{
	//	1- Configure the GPIO to be AF Input -> floating input
	GPIO_PinConfig_t GPIO_PINCFG;
	GPIO_PINCFG.GPIO_PinNumber = EXTI_Config->EXTI_PIN.GPIO_PIN;
	GPIO_PINCFG.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_Port, &GPIO_PINCFG);
	//	===========================================================================================================================


	//	2- Update AFIO to Route between the EXTI line with port A,B,C,D
	uint8_t AFIO_EXTICR_Index = EXTI_Config->EXTI_PIN.EXTI_LineNumber / 4;
	uint8_t AFIO_EXTICR_Position = (EXTI_Config->EXTI_PIN.EXTI_LineNumber % 4) * 4;
	//	clear the four bits
	AFIO->EXTICR[AFIO_EXTICR_Index] &= ~(0xF << AFIO_EXTICR_Position);
	AFIO->EXTICR[AFIO_EXTICR_Index] |= ((AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXTI_PIN.GPIO_Port) & 0xFFFF) << AFIO_EXTICR_Position);
	//	===========================================================================================================================


	//	3- Update Rising or Falling Trigger
	EXTI->RSTR &= ~(1<<EXTI_Config->EXTI_PIN.EXTI_LineNumber);
	EXTI->FTSR &= ~(1<<EXTI_Config->EXTI_PIN.EXTI_LineNumber);

	if(EXTI_Config->Trigger_Case == EXTI_Trigger_Rising)
	{
		EXTI->RSTR |= (1<<EXTI_Config->EXTI_PIN.EXTI_LineNumber);
	}
	else if(EXTI_Config->Trigger_Case == EXTI_Trigger_Falling)
	{
		EXTI->FTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_LineNumber);
	}
	else if(EXTI_Config->Trigger_Case == EXTI_Trigger_Both)
	{
		EXTI->RSTR |= (1<<EXTI_Config->EXTI_PIN.EXTI_LineNumber);
		EXTI->FTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_LineNumber);
	}
	//	===========================================================================================================================



	//	4-Update IRQ Handling CallBack
	GP_IRQ_CallBACK[EXTI_Config->EXTI_PIN.EXTI_LineNumber] = EXTI_Config->P_IRQ_CallBACK;

	//	===========================================================================================================================



	//	5-Enable/Disable IRQ
	if(EXTI_Config->IRQ_EN == EXTI_IRQ_ENABLE)
	{
		EXTI->IMR |= 1<<EXTI_Config->EXTI_PIN.EXTI_LineNumber;
		Enable_NVIC(EXTI_Config->EXTI_PIN.EXTI_LineNumber);
	}

	else
	{
		EXTI->IMR &= ~(1<<EXTI_Config->EXTI_PIN.EXTI_LineNumber);
		Disable_NVIC(EXTI_Config->EXTI_PIN.EXTI_LineNumber);
	}
}









/**
 * ===============================================
 * APIs Supported by "MCAL EXTI DRIVER"
 * ===============================================
 */


/**================================================================
 * @Fn			-MCAL_EXTI_GPIO_INIT
 * @brief 		-Initializes The EXTI From Specific GPIO PIN and specify the MASK/Trigger Condition and IRQ Call Back
 * @param [in] 	-EXTI_Config set by @ref EXTI_Define, EXTI_Trigger_Define and EXTI_IRQ_Define
 * @retval 		-none
 * Note			-Stm32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 				 But LQFP48 Package has only GPIO A,B,PART of C/D exported as external PINS from the MCU
 */
void MCAL_EXTI_GPIO_INIT(EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}






/**================================================================
 * @Fn			-MCAL_EXTI_GPIO_DEINIT
 * @brief 		-Reset EXTI Registers and NVIC corresponding IRQ Mask
 * @retval 		-none
 * Note			-none
 */
void MCAL_EXTI_GPIO_DEINIT(void)
{
	//	clear all the EXTI pins
	EXTI->EMR 		= 0x00000000;
	EXTI->IMR 		= 0x00000000;
	EXTI->FTSR 		= 0x00000000;
	EXTI->RSTR 		= 0x00000000;
	EXTI->SWIER 	= 0x00000000;
	EXTI->PR 		= 0xFFFFFFFF;

	//	Disable EXTI IQR From NVIC
	NVIC_IRQ6_EXTI0_Disable;
	NVIC_IRQ7_EXTI1_Disable;
	NVIC_IRQ8_EXTI2_Disable;
	NVIC_IRQ9_EXTI3_Disable;
	NVIC_IRQ10_EXTI4_Disable;
	NVIC_IRQ23_EXTI5_9_Disable;
	NVIC_IRQ40_EXTI10_15_Disable;

}





void MCAL_EXTI_GPIO_UPDATE(EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}










/**
 * ===============================================
 * ISR Functions
 * ===============================================
 */
void EXTI0_IRQHandler(void){
	//clear the corresponding pending bit
	EXTI->PR = 1<<0;
	//callback function
	GP_IRQ_CallBACK[0]();
}


void EXTI1_IRQHandler(void){
	//clear the corresponding pending bit
	EXTI->PR = 1<<1;
	//callback function
	GP_IRQ_CallBACK[1]();
}

void EXTI2_IRQHandler(void){
	//clear the corresponding pending bit
	EXTI->PR = 1<<2;
	//callback function
	GP_IRQ_CallBACK[2]();
}

void EXTI3_IRQHandler(void){
	//clear the corresponding pending bit
	EXTI->PR = 1<<3;
	//callback function
	GP_IRQ_CallBACK[3]();
}



void EXTI4_IRQHandler(void){
	//clear the corresponding pending bit
	EXTI->PR = 1<<4;
	//callback function
	GP_IRQ_CallBACK[4]();
}



void EXTI9_5_IRQHandler(void){

	if(EXTI->PR & 1<<5) { EXTI->PR  = 1<<5;   GP_IRQ_CallBACK[5](); }
	if(EXTI->PR & 1<<6) { EXTI->PR  = 1<<6;   GP_IRQ_CallBACK[6](); }
	if(EXTI->PR & 1<<7) { EXTI->PR  = 1<<7;   GP_IRQ_CallBACK[7](); }
	if(EXTI->PR & 1<<8) { EXTI->PR  = 1<<8;   GP_IRQ_CallBACK[8](); }
	if(EXTI->PR & 1<<9) { EXTI->PR  = 1<<9;   GP_IRQ_CallBACK[9](); }
}



void EXTI15_10_IRQHandler(void){

	if( EXTI->PR & 1<<10 ) { EXTI->PR |= 1<<10; GP_IRQ_CallBACK[10](); }
	if( EXTI->PR & 1<<11 ) { EXTI->PR |= 1<<11; GP_IRQ_CallBACK[11](); }
	if( EXTI->PR & 1<<12 ) { EXTI->PR |= 1<<12; GP_IRQ_CallBACK[12](); }
	if( EXTI->PR & 1<<13 ) { EXTI->PR |= 1<<13; GP_IRQ_CallBACK[13](); }
	if( EXTI->PR & 1<<14 ) { EXTI->PR |= 1<<14; GP_IRQ_CallBACK[14](); }
	if( EXTI->PR & 1<<14 ) { EXTI->PR |= 1<<15; GP_IRQ_CallBACK[15](); }
}













































