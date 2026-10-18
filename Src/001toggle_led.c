#include <stdint.h>
#include "stm32f407xx.h"
#include "gpio_driver.h"

extern void toggle_led(void);

void toggle_led(void)
{
	GPIO_Handle_t GpioLedA; //, GpioLedB, GpioLedC, GpioLedD;

	GpioLedA.pGPIOx = GPIOD;
	GpioLedA.GPIO_PinConfig.PinNumber = GPIO_PIN_12;
	GpioLedA.GPIO_PinConfig.PinMode = GPIO_MODE_OUTPUT;
	GpioLedA.GPIO_PinConfig.PinOPType = GPIO_OTYPE_PP;
	GpioLedA.GPIO_PinConfig.PinSpeed = GPIO_OSPEED_L;
	GpioLedA.GPIO_PinConfig.PinPuPdControl = GPIO_PUPD_NONE;


/*  GpioLedB.pGPIOx = GPIOD;
	GpioLedB.GPIO_PinConfig.PinNumber = GPIO_PIN_13;
	GpioLedB.GPIO_PinConfig.PinMode = GPIO_MODE_OUTPUT;
	GpioLedB.GPIO_PinConfig.PinOPType = GPIO_OTYPE_PP;
	GpioLedB.GPIO_PinConfig.PinSpeed = GPIO_OSPEED_L;
	GpioLedB.GPIO_PinConfig.PinPuPdControl = GPIO_PUPD_NONE;

	GpioLedC.pGPIOx = GPIOD;
	GpioLedC.GPIO_PinConfig.PinNumber = GPIO_PIN_14;
	GpioLedC.GPIO_PinConfig.PinMode = GPIO_MODE_OUTPUT;
	GpioLedC.GPIO_PinConfig.PinOPType = GPIO_OTYPE_PP;
	GpioLedC.GPIO_PinConfig.PinSpeed = GPIO_OSPEED_L;
	GpioLedC.GPIO_PinConfig.PinPuPdControl = GPIO_PUPD_NONE;

	GpioLedD.pGPIOx = GPIOD;
	GpioLedD.GPIO_PinConfig.PinNumber = GPIO_PIN_15;
	GpioLedD.GPIO_PinConfig.PinMode = GPIO_MODE_OUTPUT;
	GpioLedD.GPIO_PinConfig.PinOPType = GPIO_OTYPE_PP;
	GpioLedD.GPIO_PinConfig.PinSpeed = GPIO_OSPEED_L;
	GpioLedD.GPIO_PinConfig.PinPuPdControl = GPIO_PUPD_NONE;
*/

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLedA);
//	GPIO_Init(&GpioLedB);
//	GPIO_Init(&GpioLedC);
//	GPIO_Init(&GpioLedD);
	while(1) {
		GPIO_ToggleOutputPin(GpioLedA.pGPIOx, GPIO_PIN_12);
//		GPIO_ToggleOutputPin(GpioLedB.pGPIOx, GPIO_PIN_13);
//		GPIO_ToggleOutputPin(GpioLedC.pGPIOx, GPIO_PIN_14);
//		GPIO_ToggleOutputPin(GpioLedD.pGPIOx, GPIO_PIN_15);
		for(uint32_t i = 0; i <= 1605445; i++) i++;
	}
}





