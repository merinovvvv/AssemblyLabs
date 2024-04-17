//#include <stdio.h>
//#include <stdbool.h>
//
//#define N 3 // ������ ������� �������
//#define M 4 // ������ ������� �������
//
//void CreateVectorB(unsigned int A[][M], int N, int M, int* B) {
//    int bIndex = 0;
//    bool hasDuplicates = false;
//
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < M - 1; ++j) {
//            for (int k = j + 1; k < M; ++k) {
//                if (A[i][j] == A[i][k]) {
//                    B[bIndex++] = i;
//                    hasDuplicates = true;
//                    break; // ������� ����������, ��������� � ��������� ������
//                }
//            }
//            if (hasDuplicates) {
//                // ����� ����� ��� ��������� ��������
//                hasDuplicates = false;
//                break;
//            }
//        }
//    }
//
//    if (bIndex == 0) { // ������ B ����, ���������� �� �������
//        printf("No rows with duplicate elements found.n");
//    }
//    else {
//        printf("Rows with duplicate elements: ");
//        for (int i = 0; i < bIndex; ++i) {
//            printf("%d ", B[i]);
//        }
//        printf("n");
//    }
//}
//
//int main() {
//    unsigned int matrix[N][M] = {
//        {1, 2, 3, 4},
//        {5, 5, 6, 7},
//        {8, 9, 10, 10}
//    };
//    int B[N] = { 0 }; // ������ B ������ ������� ������ ���� �����
//
//    // ����� ������� CreateVectorB �� ������������ �������
//    __asm {
//        push N        // ��������� ��������
//        push M        // ������ ��������
//        lea eax, B    // ������ ��������, ����� ������� B
//        push eax
//        lea eax, matrix // ������ ��������, ����� ������� �������� ������� matrix
//        push eax
//        call CreateVectorB
//        add esp, 16   // ������� ����� (4 ��������� * 4 ����� ������)
//    }
//
//    // ����� ������ ������� ������ B ����� ��������� ������� ������ �����
//    return 0;
//}
