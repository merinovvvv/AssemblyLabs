#pragma once

#ifndef EX10_H
#define EX10_H

#include <vector>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

std::vector <int> vectorMerge (int* _ptr1, int* _ptr2, int _size) {

	spdlog::trace("vectorMerge func. started.");

	int resSize = _size * 2;
	std::vector <int> merged (resSize);
	int* mr = merged.data();

	spdlog::debug("__asm started.");

	int counter = 0;

	__asm {
		mov ecx, counter
		mov edx, dword ptr[mr]//putting the final vec pointer into edx
		mov esi, 0 //i
		mov edi, 0 //j

	begin_:
		cmp esi, _size
		je push3_
		cmp edi, _size
		je push4_
		mov ebx, dword ptr [_ptr1] //putting the 1st vec pointer to ebx in order to recieve the value
		mov eax, dword ptr[ebx + esi * 4]
		mov ebx, dword ptr[_ptr2] //putting the 2nd vec pointer to ebx in order to recieve the value
		cmp eax, dword ptr[ebx + edi * 4]
		jnle push2_

	push1_://push 1st vec's value to final vec
		mov ebx, dword ptr [_ptr1] //putting the 1st vec pointer to ebx in order to recieve the value
		mov eax, dword ptr[ebx + esi * 4]
		mov dword ptr[edx + ecx * 4], eax
		inc esi //i++
		inc ecx //counter++
		jmp begin_

	push2_://push 2nd vec's value to final vec
		mov ebx, dword ptr[_ptr2] //putting the 2nd vec pointer to ebx in order to recieve the value
		mov eax, dword ptr [ebx + edi * 4]
		mov dword ptr[edx + ecx * 4], eax
		inc edi //j++
		inc ecx //counter++
		jmp begin_

	push3_: //vec1 is finished, push vec2 values
		cmp ecx, resSize //if counter == resSize (if it is the end of the final vec)
		je end_
		mov ebx, dword ptr [_ptr2] //putting the 2nd vec pointer to ebx in order to recieve the value
		mov eax, dword ptr[ebx + edi * 4]
		mov dword ptr[edx + ecx * 4], eax
		inc edi
		inc ecx
		jmp push3_

	push4_://vec2 is finished, push vec1 values
		cmp ecx, resSize
		je end_
		mov ebx, dword ptr[_ptr1] //putting the 1st vec pointer to ebx in order to recieve the value
		mov eax, dword ptr[ebx + esi * 4]
		mov dword ptr[edx + ecx * 4], eax
		inc esi
		inc ecx
		jmp push3_

	end_:
}

	spdlog::debug("__asm finished.");

	spdlog::trace("vectorMerge func. finished.");

	return merged;

}

#endif //EX10_H