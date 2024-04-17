#include <iostream>
#include <vector>
#include "ex11.h"


int main()
{
	spdlog::set_level(spdlog::level::trace);
	spdlog::trace("program started.");

	std::vector<int> a = { 4, 7, 2 };
	std::vector<int> b = { 7, 4, 15 };
	std::vector<int> c = { 4, 7, 7 };
	std::cout << arrayIntersection(a, b, c);

	spdlog::trace("program finished.");
}