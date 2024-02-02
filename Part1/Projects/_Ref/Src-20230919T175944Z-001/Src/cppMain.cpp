/*
 * EventLoop.cpp
 *
 *  Created on: 28.10.2022
 *      Author: andreas.kuhn
 */

#include "cppMain.hpp"
#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_tim.h"

#include "Controller.h"
#include "Uart.h"

#include "main.h"

extern TIM_HandleTypeDef htim16;

// Main Cpp event loop to run application
void cppMain()
{
	// Create objects
	Controller ctrLoop;
	Uart usart2(&ctrLoop);
	ctrLoop.setRefUart(&usart2);

	// Start listening on Uart
	usart2.listenForNBytes(1);

	while(1)
	{
		if(ctrLoop.newValsFlag)
		{
			ctrLoop.newValsFlag = 0;

			usart2.sendDebugInfo(
					ctrLoop.y,
					ctrLoop.rLim,
					ctrLoop.uPlantLin,//ctrLoop.uC,
					ctrLoop.uP,
					ctrLoop.uI,
					ctrLoop.uD,
					(float)ctrLoop.uPwm
			);
		}
	}
}

// --- C Entry Points -----------------------------------------------------------------------------
extern "C"
{
	void cppMainC()
    {
        cppMain();
    }

    // Callback function for ALL 'timer elapsed' events (This is why this ISR is kept in cppMain)
	void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
	{
	  // Check which of the timers triggered this callback
		if(htim == &htim16) // Timer16 = Control loop Timer
			Controller::isrWrapperTIM16PeriodElapsed(); // call controlLoop isrWrapper to enter C++ Object

	}
}



