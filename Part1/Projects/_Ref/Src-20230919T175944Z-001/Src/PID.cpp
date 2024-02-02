/*
 * controller.cpp
 *
 *  Created on: 26.10.2022
 *      Author: andreas.kuhn
 */
#include "PID.h"

#include "math.h"







/* --- DTF Class: discrete transfer function ------------------------------------------------------ */
DTF::DTF()
{}

void DTF::setCoefs(float new_b1, float new_b0, float new_a1, float new_a0)
{
	b1 = new_b1;
	b0 = new_b0;
	a1 = new_a1;
	a0 = new_a0;
}

float DTF::eval(float ek)
{
	float uk = -a0*ukm1 + b1*ek + b0*ekm1;

	// update state for next call
	ukm1 = uk;
	ekm1 = ek;
	return uk;
}

/* --- PID Class --------------------------------------------------------------- */
PID::PID()
{}

void PID::setParams(float Kr, float Tn, float Tv, float Tc)
{
	// calculate tf(z) coefs (tustin)  and save to corresponding DTF object
	// Note: Argument parameters represent parallel PID model

	// P-Term
	kr = Kr;

	// I-Term tf structure:
	// b1*z + b0
	// ---------
	//   z - 1    <-- fixed

	i.b1 = Ts/(2*Tn); 		// symmetric due to tustin approximation
	i.b0 = Ts/(2*Tn);
	i.a1 = 1;
	i.a0 = -1;

	// D-Term tf structure:
	// b1*z + b0
	// ---------
	//   z + a0   <-- a1 = 1 fixed

	d.b1 = Tv/(Tc+Ts/2);  	// symmetric due to tustin approximation
	d.b0 = -Tv/(Tc+Ts/2);
	d.a1 = 1;
	d.a0 = -(Tc-Ts/2)/(Tc+Ts/2);
}


float PID::getP(float x)
{
	return kr*x;
}

float PID::getI(float x)
{
	return i.eval(x); // evaluate transfer discrete function
}

float PID::getD(float x)
{
	return d.eval(x);
}


/* ---  Helper functions (TODO: move to controller.cpp!) -------------------------------------------- */
//constexpr float adjOffset = 0.0035;

float PID::plantLin(float y_rad)
{
	return sin(y_rad)*w0_2;
}

constexpr float adjScale = 1.29;// 7V adjustment
float PID::actorLin(float u)
{
	float M = u*J;

	if(M>0) // avoid complex solutions from negative input
		return ((-b/(2*a) + sqrt(M/a + pow(b,2)/(2*pow(a,2)))))*adjScale;
	else
		return 0;
}





