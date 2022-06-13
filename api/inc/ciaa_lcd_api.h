/*
 * ciaa_lcd_api.h
 *
 *  Created on: Jun 12, 2022
 *      Author: fabri
 */

#ifndef CIAA_LCD_API_H_
#define CIAA_LCD_API_H_

#include "chip.h"
#include "ciaa_gpio_api.h"
#include "ciaa_stdlib.h"

typedef struct {
	pin_t *en;
	pin_t *rs;
	pin_t *d4;
	pin_t *d5;
	pin_t *d6;
	pin_t *d7;
} lcd_t;

typedef struct {
	lcd_t lcd;
	bool cursor;
	bool blink;
	bool bigFont;
} lcd_config_t;

void lcd_init(void);
void lcd_config_init(lcd_config_t lcd);
void lcd_put_nibble(lcd_t lcd, uint8_t nibble);
void lcd_put_command(lcd_t lcd, uint8_t cmd);
void lcd_putc(lcd_t lcd, char c);
void lcd_puts(lcd_t lcd, const char* str);
void lcd_clear(lcd_t lcd);
void lcd_go_to_xy(lcd_t lcd, uint8_t x,  uint8_t y);

static inline lcd_config_t lcd_get_default_config(void) {
	lcd_config_t config = {
		{ &LCD_EN, &LCD_RS, &LCD1, &LCD2, &LCD3, &LCD4 },
		false,
		false,
		false
	};
	return config;
}

static inline lcd_t lcd_get_from_config(lcd_config_t config) {
	return config.lcd;
}

#endif /* CIAA_LCD_API_H_ */
