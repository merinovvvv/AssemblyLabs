#include <iostream>

int main() {
	int M[3][4] = { {100,2,33,4},{5,6,77,8},{900,10,11,120} };
	int n = 3, m = 4, max;
	int resRows;
	int resCols;
	__asm
	{
		mov eax, n
		mul m
		mov ecx, eax //количество элементов массива
		xor esi, esi //индекс
		mov edx, M //максимальный элемент
		mov eax, 0 //индекс максимального элемента
		begin :
		cmp edx, M[esi * 4]
			jnl m_notMax //Jump Not Less
			mov edx, M[esi * 4]
			mov eax, esi
			m_notMax :
		inc esi
			loop begin
			mov max, edx //сохран€ем максимум
			xor edx, edx //вычисл€ем позицию
			div m //в eax Ц номер строки, в edx Ц номер столбца
			mov resRows, eax
			mov resCols, edx

	}
	std::cout << resRows << " " << resCols;
}