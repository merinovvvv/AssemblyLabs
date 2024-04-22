#include <iostream>
#include <utility>
#include <cmath>

extern "C" float __fastcall calculateSqrt(int, float*);

float CalculateSqrt(int n, float* a) {
    float variable = *a;
    __asm {
        finit  // ������������� ������������
        mov esi, dword ptr[a]  // �������� ������ ������� � ������� esi
        mov ecx, n  // �������� ���������� �������� � ������� ecx
        _loop :
            fld dword ptr[esi]  // �������� �������� �� ������ � ���� FPU
            fld1 //�������� 1
            fld1 //�������� 1
            fadd  // �������� ���� ������� �������� � ����� FPU

            fdivp st(1), st(0)  // ������� ���� ������� �������� � ����� FPU
            fld dword ptr[variable]  // �������� ���������� variable � ���� FPU

            fld1
            fld1
            fadd
            fld dword ptr[esi]

            fmulp st(1), st(0)  // ��������� ���� ������� �������� � ����� FPU
            fdivp st(1), st(0)
            faddp st(1), st(0)
            fstp dword ptr[esi]  // ���������� �������� �������� ����� FPU � ������
            loop _loop  // ���������� ����� ecx ���
    }
    return *a;
}

int main() {
    float* a = new float(4.0);
    int n = 5;

    //float result;
    //__asm {
    //    mov ecx, n  // �������� ���������� �������� � ������� ecx
    //    mov edx, dword ptr[a]  // �������� ������ ����� a � ������� edx
    //    call calculateSqrt  // ����� ������� calculateSqrt
    //    fstp dword ptr[result]
    //}

    float result = calculateSqrt(n, a);
    std::cout << result;
    return 0;
}
