/*
 * gpio_driver.c
 *
 *  Created on: Oct 5, 2026
 *      Author: rajat
 */

#include "gpio_driver.h"


/* *****************************************************************************************
 *                               APIs supported by this driver
 *           
 ******************************************************************************************* */


 /*
  * Peripheral clock setup
 */

/* ***************************************************************
 *  @fn                 - GPIO_PeriClockControl
 * 
 * @brief               - This function enables or disables peripheral clock for the given GPIO port        
 *  
 * @param[in]           - base address of the GPIO port
 * @param[in]           - ENABLE or DISABLE macro
 * @param[in]           -
 *
 * @return              - none
 * 
 * @Note                - none
 */
void GPIO_PeriClockControl(GPIO_TypeDef *pGPIOx, uint8_t EnorDi) {
    if(EnorDi == ENABLE) {
        if(pGPIOx == GPIOA){
            GPIOA_CLK_EN();
        } else if(pGPIOx == GPIOB) {
            GPIOB_CLK_EN();
        } else if(pGPIOx == GPIOC) {
            GPIOC_CLK_EN();
        } else if(pGPIOx == GPIOD) {
            GPIOD_CLK_EN();
        } else if(pGPIOx == GPIOE) {
            GPIOE_CLK_EN();
        }
    } else {
        if(pGPIOx == GPIOA){
            GPIOA_CLK_DI();
        } else if(pGPIOx == GPIOB) {
            GPIOB_CLK_DI();
        } else if(pGPIOx == GPIOC) {
            GPIOC_CLK_DI();
        } else if(pGPIOx == GPIOD) {
            GPIOD_CLK_DI();
        } else if(pGPIOx == GPIOE) {
            GPIOE_CLK_DI();
        }
    }
}

/* 
 *  Init & DeInit
 */


