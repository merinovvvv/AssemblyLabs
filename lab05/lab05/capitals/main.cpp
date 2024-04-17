#include <iostream>
#include <string>

extern "C" void __cdecl capitals(char*, int);

int main() {

	std::string str;
	std::cout << "Input your string: ";
	std::getline(std::cin, str);

	int length = str.size();
	char* stringPointer = &str[0];
	capitals(stringPointer, length);

	std::cout << "The string now looks like: " << str;

}