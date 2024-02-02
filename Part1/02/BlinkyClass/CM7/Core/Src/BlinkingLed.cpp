
/*
 * BlinkingLed.cpp
 *
 *  Created on: Oct 2, 2023
 *      Author: ayome
 */

#include "BlinkingLed.h"

// blank ctor for creation/allocation on heap
BlinkingLed::BlinkingLed() {}

// Minimum ctor (use defaults for frequency, dutyCycle)
BlinkingLed::BlinkingLed(GPIO_TypeDef* port, uint16_t pin)
	: STM32H7Led(port, pin) {}

// Full ctor
BlinkingLed::BlinkingLed(GPIO_TypeDef* port, uint16_t pin, float_t frequency, uint8_t dutyCycle)
	: STM32H7Led(port, pin), frequency(frequency), dutyCycle(dutyCycle) {}

// setters
void BlinkingLed::setDutyCycle(const uint8_t dutyCycle){
	this->dutyCycle = dutyCycle;
}
void BlinkingLed::setFrequency(const float frequency){
	this->frequency = frequency;
}

void BlinkingLed::processBlinking(){
	if(checkExpiration()){ // timer expired: do stuff
		initialize((uint32_t)(1/frequency*1000));
		toggleLED();
	}
	else { // not yet expired: do nothing

	}
}

