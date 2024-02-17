#include <iostream>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include "ex3.h"

int main() {
	spdlog::set_level(spdlog::level::trace);

	spdlog::trace("program started.");

	int32_t a;
	std::cout << "input the a number: ";
	std::cin >> a;

	int n = ex3(a);

	std::cout << "The max n-value for a^n equals to: " << n << '\n';

	spdlog::trace("program finished.");
	
	return 0;
}