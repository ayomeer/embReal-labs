#include "cppMain.h"
#include "main.h"
#include <iostream>
//#include <cstdint>
#include "AccGyroSensor.h"
#include "STM32H7led.h"
#include "SpiritLevelSingleAxis3LED.h"

// global accelerator variables
int32_t gyroX;
int32_t gyroY;
int32_t gyroZ;

int32_t accX;
int32_t accY;
int32_t accZ;

#define SPIRITLEVEL // switch between simple sensor console output and spirit-level application

void cppMain(){
	#ifdef SPIRITLEVEL
	SpiritLevelSingleAxis3LED spiritLevel; // /!\ no empty () allowed for object instantiation
	spiritLevel.init();

	while(1){
		if(HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin)){
			spiritLevel.setZero();
		}

		spiritLevel.updateValues();
		spiritLevel.show();

		HAL_Delay(100);
	}

	#else
	myhal::STM32H7_led led1(LD1_GPIO_Port, LD1_Pin);

	AccGyroSensor motionSens;
	motionSens.initSensor();

	std::cout << "Outputting Gyro Values to VCP \n\r";

	while(1){
		// check for button press -> set zero
		if(HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin)){
			motionSens.Acc.setZero();
			motionSens.Gyro.setZero();
		}

		// get new values from sensor HAL
		motionSens.updateValues();
		motionSens.Gyro.getValues(&gyroX, &gyroY, &gyroZ);
		motionSens.Acc.getValues(&accX, &accY, &accZ);

		// outpute values to console
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
	#endif
}


