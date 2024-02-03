/*
 * SpiritLevelSingleAxis3LED.cpp
 *
 *  Created on: Feb 3, 2024
 *      Author: ayome
 */

#include "SpiritLevelSingleAxis3LED.h"
#include "main.h" // for creating LED objects with pin names
#include <iostream> // for console output
#include <map>

SpiritLevelSingleAxis3LED::SpiritLevelSingleAxis3LED()
	: LD1(LD1_GPIO_Port, LD1_Pin), LD2(LD2_GPIO_Port, LD2_Pin), LD3(LD3_GPIO_Port, LD3_Pin)
{

}

SpiritLevelSingleAxis3LED::~SpiritLevelSingleAxis3LED() {

}

void SpiritLevelSingleAxis3LED::init(){
	// connect LED objects to led pins
	this->motionSens.initSensor();
}


void SpiritLevelSingleAxis3LED::updateValues(){
	// get new values from sensor HAL into
	this->motionSens.updateValues(); // tell sensor HAL to fetch new measurement
	this->motionSens.Acc.getValues(nullptr, &this->accY, nullptr); // get the new values
}

void SpiritLevelSingleAxis3LED::show(){
	// console output

	std::cout << "Y Acc: " << this->accY << "\n\r";
	std::cout << "Y Acc Min: " << motionSens.Acc.Ystats["Min"] << "\n\r";
	std::cout << "Y Acc Avg: " << motionSens.Acc.Ystats["Avg"] << "\n\r";
	std::cout << "Y Acc Max: " << motionSens.Acc.Ystats["Max"] << "\n\r";
	std::cout << "\n\r";

	// led output
	if(this->accY < -(this->threashold)){
		this->LD1.setLED();
		this->LD2.unsetLED();
		this->LD3.unsetLED();
	}
	else if(this->accY < (this->threashold)){
		this->LD1.unsetLED();
		this->LD2.setLED();
		this->LD3.unsetLED();
	}
	else { // accY > threashold
		this->LD1.unsetLED();
		this->LD2.unsetLED();
		this->LD3.setLED();
	}
}

void SpiritLevelSingleAxis3LED::setZero(){
	this->motionSens.Acc.setZero();
	this->motionSens.Gyro.setZero();
}
