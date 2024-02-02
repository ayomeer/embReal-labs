/*
 * STM32H7Led.cpp
 *
 *  Created on: Oct 2, 2023
 *      Author: ayome
 */

#include "STM32H7Led.h"

using namespace myhal; // STM32H7Led inside 'myhal' namespace (or "package")


// STM32H7Led::STM32H7Led() {} // not needed with initializer list in BlinkingLed.cpp ctor
STM32H7Led::STM32H7Led(GPIO_TypeDef* port, uint16_t pin) {
	this->port = port;
	this->pin = pin;
}


void STM32H7Led::toggleLED(){
	HAL_GPIO_TogglePin(port, pin);
}
