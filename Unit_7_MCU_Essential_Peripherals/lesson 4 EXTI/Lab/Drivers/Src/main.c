/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#include "stm32f103x6.h"
#include "Stm32_F103C6_gpio_driver.h"
#include "Stm32_F103C6_EXTI_driver.h"
#include "lcd.h"
#include "keypad.h"

uint32_t IRQ_Flag = 0;

void wait_ms(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++);
}


void EXTI9_CallBack(void)
{
	IRQ_Flag = 1;
	LCD_WRITE_STRING("IRQ EXTI9 is Happened _|-  ");
	wait_ms(1000);
}



int main(void) {

	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();

	LCD_INIT();
	LCD_clear_screen();


	EXTI_PinConfig_t EXTI_CFG;
	EXTI_CFG.EXTI_PIN = EXTI9PB9;
	EXTI_CFG.Trigger_Case = EXTI_Trigger_Rising;
	EXTI_CFG.P_IRQ_CallBACK = EXTI9_CallBack;
	EXTI_CFG.IRQ_EN = EXTI_IRQ_ENABLE;

	MCAL_EXTI_GPIO_INIT(&EXTI_CFG);

	IRQ_Flag = 1;

	while(1)
	{
		if(IRQ_Flag)
		{
			LCD_clear_screen();
			IRQ_Flag = 0;
		}


	}

}

