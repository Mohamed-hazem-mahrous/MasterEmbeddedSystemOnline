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

typedef volatile unsigned int vuint32_t;

#include "stdint.h"

// RCC Rsgisters
#define RCC_BASE 			0x40021000
#define RCC_APB2ENR 		*((vuint32_t*) (RCC_BASE + 0x18))
#define RCC_IOPAEN	(1<<2)
#define RCC_IOPBEN	(1<<3)


// GPIO A Registers
#define GPIOA_BASE 			0x40010800
#define GPIOA_CRL 			*((vuint32_t*) (GPIOA_BASE + 0x00))
#define GPIOA_CRH 			*((vuint32_t*) (GPIOA_BASE + 0x04))
#define GPIOA_IDR 			*((vuint32_t*) (GPIOA_BASE + 0x08))
#define GPIOA_ODR 			*((vuint32_t*) (GPIOA_BASE + 0x0C))
#define GPIOA_Pin13	(1UL<<13)


// GPIO B Registers
#define GPIOB_BASE 			0x40010C00
#define GPIOB_CRL 			*((vuint32_t*) (GPIOB_BASE + 0x00))
#define GPIOB_CRH 			*((vuint32_t*) (GPIOB_BASE + 0x04))
#define GPIOB_IDR 			*((vuint32_t*) (GPIOB_BASE + 0x08))
#define GPIOB_ODR 			*((vuint32_t*) (GPIOB_BASE + 0x0C))
#define GPIOB_Pin13	(1UL<<13)






void Clock_INIT(){
	//	Enable Clock GPIO A
	RCC_APB2ENR |= RCC_IOPAEN;

	//	Enable Clock GPIO B
	RCC_APB2ENR |= RCC_IOPBEN;
}

void GPIO_INIT(){
	//	Pin 1 Port B Output mode, max speed 2 MHz
	GPIOB_CRL &= 0xffffff0f;
	GPIOB_CRL |= 0x00000020;

	//	Pin 13 Port B Output mode, max speed 2 MHz
	GPIOB_CRH &= 0xff0fffff;
	GPIOB_CRH |= 0x00200000;


	//	Pin 1 Port A Floating input (CNFy , MODEy) --> (Floating input,  Input mode) --> (01, 00) --> 4
	GPIOA_CRL &= 0xffffff0f;
	GPIOA_CRL |= 0x00000040;

	//	Pin 13 Port A Floating input (CNFy , MODEy) --> (Floating input,  Input mode) --> (01, 00) --> 4
	GPIOA_CRH &= 0xff0fffff;
	GPIOA_CRH |= 0x00400000;
}

void wait_ms(vuint32_t time){
	vuint32_t i, j;
	for(i = 0; i< time ; i++)
		for(j = 0; j < 255 ; j++);
}


int main(void)
{
	Clock_INIT();
	GPIO_INIT();


	while(1){
		if (((GPIOA_IDR & (1<<1)) >> 1) == 0){
			GPIOB_ODR ^= 1<<1;
			while (((GPIOA_IDR & (1<<1)) >> 1) == 0);
		}
		if (((GPIOA_IDR & (1<<13)) >> 13) == 1){
			GPIOB_ODR ^= 1<<13;
		}
		wait_ms(1);
	}

	return 0;
}







