#pragma once

#ifndef EX8_H
#define EX8_H


#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

std::pair <int, int> degOfTwo(size_t number) {
	spdlog::trace("degOfTwo func. started.");

	if (number == 0) {
		spdlog::error("Exception is thrown (Number is 0).");
		throw std::logic_error("Number is 0.");
	}

	spdlog::debug("__asm started.");

	int lower_exponent = 0;
	int upper_exponent = 0;
	
	__asm {
		xor eax, eax
		mov ebx, number
		bsr ecx, ebx
		mov upper_exponent, ecx
	}


	lower_exponent = upper_exponent;

	upper_exponent += 1;

	std::pair <int, int> result(lower_exponent, upper_exponent);

	spdlog::debug("__asm finished.");

	spdlog::trace("degOfTwo func. finished.");

	return result;
}


#endif //EX8_H