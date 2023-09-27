/*
 * stm32f103x8_SPI_driver.h
 *
 *  Created on: Sep 27, 2023
 *      Author: Mahmoud
 */

#ifndef INC_STM32F103X8_SPI_DRIVER_H_
#define INC_STM32F103X8_SPI_DRIVER_H_

//includes
#include "STM32F103x8.h"
#include "stm32f103x8_gpio_driver.h"
#include "stm32f103x8_RCC_driver.h"


struct S_IRQ_SRC
{
	uint8_t TXE:1; 				//Tx Buffer Empty Interrupt
	uint8_t RXNE:1; 			//Rx Buffer Not Empty Interrupt
	uint8_t ERRI:1; 			//Error Interrupt
	uint8_t Reserved:5;
};


// Configuration structure
typedef struct
{
	uint16_t Device_Mode;  				// Specifies the SPI operation mode @ref SPI_Device_Mode
	uint16_t Communication_Mode;		// Specifies the SPI bidirection mode state @ref SPI_Communication_Mode
	uint16_t Frame_Format;				// Specifies LSB or MSB @ref SPI_Frame_Format
	uint16_t Data_Size;					// @ref SPI_Data_Size
	uint16_t CLKPolarity;				// @ref SPI_CLKPolarity
	uint16_t CLKPhase;					// @ref SPI_CLKPhase

	uint16_t NSS;						// SPecifies whether the NSS signal is managed by Hardware or software
										// using SSI bitenable @ref SPI_NSS

	uint16_t SPI_BAUDRATE_PRESCALER;	// specifies the baudrate prescaler value which will be used to configure
										// the transmit and receive SCK clock @ref SPI_BAUDRATE_PRESCALER

	uint16_t IRQ_Enable;				//@ref SPI_IRQ_Enable

	void(* P_IRQ_CallBack)(struct S_IRQ_SRC IRQ_SRC);		//Set the C Function() which will be called once the IRQ  Happen


}SPI_Config_t;


//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref SPI_Device_Mode
#define SPI_DEVICE_Mode_Slave    (0x00000000U)
#define SPI_DEVICE_Mode_Master   (0x1<<2)       //CR1.MSTR


//@ref SPI_Communication_Mode
#define SPI_Communication_2_Lines_Full_Duplex    (0x00000000U)
#define SPI_Communication_2_Lines_Receive_Only   (0x1<<10)			     //CR1.RXONLY
#define SPI_Communication_1_Line_Receive_Only    (0x1<<15)			     //CR1.BIDIMODE
#define SPI_Communication_1_Line_Transmit_Only   ((0x1<<15) | (0x1<<14)) //CR1.BIDIMODE & //CR1.BIDIOE


//@ref SPI_Frame_Format
#define SPI_MSB_First           (0x00000000U)
#define SPI_LSB_First           (0x1<<7)

//@ref SPI_Data_Size
#define SPI_Size_8bit           (0x00000000U)
#define SPI_Size_16bit          (0x1<<11)


//@ref SPI_CLKPolarity
#define SPI_Clock_Polarity_Low_Idle 		(0x00000000U)
#define SPI_Clock_Polarity_High_Idle 		(0x1<<1)


//@ref SPI_CLKPhase
#define SPI_Clock_First_Edge_Capture	    (0x00000000U)
#define SPI_Clock_Second_Edge_Capture		(0x1<<0)


//@ref SPI_NSS

//Hardware
#define SPI_NSS_Hard_Slave 		  (0x00000000U)
#define SPI_NSS_SS_Output_Enable  (0x1<<2)		  //CR2.SSOE
#define SPI_NSS_SS_Output_Disable ~(0x1<<2)      //CR2.SSOE

//Software
#define SPI_NSS_SW_Reset    	  (0x1<<9)
#define SPI_NSS_SW_Set            ((0x1<<9) | (0x1<<8))


//@ref SPI_BAUDRATE_PRESCALER
#define SPI_Prescaler_2 	      (0x00000000U)
#define SPI_Prescaler_4 		  (0b001 << 3)
#define SPI_Prescaler_8 		  (0b010 << 3)
#define SPI_Prescaler_16 		  (0b011 << 3)
#define SPI_Prescaler_32 		  (0b100 << 3)
#define SPI_Prescaler_64          (0b101 << 3)
#define SPI_Prescaler_128         (0b110 << 3)
#define SPI_Prescaler_256         (0b111 << 3)


//@ref SPI_IRQ_Enable
#define SPI_IRQ_Enable_NONE       (0x00000000U)
#define SPI_IRQ_Enable_TXEIE      (0x1<<7)
#define SPI_IRQ_Enable_RXNEIE     (0x1<<6)
#define SPI_IRQ_Enable_ERRIE      (0x1<<5)


typedef enum
{
	Polling_DISABLE ,
	Polling_ENABLE
}SPI_Polling_Mechanism;

/*
* ===============================================
* APIs Supported by "MCAL USART DRIVER"
* ===============================================
*/
void MCAL_SPI_init(SPI_TypeDef* SPIx , SPI_Config_t* SPI_Config);
void MCAL_SPI_Deinit(SPI_TypeDef* SPIx);

void MCAL_SPI_GPIO_SetPins(SPI_TypeDef* SPIx);

void MCAL_SPI_Send_Data(SPI_TypeDef* SPIx , uint16_t* p_TxBuffer , SPI_Polling_Mechanism Polling);
void MCAL_SPI_Receive_Data(SPI_TypeDef* SPIx , uint16_t* p_TxBuffer , SPI_Polling_Mechanism Polling);

void MCAL_SPI_SendReceive_Data(SPI_TypeDef* SPIx , uint16_t* p_TxBuffer , SPI_Polling_Mechanism Polling);





#endif /* INC_STM32F103X8_SPI_DRIVER_H_ */
