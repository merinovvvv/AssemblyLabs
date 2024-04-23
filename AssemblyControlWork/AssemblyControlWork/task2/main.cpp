
#include <iostream>
#include <vector>


extern "C" void __cdecl CreateVectorB(unsigned int** A, int N, int M, int* B);

int main() {
    std::cout << "Input the number of rows: ";
    int N;
    std::cin >> N;
    std::cout << "Input the number of columns: ";
    int M;
    std::cin >> M;

    std::vector <int> res(N);
    int* B = res.data();

    unsigned int** A = new unsigned int* [N];


    for (size_t i = 0; i < N; ++i) {
        A[i] = new unsigned int[M];
    }

    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            std::cin >> A[i][j];
        }
    }

    CreateVectorB(A, N, M, B);

    std::cout << *B;

    /*__asm {
      push n
      push m

      xor eax, eax
      xor ebx, ebx

      call CreateVectorB


    }*/

    return 0;

}
