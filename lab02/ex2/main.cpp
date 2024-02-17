#include <iostream>

#include "ex2.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

int main() {

	try {

		spdlog::set_level(spdlog::level::trace);

		spdlog::trace("program started.");

		int a;

		std::cout << "input the a number: ";
		std::cin >> a;


		std::string expr = "(a^5 + 2 * (a^2 - 4) + a) / a^3";
		int result = ex2(a);

		std::cout << "The result of the expression " << expr << " equals to : " << result << '\n';
		spdlog::trace("program finished.");
	}

	catch (std::logic_error& ex) {
		std::cerr << ex.what();
		exit(0);
	}

	return 0;
}

