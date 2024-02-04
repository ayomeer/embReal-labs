#include "cppMain.h"
#include "main.h"
#include <iostream>
// re-imlemented _write() in main.c (!)

extern UART_HandleTypeDef huart3;

void cppMain(){
	std::cout<<"printing incrementing auto variable: \n\r";
	for(auto i=0; i<256; i++){
		std::cout<<"i: " << i << "\n\r"; // works better than 'endl'
		HAL_Delay(50);
	}

	while(1){

	}
}


