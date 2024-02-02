#pragma once //replaces include guards for insuring header file is included only once

// if compiled by cpp compiler, wrap function declaration in 'extern "C" {}'
#ifdef __cplusplus
	extern "C" {
#endif


void cppMain();


#ifdef __cplusplus
	}
#endif
