

#include <iostream>
#include <utility>
#include <cmath>

extern "C" float __fastcall calculateSqrt(int, float*);

float CalculateSqrt(int N, float* A) {
    float variable = *A;
    __asm {
        finit
        mov esi, dword ptr[A]
        mov ecx, N
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
    return *A;
}

int main() {
    float a = 4.0;
    int n = 10;
    float result;
    __asm {
        mov ecx, n
        mov edx, a
        mov ebx, dword ptr[a]
        call calculateSqrt
        mov result, eax
    }
    return 0;
}
