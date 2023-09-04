/*
 * Stm32_F103C6_GPIO_Driver.c
 *
 *  Created on: Sep 4, 2023
 *      Author: Mohamed Hazem
 */

#include "Incs/Stm32_F103C6_GPIO_Driver.h"







/**================================================================
 * @Fn			- MCAL_GPIO_INIT
 * @brief 		- Initializes the GPIOx PIN according to the specified parameters in the PinConfig
 * @param [in] 	- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in]	- PinConfig pointer to the GPIO_PinConfig_t structure that contains the configuration information
 * 				  for the specified PIN
 * @retval 		- none
 * Note			- none
 */
void MCAL_GPIO_INIT(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig)
{
	/*
	    Choose the correct control register based on the pin number
	    CRL for pin(0 >> 7)
	    CRH for pin(8 >> 15)
	 */
	volatile uint32_t *configregister = NULL;
	uint8_t shift;
	uint8_t Pin_config = 0;


	configregister = (PinConfig->GPIO_PinNumber < GPIO_PIN_8) ? &GPIOx->CRL : &GPIOx->CRH;

	shift = ((PinConfig->GPIO_PinNumber % 8) * 4);

	*(configregister) &= ~(0xF << shift);

	if(PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_AF_PP || PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_AF_OD || PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_OD || PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_PP)
	{
		Pin_config = ((((PinConfig->GPIO_Mode - 4)<<2) | (PinConfig->GPIO_Output_Speed)) & 0x0F);
	}
	else
	{
		if(PinConfig->GPIO_Mode == GPIO_MODE_INPUT_FLo ||PinConfig->GPIO_Mode == GPIO_MODE_Analog)
		{
			Pin_config = ((((PinConfig->GPIO_Mode) << 2) | 0x00) & 0x0F);

		}
		else if(PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_AF_INPUT )
		{
			Pin_config = ((((GPIO_MODE_INPUT_FLo) << 2) | 0x00) & 0x0F);
		}
		else
		{
			Pin_config = ((((GPIO_MODE_INPUT_PU) << 2) | 0x00) & 0x0F);
			if(PinConfig->GPIO_Mode == GPIO_MODE_INPUT_PU)
			{
				GPIOx->ODR |= PinConfig->GPIO_PinNumber;
			}
			else
			{
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
			}
		}

	}
	*(configregister) |= ((Pin_config)<<shift);

}







/**================================================================
 * @Fn			- MCAL_GPIO_DEINIT
 * @brief 		- Deinitialization function that resets the entire port.
 * @param [in] 	- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
 * @retval 		- none
 * Note			- none
 */
