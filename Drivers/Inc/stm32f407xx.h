/*
 * stm32f407xx.h
 *
 *  Created on: Oct 4, 2026
 *      Author: rajat
 */

#include <stdint.h>

#ifndef STM32F407XX_H_
#define STM32F407XX_H_

#define __IO volatile



/************************************* Processor Specific Details ************************************/

/*
 *  ARM Cortex Mx Processor NVIC ISERx register Address
 */

#define NVIC_ISER0				((__IO uint32_t*)0xE000E100)
#define NVIC_ISER1				((__IO uint32_t*)0xE000E104)
#define NVIC_ISER2				((__IO uint32_t*)0xE000E108)
#define NVIC_ISER3				((__IO uint32_t*)0xE000E10C)


/*
 *  ARM Cortex Mx Processor NVIC ICERx register Address
 */

#define NVIC_ICER0				((__IO uint32_t*)0xE000E180)
#define NVIC_ICER1				((__IO uint32_t*)0xE000E184)
#define NVIC_ICER2				((__IO uint32_t*)0xE000E188)
#define NVIC_ICER3				((__IO uint32_t*)0xE000E18C)


/*
 * ARM Cortex Mx Processor Interrupt Priority Register Address
 */
#define NVIC_IPR_BASE			((__IO uint32_t*)0xE000E400)

#define NO_PR_BITS_IMPLEMENTED	4




/*
 * Base addresses of FLASH and SRAM memories
 */

#define SRAM2_BASE   			0x2001C000UL
#define SRAM1_BASE   			0x20000000UL
#define ROM_BASE     			0x1FFF0000UL  /* also known as system memory. */
#define FLASH_BASE   			0x08000000UL   /* addresses cannot be signed */

/*
 * APBx and AHBx Bus Peripheral base address
 */

#define AHB3PERIPH_BASE			0xA0000000UL
#define AHB2PERIPH_BASE			0x50000000UL
#define AHB1PERIPH_BASE			0x40020000UL
#define APB2PERIPH_BASE			0x40010000UL
#define APB1PERIPH_BASE			0x40000000UL

/*
 * AHB3 Peripherals Base Addresses
 */

#define FSMC_CR_BASE 			AHB3PERIPH_BASE

/*
 * AHB2 Peripherals Base Addresses
 */

#define RNG 					(AHB2PERIPH_BASE + 60800UL)
#define HASH					(AHB2PERIPH_BASE + 60400UL)
#define CRYP					(AHB2PERIPH_BASE + 60000UL)
#define DCMI					(AHB2PERIPH_BASE + 50000UL)
#define USB_OTG_FS				(AHB2PERIPH_BASE + 00000UL)

/*
 * AHB1 Peripherals Base Addresses
 */

#define USB_OTG_HS				(AHB1PERIPH_BASE + 0x20000UL)
#define DMA2D					(AHB1PERIPH_BASE + 0xB000UL)
#define ETHERNET_MAC			(AHB1PERIPH_BASE + 0x8000UL)	
#define DMA2					(AHB1PERIPH_BASE + 0x6400UL)
#define DMA1					(AHB1PERIPH_BASE + 0x6000UL)
#define BKPSRAM					(AHB1PERIPH_BASE + 0x4000UL)
#define FLASH_INTERFACE			(AHB1PERIPH_BASE + 0x3C00UL)
#define RCC_BASE				(AHB1PERIPH_BASE + 0x3800UL)
#define CRC_BASE				(AHB1PERIPH_BASE + 0x3000UL)
#define GPIOK_BASE				(AHB1PERIPH_BASE + 0x2800UL)
#define GPIOJ_BASE				(AHB1PERIPH_BASE + 0x2400UL)
#define GPIOI_BASE				(AHB1PERIPH_BASE + 0x2000UL)
#define GPIOH_BASE				(AHB1PERIPH_BASE + 0x1C00UL)
#define GPIOG_BASE 				(AHB1PERIPH_BASE + 0x1800UL)
#define GPIOF_BASE				(AHB1PERIPH_BASE + 0x1400UL)
#define GPIOE_BASE				(AHB1PERIPH_BASE + 0x1000UL)
#define GPIOD_BASE				(AHB1PERIPH_BASE + 0x0C00UL)
#define	GPIOC_BASE				(AHB1PERIPH_BASE + 0x0800UL)
#define GPIOB_BASE				(AHB1PERIPH_BASE + 0x0400UL)
#define GPIOA_BASE 				(AHB1PERIPH_BASE + 0x0000UL)

