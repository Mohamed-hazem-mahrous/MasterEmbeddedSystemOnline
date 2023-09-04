/*
 * Stm32_F103C6_GPIO_Driver.h
 *
 *  Created on: Sep 4, 2023
 *      Author: Mohamed
 */

#ifndef STM32_F103C6_GPIO_DRIVER_H_
#define STM32_F103C6_GPIO_DRIVER_H_



//-----------------------------
//Includes
//-----------------------------
#include "Stm32_F103x6.h"





//====================================================================================================================







//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef struct
{
	uint16_t GPIO_PinNumber;		// Specifies the GPIO pins to be configured
									// this parameter can be a value of @ref GPIO_PINS_Define

	uint8_t GPIO_Mode;				// Specifies the operating mode for the selected Pins
									// this parameter can be a value of @ref GPIO_MODE_Define

	uint8_t GPIO_Output_Speed;		// Specifies the speed for the selected Pins
									// this parameter can be a value of @ref GPIO_SPEED_Define

}GPIO_PinConfig_t;






//====================================================================================================================







//-----------------------------
//Macros Configuration References
//-----------------------------

/*@ref GPIO_PIN_STATUS
*/
#define GPIO_PIN_SET			1
#define GPIO_PIN_RESET			0




/*@ref GPIO_RETURN_LOCK
*/
#define GPIO_RETURN_LOCK_ENABLED			1
#define GPIO_RETURN_LOCK_ERROR		0








/*@ref GPIO_PINS_Define
*/
#define GPIO_PIN_0					((uint16_t)0x0001)  /*Pin 0 Selected*/
#define GPIO_PIN_1					((uint16_t)0x0002)  /*Pin 1 Selected*/
#define GPIO_PIN_2					((uint16_t)0x0004)  /*Pin 2 Selected*/
#define GPIO_PIN_3					((uint16_t)0x0008)  /*Pin 3 Selected*/
#define GPIO_PIN_4					((uint16_t)0x0010)  /*Pin 4 Selected*/
#define GPIO_PIN_5					((uint16_t)0x0020)  /*Pin 5 Selected*/
#define GPIO_PIN_6					((uint16_t)0x0040)  /*Pin 6 Selected*/
#define GPIO_PIN_7					((uint16_t)0x0080)  /*Pin 7 Selected*/
#define GPIO_PIN_8					((uint16_t)0x0100)  /*Pin 8 Selected*/
#define GPIO_PIN_9					((uint16_t)0x0200)  /*Pin 9 Selected*/
#define GPIO_PIN_10					((uint16_t)0x0400)  /*Pin 10 Selected*/
#define GPIO_PIN_11					((uint16_t)0x0800)  /*Pin 11 Selected*/
#define GPIO_PIN_12					((uint16_t)0x1000)  /*Pin 12 Selected*/
#define GPIO_PIN_13					((uint16_t)0x2000)  /*Pin 13 Selected*/
#define GPIO_PIN_14					((uint16_t)0x4000)  /*Pin 14 Selected*/
#define GPIO_PIN_15					((uint16_t)0x8000)  /*Pin 15 Selected*/

#define GPIO_PIN_ALL				((uint16_t)0xFFFF)  /*All Pins Selected*/

#define GPIO_PIN_MASK				0x0000FFFFu  /*Pin Mask for assert test*/





/*@ref GPIO_MODE_Define
 * 		0: Analog Mode
 * 		1: FLoating Input  (Reset State)
 * 		2: Input with pull up
 * 		3: Input with pull Down
 * 		4: General Purpose Output push-pull
 * 		5: General Purpose Output open-drain
 * 		6: Alternative Function Output push-pull
 * 		7: Alternative Function Output open-drain
 * 		8: Alternative Function Input
*/
#define GPIO_MODE_Analog							0x00000000u // Analog Mode
#define GPIO_MODE_INPUT_FLo							0x00000001u // FLoating Input
#define GPIO_MODE_INPUT_PU							0x00000002u // Input with pull up
#define GPIO_MODE_INPUT_PD							0x00000003u // Input with pull Down
#define GPIO_MODE_OUTPUT_PP							0x00000004u // General Purpose Output push-pull
#define GPIO_MODE_OUTPUT_OD							0x00000005u // General Purpose Output open-drain
#define GPIO_MODE_OUTPUT_AF_PP						0x00000006u // Alternative Function Output push-pull
#define GPIO_MODE_OUTPUT_AF_OD						0x00000007u // Alternative Function Output open-drain
#define GPIO_MODE_OUTPUT_AF_INPUT					0x00000008u // Alternative Function Input







/*@ref GPIO_SPEED_Define
 * 		01: Output Mode, max speed = 10 MHZ
 * 		10: Output Mode, max speed = 2 MHZ
 * 		11: Output Mode, max speed = 50 MHZ
*/
#define GPIO_SPEED_10_MHZ							0x00000001u // Output Mode, max speed = 10 MHZ
#define GPIO_SPEED_2_MHZ							0x00000002u // Output Mode, max speed = 2 MHZ
#define GPIO_SPEED_50_MHZ							0x00000003u // Output Mode, max speed = 50 MHZ








//====================================================================================================================







/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/
void MCAL_GPIO_INIT				(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig);
void MCAL_GPIO_DEINIT			(GPIO_TypeDef *GPIOx);

// Read APIs
uint8_t MCAL_GPIO_ReadPIN		(GPIO_TypeDef *GPIOx, uint8_t PinNumber);
uint16_t MCAL_GPIO_ReadPORT		(GPIO_TypeDef *GPIOx);

// Write APIs
void MCAL_GPIO_WritePIN			(GPIO_TypeDef *GPIOx, uint8_t PinNumber, uint8_t value);
void MCAL_GPIO_WritePORT		(GPIO_TypeDef *GPIOx, uint8_t value);

void MCAL_GPIO_TogglePIN		(GPIO_TypeDef *GPIOx, uint8_t PinNumber);

uint8_t MCAL_GPIO_LockPIN		(GPIO_TypeDef *GPIOx, uint8_t PinNumber);







#endif /* STM32_F103C6_GPIO_DRIVER_H_ */