void MCAL_GPIO_DEINIT(GPIO_TypeDef *GPIOx)
{
	//	GPIOx->BRR 	= 0x00000000;
	//	GPIOx->BSRR = 0x00000000;
	//	GPIOx->CRH 	= 0x44444444;
	//	GPIOx->CRL 	= 0x44444444;
	//	GPIOx->LCKR = 0x00000000;
	//	GPIOx->ODR = 0x00000000;

	if(GPIOx == GPIOA)
	{
		RCC->APB2RSTR |= (1<<2);
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if(GPIOx == GPIOB)
	{
		RCC->APB2RSTR |= (1<<3);
		RCC->APB2RSTR &= ~(1<<3);
	}
	else if(GPIOx == GPIOC)
	{
		RCC->APB2RSTR |= (1<<4);
		RCC->APB2RSTR &= ~(1<<4);
	}
	else if(GPIOx == GPIOD)
	{
		RCC->APB2RSTR |= (1<<5);
		RCC->APB2RSTR &= ~(1<<5);
	}
	else if(GPIOx == GPIOE)
	{
		RCC->APB2RSTR |= (1<<6);
		RCC->APB2RSTR &= ~(1<<6);
	}

}









/**================================================================
 * @Fn			- MCAL_GPIO_ReadPIN
 * @brief 		- Reads the status of GPIOx PINy.
 * @param [in] 	- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in]	- The number of the pin to be read must be a value of @ref GPIO_PIN_define.
 * @retval 		- Current pin status which can be a value of @ref GPIO_PIN_STATUS.
 * Note			- none
 */
uint8_t MCAL_GPIO_ReadPIN(GPIO_TypeDef *GPIOx, uint8_t PinNumber)
{
	uint8_t BitStatus;

	if(((GPIOx->IDR) & PinNumber) != (uint32_t)GPIO_PIN_RESET)
	{
		BitStatus = GPIO_PIN_SET;
	}else{
		BitStatus = GPIO_PIN_RESET;
	}
	return BitStatus;
}






/**================================================================
 * @Fn			- MCAL_GPIO_ReadPORT
 * @brief 		- Reads the status of the entire GPIOx.
 * @param [in] 	- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
 * @retval 		- Current port value.
 * Note			- none
 */
uint16_t MCAL_GPIO_ReadPORT(GPIO_TypeDef* GPIOx)
{
	uint16_t port_val;

	port_val = (uint16_t)GPIOx->IDR;

	return port_val;
}






/**================================================================
 * @Fn			- MCAL_GPIO_WritePIN
 * @brief 		- Write a value on GPIOx PINy.
 * @param [in] 	- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in]	- The number of the pin to be read must be a value of @ref GPIO_PIN_define.
 * @param [in]	- The pin value to be must be a vale of @ref GPIO_PIN_STATUS.
 * @retval 		- Current port value.
 * Note			- none
 */
void MCAL_GPIO_WritePIN(GPIO_TypeDef *GPIOx, uint8_t PinNumber, uint8_t value)
{
	if(value != GPIO_PIN_RESET)
	{
		GPIOx->BSRR = (uint32_t)PinNumber;
	}else{
		GPIOx->BRR = (uint32_t)PinNumber;
	}
}






/**================================================================
 * @Fn			- MCAL_GPIO_WritePORT
 * @brief 		- Write the status of the entire GPIOx.
 * @param [in] 	- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in]	- The pin value to be must be a vale of @ref GPIO_PIN_STATUS.
 * @retval 		- none
 * Note			- none
 */
void MCAL_GPIO_WritePORT(GPIO_TypeDef *GPIOx, uint8_t value)
{
	GPIOx->ODR = (uint32_t)value;
}







/**================================================================
 * @Fn			- MCAL_GPIO_TogglePIN
 * @brief 		- Toggle the value of GPIOx PINy.
 * @param [in] 	- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in]	- The number of the pin to be read must be a value of @ref GPIO_PIN_define.
 * @retval 		- none
 * Note			- none
 */
void MCAL_GPIO_TogglePIN(GPIO_TypeDef *GPIOx, uint8_t PinNumber)
{
	GPIOx->ODR ^= (PinNumber);
}






/**================================================================
 * @Fn			- MCAL_GPIO_LockPIN
 * @brief 		- Lock the configuration settings of GPIOx PINy.
 * @param [in] 	- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in]	- The number of the pin to be read must be a value of @ref GPIO_PIN_define.
 * @retval 		- Lock status which will be a value of @ref GPIO_RETURN_LOCK.
 * Note			- none
 */
uint8_t MCAL_GPIO_LockPIN(GPIO_TypeDef *GPIOx, uint8_t PinNumber)
{
	/*Bit 16 LCKK[16]: Lock key
	    This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	    0: Port configuration lock key not active
	    1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	    LOCK key writing sequence:
	    Write 1
	    Write 0
	    Write 1
	    Read 0
	    Read 1 (this read is optional but confirms that the lock is active)
	    Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	 */

	volatile uint32_t tmp = 1<<16;

	tmp |= PinNumber;

//	write 1
	GPIOx->LCKR = tmp;

//	write 0
	GPIOx->LCKR = PinNumber;

//	write 1
	GPIOx->LCKR = tmp;

//	read 0
	tmp = GPIOx->LCKR;

//	read 1
	if((uint32_t)(GPIOx->LCKR & 1<<16))
	{
		return GPIO_RETURN_LOCK_ENABLED;
	}else{
		return GPIO_RETURN_LOCK_ERROR;
	}
}