/*
 * APB2 Peripherals Base Addresses
 */

#define SPI6_BASE             	(APB2PERIPH_BASE + 0x5400UL)
#define SPI5_BASE             	(APB2PERIPH_BASE + 0x5000UL)
#define SAI1_BASE             	(APB2PERIPH_BASE + 0x5800UL)
#define LTDC_BASE             	(APB2PERIPH_BASE + 0x6800UL)
#define TIM11_BASE            	(APB2PERIPH_BASE + 0x4800UL)
#define TIM10_BASE            	(APB2PERIPH_BASE + 0x4400UL)
#define TIM9_BASE             	(APB2PERIPH_BASE + 0x4000UL)
#define EXTI_BASE             	(APB2PERIPH_BASE + 0x3C00UL)
#define SYSCFG_BASE           	(APB2PERIPH_BASE + 0x3800UL)
#define SPI4_BASE             	(APB2PERIPH_BASE + 0x3400UL)
#define SPI1_BASE             	(APB2PERIPH_BASE + 0x3000UL)
#define SDIO_BASE             	(APB2PERIPH_BASE + 0x2C00UL)
#define ADC_BASE              	(APB2PERIPH_BASE + 0x2000UL)
#define USART6_BASE           	(APB2PERIPH_BASE + 0x1400UL)
#define USART1_BASE           	(APB2PERIPH_BASE + 0x1000UL)
#define TIM8_BASE             	(APB2PERIPH_BASE + 0x0400UL)
#define TIM1_BASE             	(APB2PERIPH_BASE + 0x0000UL)

/*
 *  APB1 Peripherals Base Addresses
 */

#define DAC_BASE             	(APB1PERIPH_BASE + 0x7400UL)
#define PWR_BASE             	(APB1PERIPH_BASE + 0x7000UL)
#define CAN2_BASE            	(APB1PERIPH_BASE + 0x6800UL)
#define CAN1_BASE            	(APB1PERIPH_BASE + 0x6400UL)
#define I2C3_BASE            	(APB1PERIPH_BASE + 0x5C00UL)
#define I2C2_BASE            	(APB1PERIPH_BASE + 0x5800UL)
#define I2C1_BASE            	(APB1PERIPH_BASE + 0x5400UL)
#define UART5_BASE           	(APB1PERIPH_BASE + 0x5000UL)
#define UART4_BASE           	(APB1PERIPH_BASE + 0x4C00UL)
#define USART3_BASE          	(APB1PERIPH_BASE + 0x4800UL)
#define USART2_BASE          	(APB1PERIPH_BASE + 0x4400UL)
#define I2S3EXT_BASE         	(APB1PERIPH_BASE + 0x4000UL)
#define SPI3_BASE            	(APB1PERIPH_BASE + 0x3C00UL)
#define SPI2_BASE            	(APB1PERIPH_BASE + 0x3800UL)
#define I2S2EXT_BASE         	(APB1PERIPH_BASE + 0x3400UL)
#define IWDG_BASE            	(APB1PERIPH_BASE + 0x3000UL)
#define WWDG_BASE            	(APB1PERIPH_BASE + 0x2C00UL)
#define RTC_BKP_BASE         	(APB1PERIPH_BASE + 0x2800UL)
#define TIM14_BASE           	(APB1PERIPH_BASE + 0x2000UL)
#define TIM13_BASE           	(APB1PERIPH_BASE + 0x1C00UL)
#define TIM12_BASE           	(APB1PERIPH_BASE + 0x1800UL)
#define TIM7_BASE            	(APB1PERIPH_BASE + 0x1400UL)
#define TIM6_BASE            	(APB1PERIPH_BASE + 0x1000UL)
#define TIM5_BASE            	(APB1PERIPH_BASE + 0x0C00UL)
#define TIM4_BASE            	(APB1PERIPH_BASE + 0x0800UL)
#define TIM3_BASE            	(APB1PERIPH_BASE + 0x0400UL)
#define TIM2_BASE            	(APB1PERIPH_BASE + 0x0000UL)



/*
 *  Structural definition of GPIOx   ( Because these are memory-mapped )
 */

