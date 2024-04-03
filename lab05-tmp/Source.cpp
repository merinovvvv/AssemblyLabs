#include <iostream>

extern "C" int __fastcall mul2(int);

int main() {
	std::cout << "multiply by 2 = " << mul2(5) << '\n';
}