#include <iostream>
#include <vector>
#include <set>

const int N = 3;
const int M = 3;

extern "C" void __cdecl CreateVectorB(unsigned int A[][M], int N, int M, int* B);

int main() {
	unsigned int A[N][M];

	//int* B = new int[N];

	std::vector <int> array(N, -1);
	int* B = array.data();

	std::cout << "Input the elements of matrix :\n";


	for (size_t i = 0; i < N; ++i) {
		for (size_t j = 0; j < M; ++j) {
			std::cin >> A[i][j];
		}
	}

	std::cout << '\n';
	std::cout << "Your matrix looks like:\n";

	for (size_t i = 0; i < N; ++i) {
		for (size_t j = 0; j < M; ++j) {
			std::cout << A[i][j] << " ";
		}
		std::cout << '\n';
	}


	CreateVectorB(A, N, M, B);

	/*__asm {

		push B
		push M
		push N
		lea eax, A
		push eax
		call CreateVectorB
	}*/





	//int index = 0;

	//for (size_t i = 0; i < N; ++i) {
	//	for (size_t j = 0; j < M; ++j) {
	//		for (size_t k = j + 1; k < M; ++k) {
	//			if (A[i][j] == A[i][k]) {
	//				B[index] = i;
	//				index++;
	//				//std::cout << i << j;
	//				break;
	//			}
	//		}
	//	}
	//}
	//

	std::cout << '\n';

	std::set <int> st;



	if (array[0] != -1) {
		for (size_t i = 0; i < array.size(); ++i) {
			if (array[i] != -1) {
				//st.insert(array[i]);
				std::cout << array[i] << ' ';
			}
		}

		/*for (auto it = st.begin(); it != st.end(); ++it) {
			std::cout << *it << " ";
		}*/
	}
	else {
		std::cout << "No elements." << '\n';
	}


	return 0;
}