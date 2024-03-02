#pragma once

#ifndef EX6_H
#define EX6_H

#include <utility>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"


std::pair <int, std::string> GcdAndFraction(int num, int den) {

	spdlog::trace("GcdAndFraction func. started.");

	int gcd = 0;
	int numerator = 0;
	size_t denominator = 0;

	if (den <= 0) {
		spdlog::error("Exception is thrown (denominator error).");
		throw std::logic_error("The denominator equals to 0 or is a negative number.");
	}


	spdlog::debug("__asm started.");

	_asm
	{
		mov eax, num
		mov ebx, den
	_start :
		cmp eax, 0
		je numIsZero_
		jg beg
		neg eax
		beg :
		cmp eax, ebx
			je prend_ //if equal
			jg gr //if greater
			sub ebx, eax
			jmp beg
			gr :
		sub eax, ebx
			jmp beg
			prend_ :
		mov gcd, eax //result is in both eax and ebx
		cdq
		mov eax, num
		cmp eax, 0
		jg end_
		neg eax
		end_ :
		div gcd
		mov numerator, eax
		mov eax, den
		cdq
		div gcd
		mov denominator, eax
		jmp end__

	numIsZero_ :
		mov numerator, 0
		mov gcd, 0
		mov denominator, 1
	end__:

	}

	spdlog::debug("__asm finished.");

	std::string shFraction = std::to_string(numerator) + "/" + std::to_string(denominator);

	if (num < 0) {
		shFraction = '-' + shFraction;
	}
	std::pair <int, std::string> res (gcd, shFraction);

	spdlog::trace("GcdAndFraction func. finished.");

	return res;

}


#endif //EX6_H