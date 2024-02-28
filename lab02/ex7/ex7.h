#pragma once

#ifndef EX7_H
#define EX7_H


#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

int NumInDeg(int num, size_t deg) {
	spdlog::trace("NumInDeg func. started.");

	spdlog::debug("__asm started.");

	int res = 0;
	int degree = deg - 1;

	__asm {
		cmp deg, 0
		je zero_
		mov eax, num
		mov ecx, degree
		cmp degree, 0
		jcxz Exit
	CYCL:
		imul eax, num
		loop CYCL
	Exit:
		mov res, eax
		jmp end_

	zero_:
		mov res, 1

	end_: 

	}

	spdlog::debug("__asm finished.");

	spdlog::trace("NumInDeg func. finished.");

	return res;
}


#endif //EX7_H