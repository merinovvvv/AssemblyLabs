#include <iostream>

#include "ex8.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

int main() {

	try {
		spdlog::set_level(spdlog::level::trace);
		spdlog::trace("program started.");

		size_t number;

		std::cout << "Input the number:\n";
		std::cin >> number;

		std::pair <int, int> result = degOfTwo(number);

		std::cout << "The number is between the " << result.first << " and " << result.second << " degrees of 2\n";

		spdlog::trace("program finished.");
	}
	catch (std::logic_error& ex) {
		std::cerr << ex.what();
	}
}
