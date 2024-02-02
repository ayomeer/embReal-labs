/*
 * IKS01A3Motion.h
 *
 *  Created on: Oct 9, 2023
 *      Author: ayome
 */

#ifndef IKS01A3MOTION_H_
#define IKS01A3MOTION_H_

#include "iks01a3_motion_sensors.h"
#include <array>
#include <cstdint>

class IKS01A3_Motion {
private:
	IKS01A3_MOTION_SENSOR_Axes_t axisValues={0,0,0};
	IKS01A3_MOTION_SENSOR_Axes_t axisOffsets={0,0,0};

	std::array<int32_t, 6> ringBufferAxisX={0,0,0,0,0,0};
	std::array<int32_t, 6> ringBufferAxisY={0,0,0,0,0,0};
	std::array<int32_t, 6> ringBufferAxisZ={0,0,0,0,0,0};

	void getValue(uint32_t instance, uint32_t function,
				  uint32_t* XAxis, uint32_t* YAxis, uint32_t* ZAxis);

public:
	IKS01A3_Motion();
	virtual ~IKS01A3_Motion();

	void init(uint32_t instance, uint32_t function);
	void enable(uint32_t instance, uint32_t function);
	void setZero();
	void updateValues(uint32_t instance, uint32_t function);
	void getValues(int32_t* XAxis, int32_t* YAxis, int32_t* ZAxis);

};

#endif /* IKS01A3MOTION_H_ */
