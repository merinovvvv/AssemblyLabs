#include <iostream>

#include "ex5.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

int main() {

	spdlog::set_level(spdlog::level::trace);

	spdlog::trace("program started.");

	int num;
	std::cout << "Input the number: ";
	std::cin >> num;
	std::pair <int, int> res = countAmountOfZeroAndEven(num);

	std::cout << "Number of 0: " << res.first << "\nNumber of even: " << res.second << '\n';

	spdlog::trace("program finished.");
}