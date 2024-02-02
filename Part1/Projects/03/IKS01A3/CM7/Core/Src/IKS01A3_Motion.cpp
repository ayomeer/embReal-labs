/*
 * IKS01A3Motion.cpp
 *
 *  Created on: Oct 9, 2023
 *      Author: ayome
 */

#include "IKS01A3_Motion.h"
#include <algorithm> // std::rotate
#include <numeric>   // std::accumulate

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

// update AxisValues struct
void IKS01A3_Motion::updateValues(uint32_t instance, uint32_t function){
	IKS01A3_MOTION_SENSOR_Axes_t tmpAxisValues;
	IKS01A3_MOTION_SENSOR_GetAxes(instance, function, &tmpAxisValues);

	// use ring buffers to store last 5 measurements + current one
	ringBufferAxisX[0] = tmpAxisValues.x;
	ringBufferAxisY[0] = tmpAxisValues.y;
	ringBufferAxisZ[0] = tmpAxisValues.z;
	std::rotate(ringBufferAxisX.begin(), ringBufferAxisX.begin()+1, ringBufferAxisX.end());
	std::rotate(ringBufferAxisY.begin(), ringBufferAxisY.begin()+1, ringBufferAxisY.end());
	std::rotate(ringBufferAxisZ.begin(), ringBufferAxisZ.begin()+1, ringBufferAxisZ.end());

	// use moving average of ring buffer contents as current value
	axisValues.x = std::accumulate(ringBufferAxisX.begin(), ringBufferAxisX.end(), 0LL) / ringBufferAxisX.size();
	axisValues.y = std::accumulate(ringBufferAxisY.begin(), ringBufferAxisY.end(), 0LL) / ringBufferAxisY.size();
	axisValues.z = std::accumulate(ringBufferAxisZ.begin(), ringBufferAxisZ.end(), 0LL) / ringBufferAxisZ.size();
}

void IKS01A3_Motion::getValues(int32_t* XAxis, int32_t* YAxis, int32_t* ZAxis){
	*XAxis = axisValues.x + axisOffsets.x;
	*YAxis = axisValues.y + axisOffsets.y;
	*ZAxis = axisValues.z + axisOffsets.z;
}
