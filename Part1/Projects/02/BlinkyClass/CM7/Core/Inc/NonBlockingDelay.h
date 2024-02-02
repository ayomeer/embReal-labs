/*
 * NonBlockingDelay.h
 *
 *  Created on: Oct 2, 2023
 *      Author: ayome
 */

#ifndef SRC_NONBLOCKINGDELAY_H_
#define SRC_NONBLOCKINGDELAY_H_

#include <cstdint>
#include "stm32H7xx_hal.h" // for HAL_GetTick()

namespace myhal{

class NonBlockingDelay {
private:
	// accessible to functions inheriting this class
	uint32_t waitTime = 0;
	uint32_t tickstart = 0;

public:
	NonBlockingDelay();
	void initialize(const uint32_t delay);
	uint8_t checkExpiration();
};

}
#endif /* SRC_NONBLOCKINGDELAY_H_ */
