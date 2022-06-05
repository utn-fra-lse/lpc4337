/*
 * EDU_CIAA.c
 *
 *  Created on: Jun 2, 2022
 *      Author: fabri
 */

/* CIAA GPIO API includes */
#include <ciaa_gpio_api.h>

/* Pin definitions */
pin_t LEDR = { 2, 0, 5, 0, SCU_MODE_FUNC4 };
pin_t LEDG = { 2, 1, 5, 1, SCU_MODE_FUNC4 };
pin_t LEDB = { 2, 2, 5, 2, SCU_MODE_FUNC4 };
pin_t LED1 = { 2, 10, 0, 14, SCU_MODE_FUNC0 };
pin_t LED2 = { 2, 11, 1, 11, SCU_MODE_FUNC0 };
pin_t LED3 = { 2, 12, 1, 12, SCU_MODE_FUNC0 };

pin_t TEC1 = { 1, 0, 0, 4, SCU_MODE_FUNC0 };
pin_t TEC2 = { 1, 1, 0, 8, SCU_MODE_FUNC0 };
pin_t TEC3 = { 1, 6, 1, 9, SCU_MODE_FUNC0 };
pin_t TEC4 = { 1, 6, 1, 9, SCU_MODE_FUNC0 };

pin_t GPIO0 = { 6, 1, 3, 0, SCU_MODE_FUNC0 };
pin_t GPIO1 = { 6, 4, 3, 3, SCU_MODE_FUNC0 };
pin_t GPIO2 = { 6, 5, 3, 4, SCU_MODE_FUNC0 };
pin_t GPIO3 = { 6, 7, 5, 15, SCU_MODE_FUNC4 };
pin_t GPIO4 = { 6, 8, 5, 16, SCU_MODE_FUNC4 };
pin_t GPIO5 = { 6, 9, 3, 5, SCU_MODE_FUNC0 };
pin_t GPIO6 = { 6, 10, 3, 6, SCU_MODE_FUNC0 };
pin_t GPIO7 = { 6, 11, 3, 7, SCU_MODE_FUNC0 };
pin_t GPIO8 = { 6, 12, 2, 8, SCU_MODE_FUNC0 };
