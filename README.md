# ciaa-api

## Supported Peripherials

| Peripherial | Files | Description |
| --- | --- | --- |
| ADC | [ciaa_adc_api.h]/[ciaa_adc_api.c] | Support for ADC0 and ADC1. Works by enabling one channel at a time. Reading can be done by polling or interrupt request service.
| DAC | [ciaa_dac_api.h]/[ciaa_dac_api.c] | Support for controling output of DAC and enabling alternative output pin.
| GPIO | [ciaa_gpio_api.h]/[ciaa_gpio_api.c] | Support for general purpose functions such as: enable GPIO pin, set direction, read and write values and set, clear and xor output. 
| PWM | [ciaa_pwm_api.h]/[ciaa_pwm_api.c] | Support for controlling up to 16 PWM outputs. Frequency, duty cycle and output pins are customizable.
| SCU | [ciaa_scu_api.h] | Support for System Control Unit. It is responsible for enabling a pin function. 


[ciaa_gpio_api.h]: inc/ciaa_gpio_api.h
[ciaa_gpio_api.c]: src/ciaa_gpio_api.c
[ciaa_adc_api.h]: inc/ciaa_adc_api.h
[ciaa_adc_api.c]: src/ciaa_adc_api.c
[ciaa_dac_api.h]: inc/ciaa_dac_api.h
[ciaa_dac_api.c]: src/ciaa_dac_api.c
[ciaa_pwm_api.h]: inc/ciaa_pwm_api.h
[ciaa_pwm_api.c]: src/ciaa_pwm_api.c
[ciaa_scu_api.h]: inc/ciaa_scu_api.h