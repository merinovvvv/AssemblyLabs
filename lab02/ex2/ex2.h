#pragma once

#ifndef EX2_H
#define EX2_H

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"


int ex2(int a) {

	if (a == 0) {
		spdlog::error("Exception is thrown (division by zero).");
		throw std::logic_error("division by zero.");
	}

	spdlog::trace("ex2 func. started.");
	int res = 0;
	spdlog::debug("__asm started.");
	__asm {
		mov eax, a
		imul eax, a //2nd degree
		imul eax, a //3rd degree
		imul eax, a //4th degree
		imul eax, a //5th degree
		mov ebx, a
		imul ebx, a //2nd degree
		sub ebx, 4 //a^2 - 4
		imul ebx, 2 //2 * (a^2 – 4)
		add eax, ebx // a^5 + 2 * (a^2 – 4)
		add eax, a // a^5 + 2 * (a^2 – 4) + a
		mov ecx, a
		imul ecx, a
		imul ecx, a
		xor edx, edx
		cmp ecx, 0 // Check if a^3 is zero
		je divideByZeroError // Jump if divisor is zero
		cdq //why
		idiv ecx // (a ^ 5 + 2 * (a ^ 2 – 4) + a) / a ^ 3
		mov res, eax
		jmp finish
	divideByZeroError : 
		mov res, -1
	finish :
	}
	spdlog::debug("__asm finished.");
	spdlog::trace("ex2 func. finished.");
	return res;
}

#endif //EX2_H