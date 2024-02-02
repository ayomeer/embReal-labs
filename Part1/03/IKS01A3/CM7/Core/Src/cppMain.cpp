#include "cppMain.h"
#include "main.h"
#include <iostream>
//#include <cstdint>
#include "AccGyroSensor.h"

// global accelerator variables
int32_t gyroX;
int32_t gyroY;
int32_t gyroZ;

int32_t accX;
int32_t accY;
int32_t accZ;

void cppMain(){

	AccGyroSensor motionSens;
	motionSens.initSensor();

	std::cout << "Outputting Gyro Values to VCP \n\r";

	while(1){
		if(HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin)){
			motionSens.Acc.setZero();
			motionSens.Gyro.setZero();
		}

		motionSens.updateValues();
		motionSens.Gyro.getValues(&gyroX, &gyroY, &gyroZ);
		motionSens.Acc.getValues(&accX, &accY, &accZ);

		std::cout << "Gyro Values \n\r";
		std::cout << "X: " << gyroX << "\n\r";
		std::cout << "Y: " << gyroY << "\n\r";
		std::cout << "Z: " << gyroZ << "\n\r";
		std::cout << "\n\r";

		std::cout << "Acc Values \n\r";
		std::cout << "X: " << accX << "\n\r";
		std::cout << "Y: " << accY << "\n\r";
		std::cout << "Z: " << accZ << "\n\r";
		std::cout << "\n\r";

		HAL_Delay(100);
	}
}


