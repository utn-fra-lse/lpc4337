# API

## Supported peripherials

| Peripherial | Files | Description |
| --- | --- | --- |
| ADC | [ciaa_adc_api.h]/[ciaa_adc_api.c] | Support for ADC0 and ADC1. Works by enabling one channel at a time. Reading can be done by polling or interrupt request service.
| DAC | [ciaa_dac_api.h]/[ciaa_dac_api.c] | Support for controling output of DAC and enabling alternative output pin.
| GPIO | [ciaa_gpio_api.h]/[ciaa_gpio_api.c] | Support for general purpose functions such as: enable GPIO pin, set direction, read and write values and set, clear and xor output. 
| PWM | [ciaa_pwm_api.h]/[ciaa_pwm_api.c] | Support for controlling up to 16 PWM outputs. Frequency, duty cycle and output pins are customizable.
| SCU | [ciaa_scu_api.h]/[ciaa_scu_api.c] | Support for System Control Unit. It is responsible for enabling a pin function.
| SysTick | [ciaa_systick_api.h]/[ciaa_systick_api.c] | Support for SysTick and time tracking.
| TIMER | [ciaa_timer_api.h]/[ciaa_timer_api.c] | Support for TIMERs initialization and interrupts.
| UART | [ciaa_uart_api.h]/[ciaa_uart_api.c] | Support for asyncronous receiver transmiter. All UART from 0 through 3 are usable.
| USB | [ciaa_usb_api.h]/[ciaa_usb_api.c] | Support for basic USB communication. Send and read functions working with libusb drivers necessary in host computer.

## Extra libraries

| Library | Files | Description |
| --- | --- | --- |
| stdlib | [ciaa_stdlib.h]/[ciaa_stdlib.c] | Adds sleep functions.
| usb_descriptors | [ciaa_usb_descriptors.c] | Defines the USB descriptors for the LPC4337.
| usb_app_config | [app_usbd_cfg.h] | USB configuration and definitions for generic project.

[ciaa_gpio_api.h]: inc/ciaa_gpio_api.h
[ciaa_gpio_api.c]: src/ciaa_gpio_api.c
[ciaa_adc_api.h]: inc/ciaa_adc_api.h
[ciaa_adc_api.c]: src/ciaa_adc_api.c
[ciaa_dac_api.h]: inc/ciaa_dac_api.h
[ciaa_dac_api.c]: src/ciaa_dac_api.c
[ciaa_pwm_api.h]: inc/ciaa_pwm_api.h
[ciaa_pwm_api.c]: src/ciaa_pwm_api.c
[ciaa_scu_api.h]: inc/ciaa_scu_api.h
[ciaa_scu_api.c]: src/ciaa_scu_api.c
[ciaa_systick_api.h]: inc/ciaa_systick_api.h
[ciaa_systick_api.c]: src/ciaa_systick_api.c
[ciaa_timer_api.h]: inc/ciaa_timer_api.h
[ciaa_timer_api.c]: src/ciaa_timer_api.c
[ciaa_stdlib.h]: inc/ciaa_stdlib.h
[ciaa_stdlib.c]: src/ciaa_stdlib.c
[ciaa_uart_api.h]: inc/ciaa_uart_api.h
[ciaa_uart_api.c]: src/ciaa_uart_api.c
[ciaa_usb_api.h]: inc/ciaa_usb_api.h
[ciaa_usb_api.c]: src/ciaa_usb_api.c
[ciaa_usb_descriptors.c]: src/ciaa_usb_descriptors.c
[app_usbd_cfg.h]: inc/app_usbd_cfg.h