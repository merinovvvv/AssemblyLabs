#pragma once

#ifndef EX4_H
#define EX4_H

#include <vector>
#include <cstdint>
#include <map>
#include <fstream>
#include <sstream>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

std::map <std::string, uint16_t> readFromFile (const std::string& filePath){
    std::ifstream fin(filePath, std::ios::in);
    std::map <std::string, uint16_t> res;

    if (!fin.is_open()) {
        spdlog::error("Exception is thown (file open error).");
        throw std::runtime_error("File open error.");
        return res;
    }

    std::string str;
    while (std::getline(fin, str)) {
        if (str == ".data") {
            continue;
        }
        std::istringstream iss(str);
        std::string key, skip;
        uint16_t value;
        iss >> key >> skip >> value;

        res[key] = value;

    }
    return res;
}

std::vector <uint16_t> ex4(uint16_t A1, uint16_t A2, uint16_t A3, uint16_t B1, uint16_t B2, uint16_t B3) {
    spdlog::trace("ex4 func. started.");
    spdlog::debug("__asm started.");

    uint16_t C1 = 0, C2 = 0, C3 = 0, C4 = 0;
    
    __asm {
        
        xor cx, cx

        mov ax, A1
        add ax, B1
        mov C1, ax

        mov bx, A2
        adc bx, B2
        mov C2, bx

        mov dx, A3
        adc dx, B3
        mov C3, dx

        adc cx, 0
        mov C4, cx
    }
    spdlog::debug("__asm finished.");

    std::vector <uint16_t> res = { C1, C2, C3, C4 };

    spdlog::trace("ex4 func. finished.");

    return res;
    
}


#endif //EX4_H