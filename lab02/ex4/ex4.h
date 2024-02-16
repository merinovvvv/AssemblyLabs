#pragma once

#ifndef EX4_H
#define EX4_H

#include <vector>
#include <cstdint>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

std::vector <int16_t> ex4(int16_t A1, int16_t A2, int16_t A3, int16_t B1, int16_t B2, int16_t B3) {
    spdlog::trace("ex4 func. started.");
    spdlog::debug("__asm started.");

    int16_t C1 = 0, C2 = 0, C3 = 0;
    
    __asm {
        mov ax, A1
        add ax, B1
        mov C1, ax

        mov ax, A2
        adc ax, B2
        mov C2, ax

        mov ax, A3
        adc ax, B3
        mov C3, ax
    }
    spdlog::debug("__asm finished.");

    std::vector <int16_t> res = { C1, C2, C3 };

    spdlog::trace("ex4 func. finished.");

    return res;
    
}


#endif //EX4_H