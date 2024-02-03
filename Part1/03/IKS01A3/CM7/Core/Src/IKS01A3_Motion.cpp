/*
 * IKS01A3Motion.cpp
 *
 *  Created on: Oct 9, 2023
 *      Author: ayome
 */

#include "IKS01A3_Motion.h"
#include <algorithm> // std::rotate
#include <numeric>   // std::accumulate
#include <algorithm>

IKS01A3_Motion::IKS01A3_Motion() {}

IKS01A3_Motion::~IKS01A3_Motion() {}


void IKS01A3_Motion::init(uint32_t instance, uint32_t function){
	IKS01A3_MOTION_SENSOR_Init(instance, function); // from BSP API iks01a3_motion_sensors.h
}

void IKS01A3_Motion::enable(uint32_t instance, uint32_t function){
	IKS01A3_MOTION_SENSOR_Enable(instance, function);
}

// sets zero (reference) position by subtracting current position using offsets
void IKS01A3_Motion::setZero(){
	axisOffsets.x=-axisValues.x;
	axisOffsets.y=-axisValues.y;
	axisOffsets.z=-axisValues.z;
}

int32_t i = 0;
int32_t sum = 0;
// update AxisValues struct
void IKS01A3_Motion::updateValues(uint32_t instance, uint32_t function){
	// get sensor values and store in local 'tmpAxisValues'
	IKS01A3_MOTION_SENSOR_Axes_t tmpAxisValues;
	IKS01A3_MOTION_SENSOR_GetAxes(instance, function, &tmpAxisValues);

	// update ring buffer
	#ifdef CUSTOM_RING_ALLOCATOR
	if(ringBufferAxisX.size()>5){ // ringBuffer full (6 elements)
		// remove first (oldest) element from all buffers
		ringBufferAxisX.erase(ringBufferAxisX.begin());
		ringBufferAxisY.erase(ringBufferAxisY.begin());
		ringBufferAxisZ.erase(ringBufferAxisZ.begin());
		// NOTE: erase() reallocates vector elements. Not efficient but w/e
	}
	// append new value at the end of the vectors
	ringBufferAxisX.push_back(tmpAxisValues.x);
	ringBufferAxisY.push_back(tmpAxisValues.y);
	ringBufferAxisZ.push_back(tmpAxisValues.z);

	#else
	// use ring buffers to store last 5 measurements + current one
	ringBufferAxisX[0] = tmpAxisValues.x;
	ringBufferAxisY[0] = tmpAxisValues.y;
	ringBufferAxisZ[0] = tmpAxisValues.z;
	std::rotate(ringBufferAxisX.begin(), ringBufferAxisX.begin()+1, ringBufferAxisX.end());
	std::rotate(ringBufferAxisY.begin(), ringBufferAxisY.begin()+1, ringBufferAxisY.end());
	std::rotate(ringBufferAxisZ.begin(), ringBufferAxisZ.begin()+1, ringBufferAxisZ.end());
	#endif

	// use moving average of ring buffer contents as current value
	axisValues.x = std::accumulate(ringBufferAxisX.begin(), ringBufferAxisX.end(), 0LL) / ringBufferAxisX.size();
	axisValues.y = std::accumulate(ringBufferAxisY.begin(), ringBufferAxisY.end(), 0LL) / ringBufferAxisY.size();
	axisValues.z = std::accumulate(ringBufferAxisZ.begin(), ringBufferAxisZ.end(), 0LL) / ringBufferAxisZ.size();

	// update Ystats
	Ystats["Min"]= *std::min_element(ringBufferAxisY.begin(), ringBufferAxisY.end());
	Ystats["Avg"]= tmpAxisValues.y;
	Ystats["Max"]= *std::max_element(ringBufferAxisY.begin(), ringBufferAxisY.end());
}

void IKS01A3_Motion::getValues(int32_t* XAxis, int32_t* YAxis, int32_t* ZAxis){
	*XAxis = axisValues.x + axisOffsets.x;
	*YAxis = axisValues.y + axisOffsets.y;
	*ZAxis = axisValues.z + axisOffsets.z;
}


