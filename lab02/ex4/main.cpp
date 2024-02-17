#include <iostream>

#include "ex4.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

int main() {

    spdlog::set_level(spdlog::level::trace);
    int16_t A1, A2, A3;
    int16_t B1, B2, B3;

    std::map <std::string, int16_t> data = readFromFile("data.txt");

    A1 = data["A1"];
    A2 = data["A2"];
    A3 = data["A3"];
    B1 = data["B1"];
    B2 = data["B2"];
    B3 = data["B3"];

    std::vector <int16_t> result = ex4(A1, A2, A3, B1, B2, B3);

    std::cout << "Output of the number in parts in hex:\n";

    std::cout << "C1: " << std::hex << result[0] << '\n';
    std::cout << "C2: " << std::hex << result[1] << '\n';
    std::cout << "C3: " << std::hex << result[2] << '\n';

    std::cout << "Output of the number in dec:\n";

    int64_t C = ((int64_t)result[2] << 32) | ((int64_t)result[1] << 16) | result[0];
    std::cout << std::dec << C;
}