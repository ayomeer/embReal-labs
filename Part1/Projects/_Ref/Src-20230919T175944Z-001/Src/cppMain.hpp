/*
 * EventLoop.hpp
 *
 *  Created on: 28.10.2022
 *      Author: andreas.kuhn
 */

#ifndef SRC_CPPMAIN_HPP_
#define SRC_CPPMAIN_HPP_

void cppMain(); // main event loop function

#ifdef __cplusplus
	extern "C"
	{
		void cppMainC();
	}
#else
	void cppMainC();
#endif

#endif /* SRC_CPPMAIN_HPP_ */
