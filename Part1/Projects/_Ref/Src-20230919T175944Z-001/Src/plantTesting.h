/*
 * plantTesting.h
 *
 *  Created on: 21.10.2022
 *      Author: andreas.kuhn
 */

#ifndef SRC_PLANTTESTING_H_
#define SRC_PLANTTESTING_H_

/* --- Constants ---------------------------------------------------------------------------- */


/* --- Sine class --------------------------------------------------------------------------- */

class SineStimulus
{
public:
	SineStimulus(float duration, float amplitude, float f_hz);
	void setParams(float duration, float amplitude, float f_hz);
	float getVal();

	int i=0;	// Counter (depends on Ts=0.02)
	int iMax;

	float a;
	float f;

};

/* --- stepSequence Class ------------------------------------------------------------------- */
// For frequency response measurements as well as testing robustness
class SineDisturbance
{
public:
	float f; // frequency
	float a; // amplitude

	float getVal();
};


/* --- sineSweep Class ---------------------------------------------------------------------- */

class SineSweep
{
public:
	SineSweep(float f0, float fend, float duration_s, float dT=0.05);
	float iterate();

private:
	float f0;
	float fend;
	float duration_s;
	float dT;

	float fSlope;
	unsigned int endCount;
};

/* --- stepSequence Class ------------------------------------------------------------------- */

class StepSequence
{
public:
	StepSequence(float arrA[5], float arrD[5], unsigned int fs=20);
	float iterate();

private:
	unsigned int fs;
	float arrOutputs[5];
	unsigned int arrStepTimes[5]; // t / dT
	unsigned int i = 0;


};


#endif /* SRC_PLANTTESTING_H_ */
