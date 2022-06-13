/*
 * ciaa_lcd_api.c
 *
 *  Created on: Jun 13, 2022
 *      Author: fabri
 */

#include "ciaa_lcd_api.h"

void lcd_init(void) {
	lcd_config_init(lcd_get_default_config());
}

void lcd_config_init(lcd_config_t config) {
	/* Get LCD struct */
	lcd_t lcd = lcd_get_from_config(config);
	/* Get pointer to the pointer of the first pin in struct */
	pin_t **p = &(lcd.en);
	/* Get the number of elements to loop through */
	uint8_t len = sizeof(lcd) / sizeof(pin_t*);
	/* Loop from first to last element */
	for(uint8_t i = 0; i < len; i++) {
		/* Get pointer to the pin */
		pin_t *pin = *p;
		/* Initialize pin */
		gpio_set_dir_out(*pin);
		/* Increment pointer to the next pin */
		p++;
	}

	/* Function set: 8 bits interface length */
	lcd_put_command(lcd, 0x03);
	/* Wait for 4.1 ms */
	sleep_ms(5);
	/* Function set: 8 bits interface length */
	lcd_put_command(lcd, 0x03);
	/* Wait for 100 us */
	sleep_us(100);
	/* Function set: 8 bits interface length */
	lcd_put_command(lcd, 0x03);
	/* Now the other instructions can be send */

	/* Function set: set interface to 4 bits length */
	lcd_put_command(lcd, 0x02);
	/* Function set: interface is 4 bits length */
	lcd_put_command(lcd, 0x02);
	/* Function set: two row display and 5x7 font */
  	lcd_put_command(lcd, 0x08 | (config.bigFont << 2));
  	/* Display on, cursor off, blink off */
  	lcd_put_command(lcd, 0x00);
  	lcd_put_command(lcd, (3 << 2) | (config.cursor << 1) | config.blink);
  	/* Input set command: increment cursor */
  	lcd_put_command(lcd, 0x00);
  	lcd_put_command(lcd, 0x06);
}

void lcd_put(lcd_t lcd, uint8_t nibble) {

	pin_t *en = lcd.en;

	/* Get pointer to the pointer of the first pin in struct */
	pin_t **p = &(lcd.d4);
	/* Get the number of elements to loop through */
	uint8_t len = sizeof(lcd) / sizeof(pin_t*);
	/* Loop from third to last element */
	for(uint8_t i = 0; i < len - 2; i++) {
		/* Get pointer to the pin */
		pin_t *pin = *p;
		/* Set value to pin */
		gpio_put(*pin, (nibble & (1 << i))? true : false);
		/* Increment pointer to the next pin */
		p++;
	}

	gpio_set(*en);
	sleep_us(40);
	gpio_clr(*en);
}

void lcd_put_command(lcd_t lcd, uint8_t cmd) {

	pin_t *rs = lcd.rs;

	gpio_clr(*rs);
	lcd_put(lcd, cmd);
}

void lcd_putc(lcd_t lcd, char c) {

	pin_t *rs = lcd.rs;

	gpio_set(*rs);
	for(uint8_t nibble = 0; nibble < 2; nibble++) {
		uint8_t n = (nibble)? c & 0x0f : c >> 4;
		lcd_put(lcd, n);
	}
}

void lcd_puts(lcd_t lcd, const char* str) {

	while(*str) {
		lcd_putc(lcd, *str);
		str++;
	}
}

void lcd_clear(lcd_t lcd) {
	lcd_put_command(lcd, 0x00);
	lcd_put_command(lcd, 0x01);
	sleep_ms(4);
}

void lcd_go_to_xy(lcd_t lcd, uint8_t x, uint8_t y) {

	uint8_t aux;
	if(y == 0) {
		aux = 0x40 + x;
		lcd_put_command(lcd, aux >> 4);
		lcd_put_command(lcd, aux & 0x0F);
	}
	else if (y == 1) {
		aux = 0xC0 + x;;
		lcd_put_command(lcd, aux >> 4);
		lcd_put_command(lcd, aux & 0x0F);
	}
}
