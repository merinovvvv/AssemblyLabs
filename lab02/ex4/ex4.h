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
        std::cerr << "File open error." << std::endl;
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

    uint16_t C1 = 0, C2 = 0, C3 = 0;
    
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

    std::vector <uint16_t> res = { C1, C2, C3 };

    spdlog::trace("ex4 func. finished.");

    return res;
    
}


#endif //EX4_H