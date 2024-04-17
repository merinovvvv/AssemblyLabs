#include <iostream>
#include <string>

extern "C" int __stdcall maxNum(char*, int);

int main() {

	std::string str;
	std::cout << "Input your string: ";
	std::getline(std::cin, str);

	int length = str.size();
	char* stringPointer = &str[0];
	int result = maxNum(stringPointer, length);

	std::cout << "The max numbers in a row result is: " << result;



}