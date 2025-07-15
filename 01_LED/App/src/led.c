/*
 * led.c
 *
 *  Created on: Jul 15, 2025
 *      Author: ljy
 */


#include "led.h"


#define HW_LED_MAX_CH 1

#define LED_MAX_CH 	HW_LED_MAX_CH

typedef struct
{
	GPIO_TypeDef *port;
	uint16_t pin;
	GPIO_PinState on_state;
	GPIO_PinState off_state;
} led_tbl_t;

led_tbl_t led_tbl[LED_MAX_CH] =
{
		{LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET, GPIO_PIN_SET}, // led
};

void ledOn(uint8_t ch)
{
	if(ch >= LED_MAX_CH) return;

	HAL_GPIO_WritePin(led_tbl[ch].port, led_tbl[ch].pin, led_tbl[ch].on_state);
}

void ledOff(uint8_t ch)
{
	if(ch >= LED_MAX_CH) return;

	HAL_GPIO_WritePin(led_tbl[ch].port, led_tbl[ch].pin, led_tbl[ch].off_state);
}

void ledToggle(uint8_t ch)
{
	if(ch >= LED_MAX_CH) return;

	HAL_GPIO_TogglePin(led_tbl[ch].port, led_tbl[ch].pin);
}
