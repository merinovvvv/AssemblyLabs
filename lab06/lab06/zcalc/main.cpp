#include <iostream>

double z_asm(double x, double y) {
	double result;
	_asm {
		finit
		fld y
		fld x
		fdiv st(1)
		fptan
		fmul x
		fmul x
		fst result
		/*fstp result
		fld x
		fld y
		fmul*/
	}
}

int main() {
	double x = 2;
	double y = 4;
	double res = z_asm(x, y);
	std::cout << res;
}