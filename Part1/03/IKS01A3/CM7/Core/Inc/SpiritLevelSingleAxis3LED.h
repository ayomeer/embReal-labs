/*
 * SpiritLevelSingleAxis3LED.h
 *
 *  Created on: Feb 3, 2024
 *      Author: ayome
 */

#ifndef SPIRITLEVELSINGLEAXIS3LED_H_
#define SPIRITLEVELSINGLEAXIS3LED_H_

#include <cstdint>
#include "AccGyroSensor.h"
#include "STM32H7led.h"

class SpiritLevelSingleAxis3LED {
public:
	SpiritLevelSingleAxis3LED();
	virtual ~SpiritLevelSingleAxis3LED();

	void init();
	void updateValues();
	void show(); 	// outpute to console and leds
	void setZero(); //

	// dependencies to other classes (compositio)
	AccGyroSensor motionSens;
	myhal::STM32H7_led LD1;
	myhal::STM32H7_led LD2;
	myhal::STM32H7_led LD3;


private:
	const int32_t threashold = 200;
	int32_t accY;
};

#endif /* SPIRITLEVELSINGLEAXIS3LED_H_ */
