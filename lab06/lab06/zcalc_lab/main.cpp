#include <iostream>
#include <string>

extern "C" double __cdecl zCalc(double x, double y);

int main() {
    double x;
    std::cout << "Enter x: ";
    std::cin >> x;
    double y;
    std::cout << "Enter y: ";
    std::cin >> y;

    double expected_result = 16 * std::tan(2) + 4 * 1/ std::tan(2);

    std::cout << "The expected result is: " << expected_result << '\n';

    double result = zCalc(x, y);

    std::cout << "The real result is : " << result;

    return 0;
}
