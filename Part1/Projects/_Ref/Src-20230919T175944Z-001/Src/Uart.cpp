/*
 * Uart.cpp
 *
 *  Created on: 31.10.2022
 *      Author: andreas.kuhn
 */

#include "Uart.h"
#include "Controller.h"
#include <stdint.h>


Uart* Uart::thisPointer = 0;

Uart::Uart(Controller* pController) : pC(pController)
{
	// On object creation: save pointer to itself for use in C ISR entry point (see end of this file)
	thisPointer = this;
}

void Uart::listenForNBytes(int n)
{
	HAL_UART_Receive_IT(&huart2, rxData[0].b, n);
}


bool paramFlag = 0; // about to receive series of controller parameters (Kr, Tn, Tv, Tc)--> 4 float, 16 bytes
bool refFlag = 0;   // about to receive reference value 								--> 1 float, 4 bytes
bool dirFlag = 0;	// about to receive value for direct (linearized) motor control		--> 1 float, 4 bytes
bool zFlag = 0; 	// about to receive stimulus data for SineStimulus Object			--> 3 float, 12 bytes
void Uart::onReceive()
{

	/* -- Receive Data ------------------------------------------------------ */
	if(refFlag) // Set new reference value
	{
		refFlag = 0; // reset flag
		pC->setR(rxData[0].f);

		listenForNBytes(1); // Restart listening for command
	}
	else if(paramFlag) // Set new PID parameters
	{
		paramFlag = 0; // reset flag

		// Set parameters in Controller.pid. Parameter order. Kr, Tn, Tv, Tc
		pC->pid.setParams(rxData[0].f, rxData[1].f, rxData[2].f, rxData[3].f);

		listenForNBytes(1); // Restart listening for command
	}
	else if(dirFlag == 1)
	{
		dirFlag = 0;
		pC->uC = rxData[0].f;

		listenForNBytes(1); // Restart listening for command
	}
	else if(zFlag == 1)
	{
		zFlag = 0;
		pC->zSine.setParams(rxData[0].f, rxData[1].f, rxData[2].f);
		pC->enStimulus = 1;

		listenForNBytes(1); // Restart listening for command
	}
	/* -- Receive Command ------------------------------------------------------- */
	else // normal case: receiving one byte commands
	{
		switch(rxData[0].b[0])
		{
		case 's': // stop
			pC->stop();
			listenForNBytes(1); // Restart listening for command
		break;

		case 'g': // go
			pC->run();
			listenForNBytes(1); // Restart listening for command
		break;

		case 'd': // direct motor control (testing actor linearization)
			pC->status = directCtrl;

			dirFlag = 1;
			listenForNBytes(1*4);
		break;

		case 'r': // set new r
			refFlag = 1;
			listenForNBytes(1*4); // listen for 1 float
		break;

		case 'p': // set new PID params
			paramFlag = 1;
			listenForNBytes(4*4); // listen for 4 floats (Kr, Tn, Tv, Tc)
		break;

		case 'z':
			zFlag = 1;
			listenForNBytes(3*4);
		break;
		}
	}
}


void Uart::sendDebugInfo(float y, float r, float lin, float p, float i, float d, float pwm)
{
	HAL_UART_Transmit(&huart2, (uint8_t*) &y,   4, UART_TIMEOUT);
	HAL_UART_Transmit(&huart2, (uint8_t*) &r,   4, UART_TIMEOUT);
	HAL_UART_Transmit(&huart2, (uint8_t*) &lin, 4, UART_TIMEOUT);
	HAL_UART_Transmit(&huart2, (uint8_t*) &p,   4, UART_TIMEOUT);
	HAL_UART_Transmit(&huart2, (uint8_t*) &i,   4, UART_TIMEOUT);
	HAL_UART_Transmit(&huart2, (uint8_t*) &d,   4, UART_TIMEOUT);
	HAL_UART_Transmit(&huart2, (uint8_t*) &pwm, 4, UART_TIMEOUT);
}

// Static functions
void Uart::isrWrapperRxCallback()
{
	thisPointer->onReceive();
}

// ISR Entry Point from C HAL
extern "C"
{
	void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
	{
		Uart::isrWrapperRxCallback(); // Call static wrapper and enter C++ Uart Obj from there
	}
}




// --- old functions (to be integrated into class) ---------------------------------------------------
void uart_sendEncoderCount(int16_t encoderCount)
{
	HAL_UART_Transmit(&huart2, (uint8_t*) &encoderCount, 2, UART_TIMEOUT);
}

void uart_sendFloat(float f)
{
	HAL_UART_Transmit(&huart2, (uint8_t*) &f, 4, UART_TIMEOUT);
}






