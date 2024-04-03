#include <iostream>
#include <vector>

#include "ex10.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"


int main() {

	spdlog::set_level(spdlog::level::trace);
	spdlog::trace("program started.");

	int size;
	std::cout << "Input the size of the sorted arrays:\n";
	std::cin >> size;
	std::vector <int> vec1;
	std::vector <int> vec2;
	int tmp;
	spdlog::debug("input started.");
	for (size_t i = 0; i < size; ++i) {
		std::cout << "Input the element of the vec1:\n";
		std::cin >> tmp;
		vec1.push_back(tmp);
	}

	for (size_t i = 0; i < size; ++i) {
		std::cout << "Input the element of the vec2:\n";
		std::cin >> tmp;
		vec2.push_back(tmp);
	}

	spdlog::debug("input finished.");

	int* ptr1 = vec1.data();
	int* ptr2 = vec2.data();

	std::vector <int> merge = vectorMerge(ptr1, ptr2, size);

	std::cout << "Merged vector looks like:\n";

	for (size_t i = 0; i < merge.size(); ++i) {
		std::cout << merge[i] << ' ';
	}

	std::cout << '\n';

	spdlog::trace("program finished.");

}