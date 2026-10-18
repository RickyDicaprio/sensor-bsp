/*
 * gpio_driver.h
 *
 *  Created on: Oct 5, 2026
 *      Author: rajat
 */


/* This is a gpio header file which allows the user to configure the required GPIOx. */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_


#include "stm32f407xx.h"

/* 
 *  This is Configuration structure for a GPIO pin
 */

typedef struct {
    uint8_t PinNumber;                          /*!< possible values from @GPIO_PIN >*/
    uint8_t PinMode;                            /*!< possible values from @GPIO_MODES >*/
    uint8_t PinOPType;                          /*!< possible values from @GPIO_OTYPE >*/
    uint8_t PinSpeed;                           /*!< possible values from @GPIO_SPEED >*/
    uint8_t PinPuPdControl;                     /*!< possible values from @GPIO_PUPD >*/
    uint8_t PinAltFunction;                     /*!< possible values from @GPIO_ALT >*/
} GPIO_PinConfig_t;


/* 
 * This is a Handle structure for a GPIO pin
 */

typedef struct {
    GPIO_TypeDef *pGPIOx;                       /*!< This holds the base address of the GPIO port to which the pin belongs >*/
    GPIO_PinConfig_t GPIO_PinConfig;            /*!< This holds the GPIO pin configuration settings >*/
} GPIO_Handle_t;

/* 
 *  @GPIO_PIN
 *  GPIO possible pin numbers
 */
#define GPIO_PIN_0              0          
#define GPIO_PIN_1              1
#define GPIO_PIN_2              2
#define GPIO_PIN_3              3
#define GPIO_PIN_4              4
#define GPIO_PIN_5              5
#define GPIO_PIN_6              6
#define GPIO_PIN_7              7
#define GPIO_PIN_8              8
#define GPIO_PIN_9              9
#define GPIO_PIN_10             10
#define GPIO_PIN_11             11
#define GPIO_PIN_12             12
#define GPIO_PIN_13             13
#define GPIO_PIN_14             14
#define GPIO_PIN_15             15



/* 
 *  @GPIO_MODES
 *  GPIO pin possible modes
 */
#define GPIO_MODE_INPUT         0b00
#define GPIO_MODE_OUTPUT        0b01
#define GPIO_MODE_ALTFN         0b10
#define GPIO_MODE_ANALOG        0b11
#define GPIO_MODE_IT_FT         0b100           /*!< Interrupt Falling Edge >*/
#define GPIO_MODE_IT_RT         0b101           /*!< Interrupt Rising Edge >*/
#define GPIO_MODE_IT_RFT        0b110           /*!< Interrupt Rising Falling Edge >*/

/* 
 *  @GPIO_OTYPE 
 *  GPIO pin possible output types
 */
#define GPIO_OTYPE_PP           0b0             /*!< Push-Pull Mode >*/
#define GPIO_OTYPE_OD           0b1             /*!< Open-drain Mode >*/

/* 
 *  @GPIO_SPEED
 *  GPIO pin possible speeds
 */
#define GPIO_OSPEED_L           0b00
#define GPIO_OSPEED_M           0b01
#define GPIO_OSPEED_H           0b10
#define GPIO_OSPEED_VH          0b11

/* 
 *  @GPIO_PUPD
 *  GPIO pin pull-up or pull-down modes
 */
#define GPIO_PUPD_NONE          0b00
#define GPIO_PUPD_PU            0b01
#define GPIO_PUPD_PD            0b10


/*
 *  @GPIO_ALT
 *  GPIO pin Alternate Function modes
 */




/* *****************************************************************************************
 *                               APIs supported by this driver
 *           
 *******************************************************************************************/

/* 
 *  Peripheral clock setup
 */


void GPIO_PeriClockControl(GPIO_TypeDef *pGPIOx, uint8_t EnorDi);

/* 
 *  Init & DeInit
 */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_TypeDef* pGPIOx);        /*!< By this we will get the base address of the respective GPIO port to be reset >*/




/* 
 *  Data Read & Write
 */

uint8_t GPIO_ReadInputPin(GPIO_TypeDef* pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadInputPort(GPIO_TypeDef* pGPIOx);
void GPIO_WriteOuputPin(GPIO_TypeDef* pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteOutputPort(GPIO_TypeDef* pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_TypeDef* pGPIOx, uint8_t PinNumber);

/* 
 *  IRQ Configuration and ISR handling
 */

void GPIO_IRQEnOrDi(uint8_t IRONumber, uint8_t EnorDi);
void GPIO_IRQPriorityConfig(uint8_t IRONumber, uint8_t IRQPriority);
void GPIO_ISRHandling(uint8_t PinNumber);







#endif /* GPIO_DRIVER_H_ */
