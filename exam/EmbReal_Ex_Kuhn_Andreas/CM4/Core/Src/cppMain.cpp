#include "cppMain.h"
#include "main.h" // includes HAL


void cppMain(){
	// New cpp main loop
	while(1){
		while(1){
			HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
			HAL_Delay(500);
			HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
		}
	}
}

