#pragma once
#ifndef EX11_H
#define EX11_H

#include <vector>
#include <algorithm>
#include "spdlog/spdlog.h"

bool arrayIntersection(std::vector<int>& a, std::vector<int>& b, std::vector<int>& c)
{
	spdlog::trace("arrayIntersection func. started.");

	int* ptrA = a.data();
	int* ptrB = b.data();
	int aSize = a.size();
	int bSize = b.size();

	int* res = new int[std::min(aSize, bSize)];
	int leng;

	spdlog::debug("__asm started.");
	__asm {
		xor edx, edx
		xor ebx, ebx
		mov esi, 0
		mov edi, dword ptr[res]
		firstLoop_:
		cmp edx, aSize
			jge end_
			xor ebx, ebx
			secondLoop_ :
		cmp ebx, bSize
			jge firstLoopCont_
			mov eax, dword ptr[ptrA]
			mov ecx, dword ptr[eax + edx * 4]
			mov eax, dword ptr[ptrB]
			cmp ecx, dword ptr[eax + ebx * 4]
			je pushElem_
			inc ebx
			jmp secondLoop_

			pushElem_ :
		mov dword ptr[edi + esi * 4], ecx
			inc esi
			inc ebx
			jmp firstLoopCont_
			firstLoopCont_ :
		inc edx
			jmp firstLoop_
			end_ :
		mov leng, esi
	}
	spdlog::debug("__asm finished.");

	if (leng != c.size()) {
		spdlog::trace("arrayIntersection func. finished.");
		return 0;
	}
	for (size_t i = 0; i < leng; ++i) {
		if (res[i] != c[i]) {
			spdlog::trace("arrayIntersection func. finished.");
			return 0;
		}
	}
	spdlog::trace("arrayIntersection func. finished.");
	return 1;
}

#endif // EX11_H