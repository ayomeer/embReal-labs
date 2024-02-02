/*
 * pwm.c
 *
 *  Created on: 21.10.2022
 *      Author: andreas.kuhn
 */

#include "Pwm.h"
#include "stm32l4xx_hal.h"

// Ctor
Pwm::Pwm(int minCount, int maxCount, int deadzoneCount) :
		minCount(minCount), maxCount(maxCount), deadzoneCount(deadzoneCount)
{
	rangeCount = (maxCount - minCount) - deadzoneCount;
}

int Pwm::setPWM(float u)
{
	int u_pwm = (int) (PWM_MIN + u*rangeCount);
	(TIM1->CCR1) = u_pwm; 	// set timer register
	return u_pwm; 			// return the value that was set
}

void Pwm::setMin()
{
	(TIM1->CCR1) = PWM_MIN;
}
