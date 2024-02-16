#include <iostream>

#include "ex1.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

int main() {
	spdlog::set_level(spdlog::level::trace);

	std::string expr = "a^5 + a^3 + a";

	int a;

	std::cout << "input the a number: ";
	std::cin >> a;

	int result = ex1(a);

	std::cout << "The result of the expression " << expr << " equals to : " << result << '\n';
}