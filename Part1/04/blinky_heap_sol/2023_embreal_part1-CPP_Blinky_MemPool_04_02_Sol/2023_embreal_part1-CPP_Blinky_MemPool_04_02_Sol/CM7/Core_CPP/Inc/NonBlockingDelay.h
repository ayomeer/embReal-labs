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
public:
	NonBlockingDelay();
	virtual ~NonBlockingDelay();

	void initialise(const uint32_t delay);
	uint8_t checkExpiration();

protected:
	uint32_t waitTime = 0;
	uint32_t tickstart = 0;
};

}
#endif /* SRC_NONBLOCKINGDELAY_H_ */
