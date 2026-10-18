# STM32F407 Sensor [BSP(Board Support Package)](https://en.wikipedia.org/wiki/Board_support_package)

This is a Bare-Metal, register level Board Support Package for the **STM32F407G-DISC1** (STM32F407VGT6, Cortex-M4)

**End Goal** - Sensing foundation of an [HVAC](https://en.wikipedia.org/wiki/Heating,_ventilation,_and_air_conditioning)-style controller by reading the temperature and humidity from the sensor via [I2C](https://en.wikipedia.org/wiki/I2C) and stream the readings over [UART](https://en.wikipedia.org/wiki/Universal_asynchronous_receiver-transmitter)

## Status

- [x] GPIO Driver
- [ ] USART Driver
- [ ] I2C Driver
- [ ] SPI Drivers
- [ ] BME280 sensor layer
- [ ] Test sample for each driver layer
- [ ] CI pipeline


## Hardware

| Item | Purpose |
|---|---|
| STM32F407G-DISC1 | Target board |
| BME280 breakout (I2C) | Temperature / humidity sensor
| USB-to-TTL adapter | UART output on PC 






## Subsectinos to add
- [ ] Design approach
- [ ] Projet structure
- [ ] Build and Flashing Instructions
- [ ] References Section

