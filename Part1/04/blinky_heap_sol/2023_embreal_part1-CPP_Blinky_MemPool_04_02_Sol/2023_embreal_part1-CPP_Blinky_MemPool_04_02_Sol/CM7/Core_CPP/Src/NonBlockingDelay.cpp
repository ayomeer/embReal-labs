/*
 * NonBlockingDelay.cpp
 *
 *  Created on: Oct 2, 2023
 *      Author: ayome
 */

#include "NonBlockingDelay.h"

using namespace myhal; // NonBlockingDelay inside 'myhal' namespace (or "package")

NonBlockingDelay::NonBlockingDelay() {

}

NonBlockingDelay::~NonBlockingDelay() {
	// TODO Auto-generated destructor stub
}


void NonBlockingDelay::initialise(const uint32_t delay){
	waitTime = delay;
	tickstart = HAL_GetTick(); // "start timer" by setting reference point
}

// returns 0 if not expired and 0xFF if expired or not yet set
uint8_t NonBlockingDelay::checkExpiration(){
	if((HAL_GetTick() - tickstart) < waitTime){ // timer counting, not yet expired
		return 0;
	}
	else{ // timer expired (or not set)
		waitTime = 0;// reset waitTime
		return 0xFF;
	}
}
