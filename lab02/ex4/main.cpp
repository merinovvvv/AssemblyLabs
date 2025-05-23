#include <iostream>

#include "ex4.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

int main() {

    try {
        spdlog::set_level(spdlog::level::trace);

        spdlog::trace("program started.");

        uint16_t A1, A2, A3;
        uint16_t B1, B2, B3;

        std::map <std::string, uint16_t> data = readFromFile("data.txt");

        A1 = data["A1"];
        A2 = data["A2"];
        A3 = data["A3"];
        B1 = data["B1"];
        B2 = data["B2"];
        B3 = data["B3"];

        std::vector <uint16_t> result = ex4(A1, A2, A3, B1, B2, B3);

        std::cout << "Output of the number in parts in hex:\n";

        std::cout << "C1: " << std::hex << result[0] << '\n';
        std::cout << "C2: " << std::hex << result[1] << '\n';
        std::cout << "C3: " << std::hex << result[2] << '\n';
        std::cout << "C4: " << std::hex << result[3] << '\n';

        std::cout << "Output of the number in dec:\n";

        uint64_t C = (static_cast<uint64_t>(result[3]) << 48) | (static_cast<uint64_t>(result[2]) << 32) | (static_cast<uint64_t>(result[1]) << 16) | (static_cast<uint64_t>(result[0]));
        std::cout << std::dec << C << '\n';

        spdlog::trace("program finished.");
    }
    catch (std::runtime_error& ex) {
        std::cerr << ex.what();
        exit(0);
    }

    return 0;
}