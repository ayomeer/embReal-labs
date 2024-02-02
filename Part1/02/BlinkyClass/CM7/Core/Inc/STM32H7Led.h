/*
 * STM32H7Led.h
 *
 *  Created on: Oct 2, 2023
 *      Author: ayome
 */

#ifndef SRC_STM32H7LED_H_
#define SRC_STM32H7LED_H_

#include "stm32h7xx_hal.h" // for GPIO defs


namespace myhal{

class STM32H7Led {
private:
	// accessible to functions inheriting this class
	GPIO_TypeDef* port;
	uint16_t pin;

public:
	STM32H7Led();
	STM32H7Led(GPIO_TypeDef* port, uint16_t pin);
	void setPortPin(GPIO_TypeDef* port, uint16_t pin); // needed for creation on heap
	void toggleLED();


};

}
#endif /* SRC_STM32H7LED_H_ */
