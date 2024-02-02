/*
 * AccGyroSensor.cpp
 *
 *  Created on: Oct 9, 2023
 *      Author: ayome
 */

#include "AccGyroSensor.h"

AccGyroSensor::AccGyroSensor() {}

AccGyroSensor::~AccGyroSensor() {}


void AccGyroSensor::initSensor(){
	Gyro.init(INSTANCE, FUNCTION_ACC | FUNCTION_GYRO);
}

void AccGyroSensor::updateValues(){
	Gyro.updateValues(INSTANCE, FUNCTION_GYRO);
	Acc.updateValues(INSTANCE, FUNCTION_ACC);
}
