#include "cppMain.h"
#include "main.h"


// From Drivers > *hal.c: 	   HAL_Delay()
// From Drivers > *hal_gpio.c: HAL_GPIO_TogglePin()

// From Blinky.ioc > System Core > GPIO we can see the BSP config:
//	The green LED pin is #defined as 'LD1' --> LD1_Port, LD1_Pin
//  => goes into main.h AFTER pin context(core) is assigned in Blinky.ioc

void cppMain(){
	// New cpp main loop
	while(1){
		HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
		HAL_Delay(500);
		HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
	}
}
