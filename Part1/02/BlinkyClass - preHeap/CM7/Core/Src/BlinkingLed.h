/*
 * BlinkingLed.h
 *
 *  Created on: Oct 2, 2023
 *      Author: ayome
 */

#ifndef SRC_BLINKINGLED_H_
#define SRC_BLINKINGLED_H_

// include classes to inherit from
#include "STM32H7Led.h"
#include "NonBlockingDelay.h"

// HAL not included, so need cstdint for uint16_t
#include <cstdint>



class BlinkingLed : myhal::STM32H7Led, myhal::NonBlockingDelay {
private:
	float_t frequency = 1;  // Hz
	uint8_t dutyCycle = 50; // %
public:
	// ctors
	BlinkingLed(GPIO_TypeDef* port, uint16_t pin);
	BlinkingLed(GPIO_TypeDef* port, uint16_t pin, float_t frequency, uint8_t dutyCycle);
	// setters
	void setDutyCycle(const uint8_t dutyCycle);
	void setFrequency(const float frequency);

	// call to check timer and blink
	void processBlinking();
};

#endif /* SRC_BLINKINGLED_H_ */
