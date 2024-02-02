/*
 * controller.h
 *
 *  Created on: 26.10.2022
 *      Author: andreas.kuhn
 */

#ifndef SRC_PID_H_
#define SRC_PID_H_

#include <stdint.h>
#include <string.h>

constexpr float Ts = 0.02; // Sampling time used in PID parameter calculations

// Parameters actorLin
constexpr float a = 0.259;
constexpr float b = 0.0482;

// Plant Parameters
constexpr float J = 0.0017;
constexpr float w0_2 = 48; // Angepasst für lin

/* --- DTF class: Discrete transfer function --------------------------------------------------------- */
// Implements I and D term as their z-transformed TFs
class DTF
{
public:
	DTF();
	void setCoefs(float new_b1, float new_b0, float new_a1, float new_a0);
	float eval(float e);

	// coefs
	float b1; // b1*z + b0
	float b0; // ---------
	float a1; //   z + a0
	float a0;

	// internal states
	float ukm1 = 0;
	float ekm1 = 0;
private:

};

/* --- PID class --------------------------------------------------------------------------------------- */

class PID
{
	public:
		PID();

		// setter
		void setParams(float Kr, float Tn, float Tv, float Tc);

		// Subsystems of parallel PID structure
		float kr;
		DTF i;					// discrete UTF I-Term
		DTF d;	 				// discrete UTF D-Term
		float getP(float x);
		float getI(float x);
		float getD(float x);

	private:

};



float rateLimit(float r);

#endif /* SRC_PID_H_ */
