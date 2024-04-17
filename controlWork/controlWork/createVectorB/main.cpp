//#include <stdio.h>
//#include <stdbool.h>
//
//#define N 3 // Пример размера массива
//#define M 4 // Пример размера массива
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
//                    break; // Найдено совпадение, переходим к следующей строке
//                }
//            }
//            if (hasDuplicates) {
//                // Сброс флага для следующей итерации
//                hasDuplicates = false;
//                break;
//            }
//        }
//    }
//
//    if (bIndex == 0) { // Вектор B пуст, совпадений не найдено
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
//    int B[N] = { 0 }; // Вектор B должен вмещать номера всех строк
//
//    // Вызов функции CreateVectorB из ассемблерной вставки
//    __asm {
//        push N        // Последний аргумент
//        push M        // Третий аргумент
//        lea eax, B    // Второй аргумент, адрес вектора B
//        push eax
//        lea eax, matrix // Первый аргумент, адрес первого элемента массива matrix
//        push eax
//        call CreateVectorB
//        add esp, 16   // Очистка стека (4 аргумента * 4 байта каждый)
//    }
//
//    // После вызова функции вектор B будет содержать искомые номера строк
//    return 0;
//}
