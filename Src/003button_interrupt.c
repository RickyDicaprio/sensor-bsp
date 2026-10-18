/*
 * 003button_interrupt.c
 *
 *  Created on: Oct 18, 2026
 *      Author: rajat
 */

#include <stdint.h>
#include <string.h>
#include "gpio_driver.h"

extern void button_interrupt(void);

void button_interrupt (void) {

	// Configuring the PD4 pin for button
	GPIO_Handle_t GpioBtn, GpioLed;

	// Initialize the structure elements to 0
	memset(&GpioLed, 0, sizeof(GpioLed));
	memset(&GpioBtn, 0, sizeof(GpioBtn));

	GpioBtn.pGPIOx = GPIOD;
	GpioBtn.GPIO_PinConfig.PinNumber = GPIO_PIN_4;
	GpioBtn.GPIO_PinConfig.PinMode = GPIO_MODE_IT_FT;
	GpioBtn.GPIO_PinConfig.PinSpeed = GPIO_OSPEED_H;
	GpioBtn.GPIO_PinConfig.PinPuPdControl = GPIO_PUPD_PU;

	GPIO_PeriClockControl(GpioBtn.pGPIOx, ENABLE);
	GPIO_Init(&GpioBtn);

	// Configuring the PD12 led
	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.PinNumber = GPIO_PIN_12;
	GpioLed.GPIO_PinConfig.PinMode = GPIO_MODE_OUTPUT;
	GpioLed.GPIO_PinConfig.PinOPType = GPIO_OTYPE_PP;
	GpioLed.GPIO_PinConfig.PinSpeed = GPIO_OSPEED_L;
	GpioLed.GPIO_PinConfig.PinPuPdControl = GPIO_PUPD_NONE;
	GPIO_Init(&GpioLed);


	// IRQ Configurations
	GPIO_IRQEnOrDi(IRQ_NO_EXTI4, ENABLE);
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI4, NVIC_IRQ_PRI_15);
}


void EXTI4_IRQHandler(void) {
	for(uint32_t i = 0; i <= 1605445/10; i++) i++;
	GPIO_ISRHandling(GPIO_PIN_4);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_12);
}

