#include "cppMain.h"
#include "main.h"

#include <iostream>
#include <cstdint>   // _t datatypes
#include <stdlib.h>  // rand
#include <algorithm> // sort

using namespace std;

// template function prototype
template <typename T>
T avgFunction(T* arr, uint32_t arrSize);


void cppMain(){

	int16_t arr[6] = {6,5,4,3,2,1};
	uint32_t arrSize = sizeof(arr)/sizeof(int16_t);
	int16_t average = 0;

	// show array on console
	cout << flush; // flush out endl's that might be stuck in there
	cout << "array contents: " << "\n\r";

	for(uint32_t i=0; i<arrSize; i++){
		cout << "idx: " << i << ", int: " << arr[i] <<"\n\r";
	}
	cout << "\n\r" << flush;

	// take average using template function
	average = avgFunction(arr, arrSize); // arr itself is pointer to first element
	// show average result on console
	cout << "computed average: " << average << "\n\r" << flush;

	// sort last three elements of the array
	// sort [first, last) <-- not including last -> last=arr[arrSize]+1
	std::sort(&arr[3], &arr[arrSize]+1); // no return needed
	// NOTE: &arr[arrSize]+1 --> pointer arithmetic takes care of 16bit memory addresses

	cout << "array with last 3 elements sorted: " << "\n\r";
	for(uint32_t i=0; i<arrSize; i++){
		cout << "idx: " << i << ", int: " << arr[i] <<"\n\r";
	}
	cout << "\n\r" << flush;

	while(1){

	}
}

// template function implementation
template <typename T>
T avgFunction(T* arr, uint32_t arrSize){
	double avg = 0;
	for(uint32_t i=0; i<arrSize; i++){
		avg += (double)arr[i];
	}
	avg /= (double)arrSize;
	return (T)avg;
}


