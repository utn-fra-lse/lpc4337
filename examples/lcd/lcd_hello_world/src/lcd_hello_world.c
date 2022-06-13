/*
===============================================================================
 Name        : lcd_hello_world.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "ciaa_lcd_api.h"

int main(void) {

    /* Read clock settings and update SystemCoreClock variable */
    SystemCoreClockUpdate();
    /* Get default LCD configuration */
    lcd_config_t config = lcd_get_default_config();
    /* Get LCD pins struct */
    lcd_t lcd = lcd_get_from_config(config);
    /* Initialize LCD */
    lcd_init();
    /* Clear screen */
    lcd_clear(lcd);
    /* Print string in LCD */
    lcd_puts(lcd, "Hello world!");

    while(1);

    return 0 ;
}
