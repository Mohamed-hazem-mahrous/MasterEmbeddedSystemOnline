/*
 * stm32f103x8_SPI_driver.C
 *
 *  Created on: Sep 27, 2023
 *      Author: Mahmoud
 */

#include "stm32f103x8_SPI_driver.h"


/*
 * ===============================================
 * Generic Macros
 * ===============================================
 */

#define SPI1_Index    0
#define SPI2_Index    1

/*
 * ===============================================
 * Generic Variables
 * ===============================================
 */

SPI_Config_t* Global_SPI_Config[2] = {NULL,NULL} ;

/*
 * ===============================================
 * Generic Functions definitions
 * ===============================================
 */

/**================================================================
 * @Fn            - MCAL_SPI_init
 * @brief         - Initialize SPI according to specified parameters
 * @param [in]    - SPIx: where x can be 1 - 2 (depending on device used) to select the spi peripheral
 * @param [in]    - SPI_Config: all SPI configuration
 * @retval        - none
 * Note           - none
 */
void MCAL_SPI_init(SPI_TypeDef* SPIx , SPI_Config_t* SPI_Config)
{
	//Safety for registers
	uint16_t CR1_temp=0 , CR2_temp=0 ;

	if(SPIx == SPI1)
	{
		Global_SPI_Config[SPI1_Index] = SPI_Config;
		RCC_SPI1_CLK_EN;
	}
	else
	{
		Global_SPI_Config[SPI2_Index] = SPI_Config;
		RCC_SPI2_CLK_EN;
	}

	//Enable SPI CR1.Bit6
	CR1_temp |= (1<<6);

	//Master or Slave
	CR1_temp |= SPI_Config->Device_Mode;

	//SPI communication mode
	CR1_temp |= SPI_Config->Communication_Mode;

	//SPI frame format
	CR1_temp |= SPI_Config->Frame_Format;

	//SPI data size
	CR1_temp |= SPI_Config->Data_Size;

	//SPI Polarity
	CR1_temp |= SPI_Config->CLKPolarity;

	//SPI CLOCK PHASE
	CR1_temp |= SPI_Config->CLKPhase;

	//==============NSS==============

	if(SPI_Config->NSS == SPI_NSS_SS_Output_Enable)
	{
		CR2_temp |= SPI_Config->NSS;
	}
	else if (SPI_Config->NSS == SPI_NSS_SS_Output_Disable)
	{
		CR2_temp &= SPI_Config->NSS;
	}
	else
	{
		CR1_temp |= SPI_Config->NSS;
	}

	//SPI baud rate prescaler
	CR1_temp |= SPI_Config->SPI_BAUDRATE_PRESCALER;

	//SPI IRQ
	if(SPI_Config->IRQ_Enable != SPI_IRQ_Enable_NONE)
	{
		CR1_temp |= SPI_Config->IRQ_Enable;

		if(SPIx == SPI1)
			{
				NVIC_IRQ35_SPI1_Enable;
			}
		else
			{
				NVIC_IRQ36_SPI2_Enable;
			}
	}

	SPIx->SPI_CR1 = CR1_temp;
	SPIx->SPI_CR2 = CR2_temp;

}

/**================================================================
 * @Fn            - MCAL_SPI_Deinit
 * @brief         - DeInitialize SPI according to specified parameters
 * @param [in]    - SPIx: where x can be 1 - 2 (depending on device used) to select the spi peripheral
 * @retval        - none
 * Note           - none
 */
void MCAL_SPI_Deinit(SPI_TypeDef* SPIx)
{

	if(SPIx == SPI1)
		{
			NVIC_IRQ35_SPI1_Disable;
			RCC_SPI1_Reset;
		}
		else
		{
			NVIC_IRQ36_SPI2_Disable;
			RCC_SPI1_Reset;
		}

}

//assuming full duplex mode

