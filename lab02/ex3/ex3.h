#pragma once

#ifndef EX3_H
#define EX3_H

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

int ex3(int32_t a) {
	spdlog::trace("ex3 func. started.");
	int n = 0;
	spdlog::debug("__asm started.");

	__asm {
		mov ebx, a
        mov eax, 1
        xor ecx, ecx //counter
        loop_start:
        inc ecx //counter++
        imul eax, ebx // Multiply result by 'a'
        jo loop_exit // If overflow, jump to exit loop
        cmp ecx, 31 // Check if counter is 31 (max 32-bit integer)
        je loop_exit // If counter is 31, jump to exit loop
        jmp loop_start // Continue loop
    loop_exit:
        dec ecx // counter-- to get the correct value
        mov n, ecx
	}
    spdlog::debug("__asm finished.");
    spdlog::trace("ex3 func. finished.");

    return n;
}

#endif //EX3_H
