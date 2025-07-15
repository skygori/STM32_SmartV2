/*
 * utils.c
 *
 *  Created on: Jul 15, 2025
 *      Author: ljy
 */


#include "utils.h"

void delay(uint32_t time_ms)
{
	HAL_Delay(time_ms);
}

uint32_t millis(void)
{
	return HAL_GetTick();
}
