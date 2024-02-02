#include "plantTesting.h"
#include "pwm.h"
#include "main.h"
#include "math.h"

constexpr float PI = 3.14159;

unsigned int i = 0;
unsigned int j = 0;


/* --- Sine class --------------------------------------------------------------------------- */
SineStimulus::SineStimulus(float duration, float amplitude, float f_hz) :
		iMax(duration/0.02), a(amplitude), f(f_hz)
{
}

void SineStimulus::setParams(float duration, float amplitude, float f_hz)
{
	i = 0; // reset counter variable

	iMax = duration/0.02;
	a = amplitude;
	f = f_hz;
}

float SineStimulus::getVal()
{
	if(i<iMax)
	{
		i++;
		return a*sin(2*M_PI*f*i*0.02); // 0.02 = Ts
	}
	else
	{
		return 0;
	}
}

/* --- SineSweep class ----------------------------------------------------------------------- */
SineSweep::SineSweep(float f0, float fend, float duration_s, float dT) :
		f0(f0),
		fend(fend),
		duration_s(duration_s),
		dT(dT)
{
	// calculate frequency slope from ctor parameters
	endCount = (int)(duration_s*(1/dT));
	fSlope = (fend-f0)/endCount; // dFrequency/sample
}


// Arguments: 	None
// Return: 		Sweep signal or (-1) if done
float SineSweep::iterate()
{
	j++;
	if(j < endCount)
	{
		return sin(2*PI*(f0+fSlope*j)*(j*dT));
	}
	else
	{// Done
		return -1; // End-Code
	}
}

/* --- stepSequence Class ------------------------------------------------------------------- */

StepSequence::StepSequence(float arrR[5], float arrD[5], unsigned int fs)
{
	// Initialize arrays
	for(int i = 0; i < 5; ++i)
	{
		arrOutputs[i] = arrR[i];
	}

	for(int i = 0; i < 5; ++i)
	{
		arrStepTimes[i] = arrD[i]*fs;
	}
}

float StepSequence::iterate()
{
	i++;
	if(i < arrStepTimes[0]){return arrOutputs[0];}
	else if(i >= arrStepTimes[4]){return -1;} // End Code
	else if(i >= arrStepTimes[3]){return arrOutputs[4];}
	else if(i >= arrStepTimes[2]){return arrOutputs[3];}
	else if(i >= arrStepTimes[1]){return arrOutputs[2];}
	else if(i >= arrStepTimes[0]){return arrOutputs[1];}
	else {return 0;}
}


/* --- Usage examples -------------------------------------------------------------------------

r = stepSeq.iterate();
if(r == -1) // look for End-Code -1
{
	rxData[0] = '0'; // go default mode
	r = 0;
}



*/
