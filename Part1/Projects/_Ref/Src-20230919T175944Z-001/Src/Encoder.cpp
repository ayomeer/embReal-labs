/*
 * encoder.c
 *
 *  Created on: 21.10.2022
 *      Author: andreas.kuhn
 */
#include "Encoder.h"
#include "main.h"

Encoder::Encoder()
{
}

int16_t Encoder::read()
{
	return (TIM4->CNT);
}

float Encoder::getRad()
{
	int16_t count = (TIM4->CNT); // important to interpret as 16bit so sign works correctly!
	return (0.004*(float)count);
}