typedef struct {
	__IO uint32_t MODER;
	__IO uint32_t OTYPER;
	__IO uint32_t OSPEEDR;
	__IO uint32_t PUPDR;
	__IO uint32_t IDR;
	__IO uint32_t ODR;
	__IO uint32_t BSRR;
	__IO uint32_t LCKR;
	__IO uint32_t AFR[2]; /* [0] --> AFRL, [1] ---> AFRH */
} GPIO_TypeDef;




/* 
 * Reset & Clock Control registers structural definitions
 */

typedef struct {
	__IO uint32_t CR;
	__IO uint32_t PLLCFGR;
	__IO uint32_t CFGR;
	__IO uint32_t CIR;
	__IO uint32_t AHB1RSTR;
	__IO uint32_t AHB2RSTR;
	__IO uint32_t AHB3RSTR;
	__IO uint32_t RESERVED0;
	__IO uint32_t APB1RSTR;
	__IO uint32_t APB2RSTR;
	__IO uint32_t RESERVED1[2];
	__IO uint32_t AHB1ENR;
	__IO uint32_t AHB2ENR;
	__IO uint32_t AHB3ENR;
	__IO uint32_t RESERVED2;
	__IO uint32_t APB1ENR;
	__IO uint32_t APB2ENR;
	__IO uint32_t RESERVED3[2];
	__IO uint32_t AHB1LPENR;
	__IO uint32_t AHB2LPENR;
	__IO uint32_t AHB3LPENR;
	__IO uint32_t RESERVED4;
	__IO uint32_t APB1LPENR;
	__IO uint32_t APB2LPENR;
	__IO uint32_t RESERVED5[2];
	__IO uint32_t BDCR;
	__IO uint32_t CSR;
	__IO uint32_t RESERVED6[2];
	__IO uint32_t RCC_SSCGR;
	__IO uint32_t PLLI2SCFGR;
} RCC_TypeDef;


/*
 * EXTI registers structural definitions
 */


typedef struct {
	__IO uint32_t IMR;
	__IO uint32_t EMR;
	__IO uint32_t RTSR;
	__IO uint32_t FTSR;
	__IO uint32_t SWIER;
	__IO uint32_t PR;
} EXTI_TypeDef;


/*
 * SYSCFG registers structural definitions
 */

typedef struct {
	__IO uint32_t MEMRMP;
	__IO uint32_t PMC;
	__IO uint32_t EXTICR[4];
	__IO uint32_t RESERVED1;
	__IO uint32_t CMPCR;
} SYSCFG_TypeDef;

/*
 *  Addresses Type casted to structural definitions
 */

#define GPIOA  	((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB  	((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC  	((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD  	((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE  	((GPIO_TypeDef *) GPIOE_BASE)

#define RCC 	((RCC_TypeDef *) RCC_BASE)
#define EXTI	((EXTI_TypeDef *) EXTI_BASE)
#define SYSCFG	((SYSCFG_TypeDef *) SYSCFG_BASE)

/*---------------------------- Clock Enable Macros ----------------------------*/

/* 
 *  Clock Enable Macros for GPIOx Peripherals
 */

#define GPIOA_CLK_EN()			(RCC->AHB1ENR |= (1 << 0))
#define GPIOB_CLK_EN()			(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_CLK_EN()			(RCC->AHB1ENR |= (1 << 2))
#define GPIOD_CLK_EN()			(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_CLK_EN()			(RCC->AHB1ENR |= (1 << 4))

/* 
 * Clock Enable Macros for I2Cx Peripherals
 */

#define I2C1_CLK_EN() 			(RCC->APB1ENR |= (1 << 21))
#define I2C2_CLK_EN() 			(RCC->APB1ENR |= (1 << 22))
#define I2C3_CLK_EN() 			(RCC->APB1ENR |= (1 << 23))

/* 
 *  Clock Enable Macros for SPIx Peripherals
 */

#define SPI1_CLK_EN()			(RCC->APB2ENR |= (1 << 12))
#define SPI2_CLK_EN()			(RCC->APB1ENR |= (1 << 14))
#define SPI3_CLK_EN()			(RCC->APB1ENR |= (1 << 15))


/* 
 *  Clock Enable Macros for USARTx & UARTx Peripherals
 */

#define USART1_CLK_EN()			(RCC->APB2ENR |= (1 << 4))
#define USART2_CLK_EN()			(RCC->APB1ENR |= (1 << 17))
#define USART3_CLK_EN()			(RCC->APB1ENR |= (1 << 18))
#define UART4_CLK_EN()			(RCC->APB1ENR |= (1 << 19))
#define UART5_CLK_EN()			(RCC->APB1ENR |= (1 << 20))

