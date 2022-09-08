# API

## Supported peripherials

| Peripherial | Files | Description |
| --- | --- | --- |
| ADC | [ciaa_adc_api.h]/[ciaa_adc_api.c] | Support for ADC0 and ADC1. Works by enabling one channel at a time. Reading can be done by polling or interrupt request service.
| DAC | [ciaa_dac_api.h]/[ciaa_dac_api.c] | Support for controling output of DAC and enabling alternative output pin.
| GPIO | [ciaa_gpio_api.h]/[ciaa_gpio_api.c] | Support for general purpose functions such as: enable GPIO pin, set direction, read and write values and set, clear and xor output. 
| IPC | [ciaa_ipc_api.h]/[ciaa_ipc_api.c] | Support for Intterprocessor Communication. Handles messaging between cores with a queue in a shared memory address.
| Multicore | [ciaa_multicore_api.h]/[ciaa_multicore_api.c] | Support for multicore initialization and communication. No data is shared within cores in this library, only interrupts are used to synchronize them.
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

[ciaa_gpio_api.h]: ciaa_api/inc/ciaa_gpio_api.h
[ciaa_gpio_api.c]: ciaa_api/src/ciaa_gpio_api.c
[ciaa_adc_api.h]: ciaa_api/inc/ciaa_adc_api.h
[ciaa_adc_api.c]: ciaa_api/src/ciaa_adc_api.c
[ciaa_dac_api.h]: ciaa_api/inc/ciaa_dac_api.h
[ciaa_dac_api.c]: ciaa_api/src/ciaa_dac_api.c
[ciaa_pwm_api.h]: ciaa_api/inc/ciaa_pwm_api.h
[ciaa_pwm_api.c]: ciaa_api/src/ciaa_pwm_api.c
[ciaa_scu_api.h]: ciaa_api/inc/ciaa_scu_api.h
[ciaa_scu_api.c]: ciaa_api/src/ciaa_scu_api.c
[ciaa_systick_api.h]: ciaa_api/inc/ciaa_systick_api.h
[ciaa_systick_api.c]: ciaa_api/src/ciaa_systick_api.c
[ciaa_timer_api.h]: ciaa_api/inc/ciaa_timer_api.h
[ciaa_timer_api.c]: ciaa_api/src/ciaa_timer_api.c
[ciaa_stdlib.h]: ciaa_api/inc/ciaa_stdlib.h
[ciaa_stdlib.c]: ciaa_api/src/ciaa_stdlib.c
[ciaa_uart_api.h]: ciaa_api/inc/ciaa_uart_api.h
[ciaa_uart_api.c]: ciaa_api/src/ciaa_uart_api.c
[ciaa_usb_api.h]: ciaa_api/inc/ciaa_usb_api.h
[ciaa_usb_api.c]: ciaa_api/src/ciaa_usb_api.c
[ciaa_usb_descriptors.c]: ciaa_api/src/ciaa_usb_descriptors.c
[app_usbd_cfg.h]: ciaa_api/inc/app_usbd_cfg.h
[ciaa_multicore_api.h]: ciaa_api/inc/ciaa_multicore_api.h
[ciaa_multicore_api.c]: ciaa_api/src/ciaa_multicore_api.c
[ciaa_ipc_api.h]: ciaa_api/inc/ciaa_ipc_api.h
[ciaa_ipc_api.c]: ciaa_api/src/ciaa_ipc_api.c