#include <iostream>  
#include<ctime>  

const int M = 4;
const int N = 3;
extern "C" void CreateVectorB(unsigned int A[][M], int N, int M, int* B);
int main() {
	unsigned int A[N][M];
	srand(time(0));
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			A[i][j] = rand() % 8;
			std::cout << A[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << '\n';
	int* B = new int[N] {-1, -1, -1};
	_asm
	{
		push B
		push M
		push N
		lea eax, A
		push eax
		call CreateVectorB
		pop eax
		pop eax
		pop eax
		pop eax
	}

	if (B[0] != -1)
	{
		for (size_t i = 0; i < N; i++)
		{
			if (B[i] != -1) {
				std::cout << B[i] << " ";
			}
			else {
				break;
			}
		}
		std::cout << "\n";
	}
	else
		std::cout << "There is no equal elements\n";
	return 0;
}