/* 
 * Clock Enable Macros for SYSCFG peripherals
 */

#define SYSCFG_CLK_EN()			(RCC->APB2ENR |= (1 << 14))



/*---------------------------- Clock Disable Macros ----------------------------*/


/* 
 *  Clock Disable Macros for GPIOx peripherals
 */

#define GPIOA_CLK_DI()  		(RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_CLK_DI()  		(RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_CLK_DI()  		(RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_CLK_DI()  		(RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_CLK_DI()  		(RCC->AHB1ENR &= ~(1 << 4))


/* 
 *  Clock Disable Macros for I2Cx peripherals
 */

#define I2C1_CLK_DI() 			(RCC->APB1ENR &= ~(1 << 21))
#define I2C2_CLK_DI() 			(RCC->APB1ENR &= ~(1 << 22))
#define I2C3_CLK_DI() 			(RCC->APB1ENR &= ~(1 << 23))


/* 
 *  Clock Disable Macros for SPIx peripherals
 */

#define SPI1_CLK_DI()			(RCC->APB2ENR &= ~(1 << 12))
#define SPI2_CLK_DI()			(RCC->APB1ENR &= ~(1 << 14))
#define SPI3_CLK_DI()			(RCC->APB1ENR &= ~(1 << 15))

/* 
 *  Clock Disable Macros for USARTx & UARTx peripherals
 */

#define USART1_CLK_DI()			(RCC->APB2ENR &= ~(1 << 4))
#define USART2_CLK_DI()			(RCC->APB1ENR &= ~(1 << 17))
#define USART3_CLK_DI()			(RCC->APB1ENR &= ~(1 << 18))
#define UART4_CLK_DI()			(RCC->APB1ENR &= ~(1 << 19))
#define UART5_CLK_DI()			(RCC->APB1ENR &= ~(1 << 20))

/* 
 *  Clock Disable Macros for SYSCFGx peripherals
 */

#define SYSCFG_CLK_DI()			(RCC->APB2ENR &= ~(1 << 14))


/*---------------------------- Peripheral Reset Macros ----------------------------*/

/*
 *  GPIOx Reset macros
 */

#define GPIOA_RST()				do { (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); } while(0)
#define GPIOB_RST()				do { (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1)); } while(0)
#define GPIOC_RST()				do { (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2)); } while(0)
#define GPIOD_RST()				do { (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3)); } while(0)
#define GPIOE_RST()				do { (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4)); } while(0)


/*  Some generic Macros */

#define ENABLE 					1
#define DISABLE					0
#define SET 					ENABLE
#define CLEAR					DISABLE
#define HIGH					ENABLE
#define LOW						DISABLE


/*
 *  Return port code for the given GPIOx base address
 */

#define GPIO_BASEADDR_TO_CODE(x)		((x == GPIOA) ? 0 : \
								   	   	 (x == GPIOB) ? 1 : \
										 (x == GPIOC) ? 2 : \
									   	 (x == GPIOD) ? 3 : \
										 (x == GPIOE) ? 4 : 0)


/*
 *  IRQ numbers for the STM32F407xx MCU
 */

#define IRQ_NO_EXTI0			6
#define IRQ_NO_EXTI1			7
#define IRQ_NO_EXTI2			8
#define IRQ_NO_EXTI3			9
#define IRQ_NO_EXTI4			10
#define IRQ_NO_EXTI9_5			23
#define IRQ_NO_EXTI15_10		40


/*
 *  IRQ Priorities
 */


#define NVIC_IRQ_PRI_0 			0
#define NVIC_IRQ_PRI_1 			1
#define NVIC_IRQ_PRI_2 			2
#define NVIC_IRQ_PRI_3 			3
#define NVIC_IRQ_PRI_4 			4
#define NVIC_IRQ_PRI_5 			5
#define NVIC_IRQ_PRI_6 			6
#define NVIC_IRQ_PRI_7 			7
#define NVIC_IRQ_PRI_8 			8
#define NVIC_IRQ_PRI_9 			9
#define NVIC_IRQ_PRI_10 		10
#define NVIC_IRQ_PRI_11			11
#define NVIC_IRQ_PRI_12			12
#define NVIC_IRQ_PRI_13			13
#define NVIC_IRQ_PRI_14			14
#define NVIC_IRQ_PRI_15			15




#endif /* STM32F407XX_H_ */
