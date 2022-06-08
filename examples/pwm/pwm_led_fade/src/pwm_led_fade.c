/*
===============================================================================
 Name        : pwm_led_fade.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "ciaa_pwm_api.h"
#include "ciaa_stdlib.h"

int main(void) {
	/* Duty variable */
	uint8_t duty_percent = 0;
	/* Fade direction */
	bool direction = false;
	/* Update System Clock */
    SystemCoreClockUpdate();
    /* Enable PWM */
    pwm_init();
    /* Enable output on PWM1 */
    pwm_set_output_pin(PWM1);
    /* Set duty cycle */
    pwm_set_duty_percent(PWM1, duty_percent);
    /* Start PWM */
    pwm_start();

    while(1) {
    	/* If direction is up */
    	if(direction) {
    		/* Increment duty */
    		pwm_set_duty_percent(PWM1, duty_percent++);
    		/* Check if it's necessary to change direction */
    		if(duty_percent == 100) { direction = false; }
    	}
    	else {
    		/* Decrement duty */
    		pwm_set_duty_percent(PWM1, duty_percent--);
    		/* Check if it's necessary to change direction */
    		if(duty_percent == 0) { direction = true; }
    	}
    	/* Wait for 10 ms */
    	sleep_ms(10);
    }
    return 0 ;
}
