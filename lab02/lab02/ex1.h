#pragma once

#ifndef EX1_H
#define EX1_H

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

int ex1 (int a) {
	spdlog::set_level(spdlog::level::trace);
	int res = 0;
	spdlog::debug("__asm started.");
	__asm {
		mov eax, a // 1st degree
		imul eax // 2nd degree
		imul eax, a // 3rd dergee
		imul eax, a // 4th degree
		imul eax, a // 5th degree
		mov ebx, a
		imul ebx, a // 2nd degree
		imul ebx, a //3rd degree
		add eax, a // 5th degree + 1st
		add eax, ebx // (5th degree + 1st) + 3rd
		mov res, eax
	}
	spdlog::debug("__asm finished.");
	spdlog::trace("ex1 func. finished.");
	return res;
}

#endif //EX1_H
