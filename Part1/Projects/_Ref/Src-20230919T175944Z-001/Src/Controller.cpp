/*
 * controlLoop.cpp
 *
 *  Created on: 29.11.2022
 *      Author: andreas.kuhn
 *
 *  Description:
 *  'Mediator'-file connecting the subcomponents of the controller software. Implements feedback loops structure
 *  and provides functions for controlling the program flow
 */

#include "Controller.h"
#include "math.h"

extern TIM_HandleTypeDef htim16;


// Helper function prototypes
float capOutput(float u);	// Keep outpute in 0..1 range
float rateLimit(float r);
float actorLin(float u); 	// Linearize actor (motor torque-curve)
float plantLin(float y); 	// Linearization of plant ("exact Linearization")


Controller* Controller::thisPointer = 0;

Controller::Controller() :
	rotaryEnc(), motorEsc(), pid(), zSine(0, 0, 0)
{
	// set default params
	pid.setParams(25, 5, 0.2, 0.05);

	// On object creation: save pointer to itself for use in C ISR entry point
	thisPointer = this;
}

float e;	// error signal in radiants

void Controller::runControlLoop()
{
	// read sensors
	y = rotaryEnc.getRad();

	// safety shutdown
	if(y > y_max)
	{
		this->status = disabled; // exit
		motorEsc.setPWM(0);
	}
	else
	{
		rLim = rateLimit(r);
		e = rLim - y;

		// get PID values
		uP = e*pid.kr;
		uI = pid.getI(e*pid.kr);
		uD = pid.getD(e*pid.kr);

		/* Frequency Respone Sweep Measurement */
		if(enStimulus) // check flag set by UART onReceive <-- MatlabApp
		{
			uZ = zSine.getVal();
			zSine.f += 0.001;
		}

		// plant extensions: linearization
		uPlantLin = plantLin(y);
		uActorLin = actorLin(uPlantLin + uP + uI + uD);

		// set new actor output
		uPwm = motorEsc.setPWM(uActorLin); // Rescale u for pwm and send to ESC

		// send new data to uart for live plot (move this to main using flag)
		newValsFlag = 1;
		//pUart->sendDebugInfo(y, r_lim, uPlantLin, uC);
	}
}

// direct motor control (testing actor linearization)
void Controller::directMotorCtrl()
{
	uActorLin = actorLin(uC);
	motorEsc.setPWM(uActorLin);
}

// program flow control
void Controller::stop()
{
	status = disabled;
	//HAL_TIM_Base_Stop_IT(&htim16); 					// Start Sampling Timer
	enStimulus = 0;
	uZ = 0;

	// reset discrete transfer function states
	pid.i.ukm1 = 0;
	pid.d.ukm1 = 0;

	motorEsc.setMin();
}

void Controller::run()
{
	status = enabled;
	//HAL_TIM_Base_Start_IT(&htim16); 					// Start Sampling Timer
}

// setters
void Controller::setR(float r_new)
{
	r = r_new;
}


void Controller::setRefUart(Uart* uartPointer)
{
	pUart = uartPointer;
}

void Controller::onTick()
{
	switch(status)
	{
	case enabled:
		runControlLoop();
	break;

	case directCtrl:
		directMotorCtrl();
	break;

	case disabled:

	break;
	}
}

// Static ISR entry point function
void Controller::isrWrapperTIM16PeriodElapsed()
{
	// call object member function using C-ified 'this'-pointer
	thisPointer->Controller::onTick();

}

/* --- Controller adjacent helper functions ------------------------------------------------------- */

float r_past = 0;
float r_diff;
float ret;

float slewRate = 0.25/50; // 0.5rad/s w/ dT= 0.05s

float rateLimit(float r)
{
	r_diff = r-r_past;
	if(r_diff > slewRate)
		ret = r_past + slewRate;
	else if(r_diff < -slewRate)
		ret = r_past - slewRate;
	else
		ret = r;

	r_past = ret;
	return ret;
}

float capOutput(float u)
{
	if(u > 1){return 1;}
	else if(u < 0){return 0;}

	return u;
}

/* ---  Helper functions (TODO: move to controller.cpp!) -------------------------------------------- */

float plantLin(float y_rad)
{
	return sin(y_rad)*w0_2;
}

constexpr float adjScale = 1.29;// 7V adjustment
float actorLin(float u)
{
	float M = u*J;

	if(M>0) // avoid complex solutions from negative input
		return ((-b/(2*a) + sqrt(M/a + pow(b,2)/(2*pow(a,2)))))*adjScale;
	else
		return 0;
}