/**================================================================
 * @Fn            - MCAL_SPI_Send_Data
 * @brief         - Send buffer to SPI
 * @param [in]    - SPIx: where x can be 1 - 2 (depending on device used) to select the USART peripheral
 * @param [in]    - p_TxBuffer: pointer to data buffer
 * @param [in]    - Polling: Enable polling or disable it
 * @retval        - none
 * Note           - none
 */
void MCAL_SPI_Send_Data(SPI_TypeDef* SPIx , uint16_t* p_TxBuffer , SPI_Polling_mechanism Polling)
{
	if(Polling == Polling_ENABLE)
		while(((SPIx->SPI_SR >>1)&1) == 0);    //Transmit buffer is empty

	SPIx->SPI_DR = *p_TxBuffer;
}

/**================================================================
 * @Fn            - MCAL_SPI_Receive_Data
 * @brief         - Receive buffer from SPI
 * @param [in]    - SPIx: where x can be 1 - 2 (depending on device used) to select the USART peripheral
 * @param [in]    - p_TxBuffer: pointer to data buffer
 * @param [in]    - Polling: Enable polling or disable it
 * @retval        - none
 * Note           - none
 */
void MCAL_SPI_Receive_Data(SPI_TypeDef* SPIx , uint16_t* p_TxBuffer , SPI_Polling_mechanism Polling)
{
	if(Polling == Polling_ENABLE)
		while(((SPIx->SPI_SR >>0)&1) == 0);    //receive buffer is full

	*p_TxBuffer = SPIx->SPI_DR;
}


/**================================================================
 * @Fn            - MCAL_SPI_SendReceive_Data
 * @brief         - Send and receive buffer by SPI
 * @param [in]    - SPIx: where x can be 1 - 2 (depending on device used) to select the USART peripheral
 * @param [in]    - p_TxBuffer: pointer to data buffer
 * @param [in]    - Polling: Enable polling or disable it
 * @retval        - none
 * Note           - none
 */
void MCAL_SPI_SendReceive_Data(SPI_TypeDef* SPIx , uint16_t* p_TxBuffer , SPI_Polling_mechanism Polling)
{
	if(Polling == Polling_ENABLE)
	{
		while(((SPIx->SPI_SR >>1)&1) == 0);
	}
	SPIx->SPI_DR = *p_TxBuffer;


	if(Polling == Polling_ENABLE)
	{
		while(((SPIx->SPI_SR >>0)&1) == 0);    //receive buffer is full
	}
	*p_TxBuffer = SPIx->SPI_DR;
}


/**================================================================
 * @Fn            - MCAL_SPI_GPIO_SetPins
 * @brief         - Set GPIO pins for SPI
 * @param [in]    - SPIx: where x can be 1 - 2 (depending on device used) to select the USART peripheral
 * @retval        - none
 * Note           - none
 */