/* ***************************************************************
 *  @fn                 - GPIO_Init
 * 
 * @brief               - This function initializes the GPIO port        
 *  
 * @param[in]           - GPIO Handle structural pointer address
 *
 * @return              - none
 * 
 * @Note                - none
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle) {
    
	/*
	 *  First clear those bit positions and then use bitwise or ( | ).
	 */

    // 1. configure the mode of the gpio pin 
	if(pGPIOHandle->GPIO_PinConfig.PinMode <= GPIO_MODE_ANALOG) {
		pGPIOHandle->pGPIOx->MODER &= ~(0b11 << (2 * pGPIOHandle->GPIO_PinConfig.PinNumber));  		// clearing the bit positions
	    pGPIOHandle->pGPIOx->MODER |= (pGPIOHandle->GPIO_PinConfig.PinMode << (2 * pGPIOHandle->GPIO_PinConfig.PinNumber)); // configuring the values
	} else {
		if(pGPIOHandle->GPIO_PinConfig.PinMode == GPIO_MODE_IT_RT) {
			// Configure the RTSR(Rising Trigger Selection Register)
			EXTI->FTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.PinNumber);   // clearing the falling edge trigger
			EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.PinNumber);
		} else if(pGPIOHandle->GPIO_PinConfig.PinMode == GPIO_MODE_IT_FT) {
			// Configure the FTSR(Falling Trigger Selection Register)
			EXTI->RTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.PinNumber);    // clearing the rising edge trigger
			EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.PinNumber);

		} else if(pGPIOHandle->GPIO_PinConfig.PinMode == GPIO_MODE_IT_RFT) {
			// Configure both the RTSR and FTSR registers
			EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.PinNumber);
			EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.PinNumber);
		}

		// 2. Configure the GPIO port selection in the SYSCFG_EXTICR
		uint8_t registerNo = pGPIOHandle->GPIO_PinConfig.PinNumber / 4;
		uint8_t bitShift = pGPIOHandle->GPIO_PinConfig.PinNumber % 4;
		uint8_t portcode = GPIO_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx);
		SYSCFG_CLK_EN();
		SYSCFG->EXTICR[registerNo] &= ~(0xF << (bitShift * 4));
		SYSCFG->EXTICR[registerNo] |= (portcode << (bitShift * 4));


		// 3. Enable the EXTI interrupt delivery using IMR
		EXTI->IMR |= 1 << pGPIOHandle->GPIO_PinConfig.PinNumber;

	}


    // 2. configure the speed of the gpio pin
    pGPIOHandle->pGPIOx->OSPEEDR &= ~(0b11 << (2 * pGPIOHandle->GPIO_PinConfig.PinNumber));  	// clearing the bit positions
    pGPIOHandle->pGPIOx->OSPEEDR |= (pGPIOHandle->GPIO_PinConfig.PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.PinNumber));

    // 3. configure the pupd type of the pin
    pGPIOHandle->pGPIOx->PUPDR &= ~(0b11 << (2 * pGPIOHandle->GPIO_PinConfig.PinNumber));   	// clearing the bit positions
    pGPIOHandle->pGPIOx->PUPDR |= (pGPIOHandle->GPIO_PinConfig.PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.PinNumber));

    // 4. configure the output type of the pin
    pGPIOHandle->pGPIOx->OTYPER &= ~(0b11 << pGPIOHandle->GPIO_PinConfig.PinNumber);			// clearing the bit positions
    pGPIOHandle->pGPIOx->OTYPER |= (pGPIOHandle->GPIO_PinConfig.PinOPType << pGPIOHandle->GPIO_PinConfig.PinNumber);

    // 5. configuring the alt functionality of the pin
    if(pGPIOHandle->GPIO_PinConfig.PinMode == GPIO_MODE_ALTFN){
    	if(pGPIOHandle->GPIO_PinConfig.PinNumber <= 7) {
    		pGPIOHandle->pGPIOx->AFR[0] &= ~(0b1111 << (4 * pGPIOHandle->GPIO_PinConfig.PinNumber));
			pGPIOHandle->pGPIOx->AFR[0] |= (pGPIOHandle->GPIO_PinConfig.PinAltFunction << (4 * pGPIOHandle->GPIO_PinConfig.PinNumber));
		} else {
			pGPIOHandle->pGPIOx->AFR[1] &= ~(0b1111 << (4 * pGPIOHandle->GPIO_PinConfig.PinNumber - 8));
			pGPIOHandle->pGPIOx->AFR[1] |= (pGPIOHandle->GPIO_PinConfig.PinAltFunction << (4 * (pGPIOHandle->GPIO_PinConfig.PinNumber - 8)));
		}
    }
}

/* ***************************************************************
 *  @fn                 - GPIO_DeInit
 * 
 * @brief               - This function resets the GPIO port        
 *  
 * @param[in]           - base address of the GPIO port
 *
 * @return              - none
 * 
 * @Note                - refer the reference manual for the reset values.
 */
void GPIO_DeInit(GPIO_TypeDef* pGPIOx) {        /*<! By this we will get the base address of the respective GPIO port to be reset >*/
	if(pGPIOx == GPIOA){
		GPIOA_RST();
	} else if(pGPIOx == GPIOB) {
		GPIOB_RST();
	} else if(pGPIOx == GPIOC) {
		GPIOC_RST();
	} else if(pGPIOx == GPIOD) {
		GPIOD_RST();
	} else if(pGPIOx == GPIOE) {
		GPIOE_RST();
	}
}


/* 
 *  Data Read & Write
 */

/* ***************************************************************
 *  @fn                 - GPIO_DeInit
 *
 * @brief               - This function resets the GPIO port
 *
 * @param[in]           - base address of the GPIO port
 *
 * @return              - none
 *
 * @Note                - refer the reference manual for the reset values.
 */
uint8_t GPIO_ReadInputPin(GPIO_TypeDef* pGPIOx, uint8_t PinNumber) { return (uint8_t)((pGPIOx->IDR >> PinNumber) & 1Ul); }

/* ***************************************************************
 *  @fn                 - GPIO_DeInit
 *
 * @brief               - This function resets the GPIO port
 *
 * @param[in]           - base address of the GPIO port

 *
 * @return              - none
 *
 * @Note                - refer the reference manual for the reset values.
 */
