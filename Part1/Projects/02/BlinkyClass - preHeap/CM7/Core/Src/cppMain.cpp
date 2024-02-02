#include "cppMain.h"
#include "main.h"

#include "BlinkingLed.h"

// create objects (in RAM data segment, since outside any function)
BlinkingLed led1(LD1_GPIO_Port, LD1_Pin, 4, 50);
BlinkingLed led2(LD2_GPIO_Port, LD2_Pin, 2, 50);
BlinkingLed led3(LD3_GPIO_Port, LD3_Pin, 1, 50);


void cppMain(){

	/*
	// create objects (on stack, since in a function)
	BlinkingLed led1(LD1_GPIO_Port, LD1_Pin, 4, 50);
	BlinkingLed led2(LD2_GPIO_Port, LD2_Pin, 2, 50);
	BlinkingLed led3(LD3_GPIO_Port, LD3_Pin, 1, 50);
	*/

	while(1){
		led1.processBlinking();
		led2.processBlinking();
		led3.processBlinking();
	}
}


