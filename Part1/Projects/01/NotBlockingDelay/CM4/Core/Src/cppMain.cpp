#include "cppMain.h"
#include "main.h"


// From Drivers > *hal.c: 	   HAL_Delay()
// From Drivers > *hal_gpio.c: HAL_GPIO_TogglePin()

// From Blinky.ioc > System Core > GPIO we can see the BSP config:
//	The green LED pin is #defined as 'LD1' --> LD1_Port, LD1_Pin
//  => goes into main.h AFTER pin context(core) is assigned in Blinky.ioc

bool NonBlocking_Delay(uint32_t Delay);

void cppMain(){
	// New cpp main loop
	while(1){
		// Toggle green LED
		if (NonBlocking_Delay(500)){
			HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
		}
		// Toggle red LED (blocking)
		HAL_Delay(500);
		HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
	}
}

// New Non-blocking Delay function
bool NonBlocking_Delay(uint32_t Delay){
	static bool flag_init = true;
	static uint32_t wait;
	static uint32_t tickstart;

	if (flag_init == true){
		flag_init = false;

		wait = Delay;
		tickstart = HAL_GetTick();
	}


	// Delay logic
	if ((HAL_GetTick() - tickstart) < wait) // not enough time passed
	{
		return false;
	}
	else{ // waited for given amount of time --> re-initialize on next entry
		flag_init = true;
		return true;
	}
}