uint16_t GPIO_ReadInputPort(GPIO_TypeDef* pGPIOx) {	return (uint16_t) pGPIOx->IDR; }

/* ***************************************************************
 *  @fn                 - GPIO_DeInit
 *
 * @brief               - This function resets the GPIO port
 *
 * @param[in]           - base address of the GPIO port
 *
 * @return              - none
 *
 * @Note                - refer the reference manual for the reset values.
 */

void GPIO_WriteOuputPin(GPIO_TypeDef* pGPIOx, uint8_t PinNumber, uint8_t Value) {
	if(Value == SET) {
		pGPIOx->ODR |= (1 << PinNumber);
	} else {
		pGPIOx->ODR &= ~(1 << PinNumber);
	}
}

/* ***************************************************************
 *  @fn                 - GPIO_DeInit
 *
 * @brief               - This function resets the GPIO port
 *
 * @param[in]           - base address of the GPIO port
 *
 * @return              - none
 *
 * @Note                - refer the reference manual for the reset values.
 */
void GPIO_WriteOutputPort(GPIO_TypeDef* pGPIOx, uint16_t Value) { pGPIOx->ODR = Value; }

/* ***************************************************************
 *  @fn                 - GPIO_DeInit
 *
 * @brief               - This function resets the GPIO port
 *
 * @param[in]           - base address of the GPIO port
 *
 * @return              - none
 *
 * @Note                - refer the reference manual for the reset values.
 */
void GPIO_ToggleOutputPin(GPIO_TypeDef* pGPIOx, uint8_t PinNumber) { pGPIOx->ODR ^= (1 << PinNumber); }



/* 
 *  IRQ Configuration and ISR handling
 */

/* ***************************************************************
 *  @fn                 - GPIO_DeInit
 *
 * @brief               - This function resets the GPIO port
 *
 * @param[in]           - base address of the GPIO port

 *
 * @return              - none
 *
 * @Note                - refer the reference manual for the reset values.
 */

void GPIO_IRQEnOrDi(uint8_t IRQNumber, uint8_t EnorDi) {
	// ENABLE the interrupt
	if(EnorDi == ENABLE) {
		if(IRQNumber <= 31) {    		// 0 to 31
			// Configure NVIC_ISER0
			*NVIC_ISER0 |= (1 << IRQNumber);
		} else if(IRQNumber <= 63) {  	// 32 to 63
			// Configure NVIC_ISER1
			*NVIC_ISER1 |= (1 << (IRQNumber % 32));
		} else if(IRQNumber <= 95) { 	// 64 to 95
			// Configure NVIC_ISER2
			*NVIC_ISER2 |= (1 << (IRQNumber % 64));
		}
	} else {
		if(IRQNumber <= 31) {    		// 0 to 31
			// Configure NVIC_ISER0
			*NVIC_ICER0 |= (1 << IRQNumber);
		} else if(IRQNumber <= 63) {  	// 32 to 63
			// Configure NVIC_ISER1
			*NVIC_ICER1 |= (1 << (IRQNumber % 32));
		} else if(IRQNumber <= 95) { 	// 64 to 95
			// Configure NVIC_ISER2
			*NVIC_ICER2 |= (1 << (IRQNumber % 64));
		}
	}

}


/* ***************************************************************
 *  @fn                 - GPIO_IRQPriorityConfig
 *
 * @brief               - This function sets the priority of the interrupt
 *
 * @param[in]           - Interrupt Number
 * @param[in]           - Interrupt Priority
 *
 * @return              - none
 * @Note                -
 */
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority) {
	uint8_t offSet = (IRQNumber / 4) * 4;
	uint8_t bitShift = ((IRQNumber % 4) * 8) + NO_PR_BITS_IMPLEMENTED; // The processor implements only bits[7:4] of each field, bits[3:0] read as zero and ignore writes.

	*(NVIC_IPR_BASE + offSet) |= (IRQPriority << bitShift);
}

void GPIO_ISRHandling(uint8_t PinNumber) {
	// Clear the exti pr register corresponding to the pin number
	if(EXTI->PR & (1 << PinNumber)) {
		EXTI->PR |= (1 << PinNumber);
	}
}





