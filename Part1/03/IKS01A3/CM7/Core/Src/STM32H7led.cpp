/*
 * STM32H7led.cpp
 *
 *  Created on: Mar 13, 2022
 *      Author: dominique.kunz
 */

#include "STM32H7led.h"

myhal::STM32H7_led::STM32H7_led(void) {
}

myhal::STM32H7_led::STM32H7_led(GPIO_TypeDef *Port,uint16_t Pin) {
	STM32H7_led::Port=Port;
	STM32H7_led::Pin=Pin;
}


myhal::STM32H7_led::~STM32H7_led() {
}

void myhal::STM32H7_led::toggleLED(void) {
  HAL_GPIO_TogglePin(this->Port, this->Pin);
}


void myhal::STM32H7_led::setLED(){
	HAL_GPIO_WritePin(this->Port, this->Pin, GPIO_PIN_SET);
}


void myhal::STM32H7_led::unsetLED(){
	HAL_GPIO_WritePin(this->Port, this->Pin, GPIO_PIN_RESET);
}
