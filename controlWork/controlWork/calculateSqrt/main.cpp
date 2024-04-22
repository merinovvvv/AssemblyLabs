#include <iostream>
#include <utility>
#include <cmath>

extern "C" float __fastcall calculateSqrt(int, float*);

float CalculateSqrt(int n, float* a) {
    float variable = *a;
    __asm {
        finit  // Инициализация сопроцессора
        mov esi, dword ptr[a]  // Загрузка адреса массива в регистр esi
        mov ecx, n  // Загрузка количества итераций в регистр ecx
        _loop :
            fld dword ptr[esi]  // Загрузка значения из памяти в стек FPU
            fld1 //загрузка 1
            fld1 //загрузка 1
            fadd  // Сложение двух верхних значений в стеке FPU

            fdivp st(1), st(0)  // Деление двух верхних значений в стеке FPU
            fld dword ptr[variable]  // Загрузка переменной variable в стек FPU

            fld1
            fld1
            fadd
            fld dword ptr[esi]

            fmulp st(1), st(0)  // Умножение двух верхних значений в стеке FPU
            fdivp st(1), st(0)
            faddp st(1), st(0)
            fstp dword ptr[esi]  // Сохранение верхнего значения стека FPU в память
            loop _loop  // Повторение цикла ecx раз
    }
    return *a;
}

int main() {
    float* a = new float(4.0);
    int n = 5;

    //float result;
    //__asm {
    //    mov ecx, n  // Загрузка количества итераций в регистр ecx
    //    mov edx, dword ptr[a]  // Загрузка адреса числа a в регистр edx
    //    call calculateSqrt  // Вызов функции calculateSqrt
    //    fstp dword ptr[result]
    //}

    float result = calculateSqrt(n, a);
    std::cout << result;
    return 0;
}
