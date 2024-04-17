#include <iostream>
#include <utility>
#include <cmath>

extern "C" float __fastcall calculateSqrt(int, float*);

float CalculateSqrt(int n, float* a) {
    float variable = *a;
    __asm {
        finit
        mov esi, dword ptr[a]
        mov ecx, n
        _loop :
        fld dword ptr[esi]
            fld1
            fld1
            fadd

            fdivp st(1), st(0)
            fld dword ptr[variable]

            fld1
            fld1
            fadd
            fld dword ptr[esi]

            fmulp st(1), st(0)
            fdivp st(1), st(0)
            faddp st(1), st(0)
            fstp dword ptr[esi]
            loop _loop
    }
    return *a;
}

int main() {
    /*float a = 4.0;
    int n = 5;
    float result = CalculateSqrt(n, &a);
    std::cout << "Result of function: " << result << ' ' << "Difference: " << std::sqrt(2) - result;*/

    float* a = new float(2.0);
    int n = 5;

    float result;
    __asm {
        mov ecx, n
        mov edx, dword ptr[a]
        call calculateSqrt
        fstp dword ptr[result]
    }
    std::cout << result;
    return 0;
}