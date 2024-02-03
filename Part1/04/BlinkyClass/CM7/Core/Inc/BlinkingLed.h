/*
 * BlinkingLed.h
 *
 *  Created on: Oct 2, 2023
 *      Author: ayome
 */

#ifndef SRC_BLINKINGLED_H_
#define SRC_BLINKINGLED_H_

// include classes to inherit from
#include "stm32h7xx_hal.h" // for GPIO defs
#include "STM32H7Led.h"
#include "NonBlockingDelay.h"

// HAL not included, so need cstdint for uint16_t
#include <cstdint>


// need to specify this |  to be able to use inherited function directly through
//                      v                                pointer of derived class
class BlinkingLed : protected myhal::STM32H7Led, myhal::NonBlockingDelay {
public:
	// ctors and dtor
	BlinkingLed();
	BlinkingLed(GPIO_TypeDef* port, uint16_t pin);
	BlinkingLed(GPIO_TypeDef* port, uint16_t pin, float_t frequency, uint8_t dutyCycle);
	virtual ~BlinkingLed();

	// setters
	void setDutyCycle(const uint8_t dutyCycle);
	void setFrequency(const float frequency);
	void setPinPort(GPIO_TypeDef* port, uint16_t pin);

	void setPinPort();
	// call to check timer and blink
	void processBlinking();

private:
	float_t frequency = 1;  // Hz
	uint8_t dutyCycle = 50; // %

};

#endif /* SRC_BLINKINGLED_H_ */
