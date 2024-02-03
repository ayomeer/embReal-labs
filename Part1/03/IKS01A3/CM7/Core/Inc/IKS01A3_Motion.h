/*
 * IKS01A3Motion.h
 *
 *  Created on: Oct 9, 2023
 *      Author: ayome
 */

#ifndef IKS01A3MOTION_H_
#define IKS01A3MOTION_H_

#include "iks01a3_motion_sensors.h"
#include <cstdint>
#include <array>
#include <map>
#include <string>

// custom ring allocator
#define CUSTOM_RING_ALLOCATOR
#include <vector>
#include "util_ring_allocator.h"
#include <numeric>  // std::accumulate

class IKS01A3_Motion {
public:
	IKS01A3_Motion();
	virtual ~IKS01A3_Motion();

	void init(uint32_t instance, uint32_t function);
	void enable(uint32_t instance, uint32_t function);
	void setZero();
	void updateValues(uint32_t instance, uint32_t function);
	void getValues(int32_t* XAxis, int32_t* YAxis, int32_t* ZAxis);
	void getStats(int32_t* Ystats);

	std::map<std::string, int32_t> Ystats = {{"Min",0},{"Avg",0},{"Max",0}};

private:
	IKS01A3_MOTION_SENSOR_Axes_t axisValues={0,0,0};
	IKS01A3_MOTION_SENSOR_Axes_t axisOffsets={0,0,0};



	#ifdef CUSTOM_RING_ALLOCATOR
	// vector<element_type, allocator<element_type, buffer_alignment>>                  v default value, can be omitted
	std::vector<int32_t, util::ring_allocator<int32_t, UINT8_C(16)>> ringBufferAxisX;
	std::vector<int32_t, util::ring_allocator<int32_t, UINT8_C(16)>> ringBufferAxisY;
	std::vector<int32_t, util::ring_allocator<int32_t, UINT8_C(16)>> ringBufferAxisZ;
	// NOTE: #elements doesn't have to be defined, because vector can grow dynamically


	#else
	std::array<int32_t, 6> ringBufferAxisX={0,0,0,0,0,0};
	std::array<int32_t, 6> ringBufferAxisY={0,0,0,0,0,0};
	std::array<int32_t, 6> ringBufferAxisZ={0,0,0,0,0,0};
	#endif

	void getValue(uint32_t instance, uint32_t function,
				  uint32_t* XAxis, uint32_t* YAxis, uint32_t* ZAxis);



};

#endif /* IKS01A3MOTION_H_ */