void MCAL_SPI_GPIO_SetPins(SPI_TypeDef* SPIx)
{
	GPIO_PinConfig_t PinCfg;

	if(SPIx == SPI1)
	{

		//PA4 - NSS
		//PA5 - CLK
		//PA6 - MISO
		//PA7 - MOSI

		if(Global_SPI_Config[SPI1_Index]->Device_Mode == SPI_DEVICE_Mode_Master)
		{
			switch(Global_SPI_Config[SPI1_Index]->NSS)
			{
			case SPI_NSS_SS_Output_Disable:
				//hardware master input floating
				PinCfg.GPIO_PinNumber = GPIO_PIN_4;
				PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOA , &PinCfg);
				break;

			case SPI_NSS_SS_Output_Enable:
				//hardware master output floating
				PinCfg.GPIO_PinNumber = GPIO_PIN_4;
				PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
				PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
				MCAL_GPIO_Init(GPIOA , &PinCfg);
				break;
			}

			//CLK for master
			PinCfg.GPIO_PinNumber = GPIO_PIN_5;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA , &PinCfg );


			//MISO for master (assuming full duplex)
			PinCfg.GPIO_PinNumber = GPIO_PIN_6;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA , &PinCfg );

			//MOSI for master
			PinCfg.GPIO_PinNumber = GPIO_PIN_7;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA , &PinCfg );
		}
		else    //slave
		{
			if(Global_SPI_Config[SPI1_Index]->NSS == SPI_NSS_Hard_Slave)
			{
				//hardware slave input floating
				PinCfg.GPIO_PinNumber = GPIO_PIN_4;
				PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOA , &PinCfg );
			}

			//CLK for slave
			PinCfg.GPIO_PinNumber = GPIO_PIN_5;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA , &PinCfg );

			//MISO for slave (assuming full duplex & point to point)
			PinCfg.GPIO_PinNumber = GPIO_PIN_6;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA , &PinCfg );

			//MOSI for slave
			PinCfg.GPIO_PinNumber = GPIO_PIN_7;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA , &PinCfg );

		}

	}
	else if(SPIx == SPI2)
	{
		//PB12 - NSS

		//PB13 - CLK

		//PB14 - MISO

		//PB15 - MOSI


		if(Global_SPI_Config[SPI2_Index]->Device_Mode == SPI_DEVICE_Mode_Master)
		{
			switch(Global_SPI_Config[SPI1_Index]->NSS)
			{
			case SPI_NSS_SS_Output_Disable:
				//hardware master input floating
				PinCfg.GPIO_PinNumber = GPIO_PIN_12;
				PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOB , &PinCfg );
				break;

			case SPI_NSS_SS_Output_Enable:
				//hardware master output floating
				PinCfg.GPIO_PinNumber = GPIO_PIN_12;
				PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
				PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
				MCAL_GPIO_Init(GPIOB , &PinCfg );
				break;
			}

			//CLK for master
			PinCfg.GPIO_PinNumber = GPIO_PIN_13;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB , &PinCfg );


			//MISO for master (assuming full duplex)
			PinCfg.GPIO_PinNumber = GPIO_PIN_14;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB , &PinCfg );

			//MOSI for master
			PinCfg.GPIO_PinNumber = GPIO_PIN_15;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB , &PinCfg );
		}
		else    //slave
		{
			if(Global_SPI_Config[SPI2_Index]->NSS == SPI_NSS_Hard_Slave)
			{
				//hardware slave input floating
				PinCfg.GPIO_PinNumber = GPIO_PIN_12;
				PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOB , &PinCfg );
			}

			//CLK for slave
			PinCfg.GPIO_PinNumber = GPIO_PIN_13;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB , &PinCfg );

			//MISO for slave (assuming full duplex & point to point)
			PinCfg.GPIO_PinNumber = GPIO_PIN_14;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB , &PinCfg );

			//MOSI for slave
			PinCfg.GPIO_PinNumber = GPIO_PIN_15;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB , &PinCfg );

		}

	}
}


//IRQ

void SPI1_IRQHandler()    /* SPI1 global interrupt */
{
	struct S_IRQ_SRC irq_src;

	irq_src.TXE  = ((SPI1->SPI_SR >>1)&1);
	irq_src.RXNE = ((SPI1->SPI_SR >>0)&1);
	irq_src.ERRI = ((SPI1->SPI_SR >>4)&1);

	Global_SPI_Config[SPI1_Index]->P_IRQ_CallBack(irq_src);
}

void SPI2_IRQHandler()           			/* SPI2 global interrupt  */
{

	struct S_IRQ_SRC irq_src;

	irq_src.TXE  = ((SPI2->SPI_SR >>1)&1);
	irq_src.RXNE = ((SPI2->SPI_SR >>0)&1);
	irq_src.ERRI = ((SPI2->SPI_SR >>4)&1);

	Global_SPI_Config[SPI2_Index]->P_IRQ_CallBack(irq_src);

}
