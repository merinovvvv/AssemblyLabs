#include <iostream>
#include <string>

extern "C" char* __stdcall DelSymbol(char*, int, char);

int main() {

		std::cout << "Enter string:\n";
		char st[40];
		std::cin >> st;
		std::cout << "Enter a symbol: ";
		char sym;
		std::cin >> sym;
		std::cout << DelSymbol(st, std::strlen(st), sym);
}

