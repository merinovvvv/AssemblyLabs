#include <iostream>

#include "ex7.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

int main() {

	spdlog::set_level(spdlog::level::trace);
	spdlog::trace("program started.");

	size_t deg;
	int num;
	std::cout << "Input the number:\n";
	std::cin >> num;
	std::cout << "Input the deg:\n";
	std::cin >> deg;

	int res = NumInDeg(num, deg);

	std::cout << "The result equals to: " << res << '\n';

	spdlog::trace("program finished.");
}