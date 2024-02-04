#include "cppMain.h"
#include "main.h"
#include <iostream> // cout
// re-imlemented _write() in main.c (!)

void cppMain(){
	std::cout<<"printing incrementing auto variable: \n\r";
	for(auto i=0; i<256; i++){
		std::cout<<"i: " << i << "\n\r";
		HAL_Delay(50);
	}

	while(1){

	}
}


