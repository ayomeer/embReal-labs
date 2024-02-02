/*
 * encoder.h
 *
 *  Created on: 21.10.2022
 *      Author: andreas.kuhn
 */

#ifndef SRC_ENCODER_H_
#define SRC_ENCODER_H_

#define ENCODER_OFFSET 32768
#define ENCODER_CRITICAL 600 // ~120deg

#define ENC2RAD 0.004
#define RAD2ENC 249 //249.1121

#include <stdint.h>

class Encoder
{
public:
	Encoder();
	int16_t read();
	float getRad();
};



#endif /* SRC_ENCODER_H_ */
