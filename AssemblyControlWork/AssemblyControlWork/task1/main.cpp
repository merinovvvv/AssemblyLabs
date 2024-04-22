#include <iostream>
#include <utility>
#include <cmath>

extern "C" float __fastcall calculateSqrt(int, float*);

    int main() {
        std::cout << "Input value of number a = ";
        float a;
        std::cin >> a;
        std::cout << "Input number of iterations n = ";
        int n;
        std::cin >> n;

        //float result = CalculateSqrt(n, &a);

        float* aPtr = &a;
        float result;
        __asm {
            mov ecx, n
            mov edx, dword ptr[aPtr]
            call calculateSqrt
            fstp dword ptr[result]
        }

        std::cout << "Result of function: " << result << ' ' << "Difference: " << std::sqrt(a) - result;

}