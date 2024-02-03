/*
 * AccGyroSensor.h
 *
 *  Created on: Oct 9, 2023
 *      Author: ayome
 *
 *      Class combining both functionalities of the Accelerometer / Gyro Sensor-Chip
 */

#ifndef ACCGYROSENSOR_H_
#define ACCGYROSENSOR_H_

#include "IKS01A3_Motion.h"
#include <cstdint>

class AccGyroSensor {
public:
	// composition: AccGyroSensor has /vital/ component IKS01a3_Motion
	IKS01A3_Motion Acc; // public for direct access w/o getter/setter
	IKS01A3_Motion Gyro;

	AccGyroSensor();
	virtual ~AccGyroSensor();

	void initSensor();
	void updateValues();


private:
	const uint32_t INSTANCE=0;
	const uint32_t FUNCTION_INIT_ACC_GYRO = MOTION_ACCELERO | MOTION_GYRO; // | --> 'or'
	const uint32_t FUNCTION_ACC = MOTION_ACCELERO;
	const uint32_t FUNCTION_GYRO = MOTION_GYRO;
};

#endif /* ACCGYROSENSOR_H_ */
