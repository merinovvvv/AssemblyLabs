#pragma once

#ifndef EX5_H
#define EX5_H

#include <utility>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

std::pair <int, int> countAmountOfZeroAndEven(int num) {

	spdlog::trace("countAmountOfZeroAndEven func. started.");

	uint8_t zeroAmount = 0; // cl
	uint8_t evenAmount = 0; // ch

	spdlog::debug("__asm started.");

	_asm {
		xor ch, ch
		xor cl, cl
		mov ebx, 10
		mov eax, num
		cmp eax, 0
		je zeroEq
		jl _abs
		jmp _loop
	_abs:
		neg eax
	_loop:
		cmp eax, 0
		jz finish
		cdq
		idiv ebx
		test edx, 1 //0b00000001
		jnz _loop //ignoring odd number
		inc ch
		cmp edx, 0 //if digit is 0
		jnz _loop
		inc cl
		jmp _loop
	finish:
		mov evenAmount, ch
		mov zeroAmount, cl
	jmp end_
	zeroEq :
		mov evenAmount, 1
		mov zeroAmount, 1
	end_:

	}

	spdlog::debug("__asm finished.");

	std::pair <int, int> result(zeroAmount, evenAmount);

	spdlog::trace("countAmountOfZeroAndEven func. finished.");
	return result;
}



#endif //EX5_H