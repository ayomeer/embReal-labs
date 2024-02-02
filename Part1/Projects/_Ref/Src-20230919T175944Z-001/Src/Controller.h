/*
 * controlLoop.h
 *
 *  Created on: 29.11.2022
 *      Author: andreas.kuhn
 *
 *  Description:
 *  'Mediator'-file connecting the subcomponents of the controller software. Implements feedback loops structure
 *  and provides functions for controlling the program flow
 */

#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_

// Includes for member objects of other classes
#include "Pwm.h"
#include "Encoder.h"
#include "PID.h"
#include "Uart.h"
#include "plantTesting.h"

constexpr float y_max = 2.6; //~= 150°

enum{
	 disabled 	= 0,	// controller disabled, output set to 0
	 enabled  	= 1,	// controller active
	 directCtrl = 2 	// special direct motor control mode for testing actor linearization
};

// Class forward declarations for classes we have pointers to
class Uart;


class Controller
{
public: 
	Controller();

	// Member objects
	Encoder rotaryEnc;
	Pwm motorEsc;
	PID pid;
	SineStimulus zSine;

	void runControlLoop();			// implements controller structure
	void directMotorCtrl();

	// program flow control
	int status = disabled;
	bool enStimulus = 0;			// enable stimulus (for frequency response measurement)
	void stop(); 					// stops execution of control loop and sets pwm output to 0
	void run();						// enable timer triggering control loop execution (status setter)

	// setters
	void setR(float r_new);

	// Control loop signals
	float r = 0;
	float rLim;
	float y;
	float uP;
	float uI;
	float uD;
	float uC; // remove?
	float uPlantLin;
	float uActorLin;
	int uPwm;

	// Disturbance Signal
	float uZ = 0;

	// live plot
	bool newValsFlag = 0;


	// pointer management
	void setRefUart(Uart* uartPointer);				// Link Uart object to this Controller object
													// (needed because of bidirectional association)
	// Associated ISR
	void onTick(); 									// ISR triggered member function
	static void isrWrapperTIM16PeriodElapsed(); 	// Static intermediate function between C-ISR and
													// C++ member functions
private:
	// Pointers to other objects
	Uart* pUart = nullptr;

	// C-compatible "this" pointer or ISR entry point
	static Controller* thisPointer;
};

#endif /* SRC_CONTROLLER_H_ */
