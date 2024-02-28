#include <iostream>

#include "ex6.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

int main() {
	
	try {

		spdlog::set_level(spdlog::level::trace);
		spdlog::trace("program started.");


		int num;
		int den;
		std::cout << "Input the numerator:\n";
		std::cin >> num;
		std::cout << "\nInput the denominator:\n";
		std::cin >> den;

		std::pair <int, std::string> res = GcdAndFraction(num, den);

		std::cout << "The GCD is: " << res.first << "\nThe shorten fraction is: " << res.second << '\n';

		spdlog::trace("program finished.");
	}
	catch (std::logic_error & ex) {
		std::cerr << ex.what();
	}
}