/*
 * LedBlink.cpp
 *
 *  Created on: 28.10.2022
 *      Author: andreas.kuhn
 */

#include "LedBlink.hpp"
#include "main.h" //Port and Pin namings

void LedBlink::blink()
{
	HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
}


