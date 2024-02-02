/*
 * Uart.h
 *
 *  Created on: 28.10.2022
 *      Author: andreas.kuhn
 */

#ifndef SRC_UART_H_
#define SRC_UART_H_

constexpr int UART_TIMEOUT = 10;

#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_uart.h"

#include "Controller.h"

// Class forward declarations for classes we have pointers to
class Controller;


class Uart
{
public:
	Uart(Controller* pController);
	void listenForNBytes(int n=1);

	// live plot matlab app
	void sendDebugInfo(float y, float r, float lin, float p, float i, float d, float pwm);

	// ISR Handling
	void onReceive(); 					// ISR-triggered member function
	static void isrWrapperRxCallback(); // Static intermediate function between C-ISR and
										//  C++ member function onReceive

private:
	//uint8_t rxData[40]; 				// RX Buffer (40 = 5*4bytes = 5 floats)
	union {
		float f;
		uint8_t b[4];
	} rxData[4];

	Controller* pC;						// Ref to Controller for passing Matlab App commands

	static Uart* thisPointer; 			// C-compatible "this" pointer for ISR entry point
};

// ISR C Stuff

extern "C"
{
	extern UART_HandleTypeDef huart2;
	//HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size, uint32_t Timeout);
}

// old and obsolete (remove)
void uart_sendEncoderCount(int16_t encoderCount);
void uart_sendFloat(float f);

#endif /* SRC_UART_H_ */


