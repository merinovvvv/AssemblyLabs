#pragma once

#ifndef EX9_H
#define EX9_H

#include <vector>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

void vectorRebuild(int* _ptr) {

	spdlog::trace("vectorRebuild func. started.");


	int i = 0;

	spdlog::debug("__asm started.");

	__asm { 
		mov esi, 1 //i
		mov edx, dword ptr[_ptr]//putting vec ptr into edx
	firstLoopBegin_ :
		cmp esi, dword ptr[edx] // compare i and value of pointer(length)
		jl secondLoop_
		jmp end__
	secondLoop_ :
		mov edi, dword ptr[edx] // j = length	
	secondLoopBegin_ :
			cmp edi, esi
			jg continueSecondLoop_
			inc esi
			jmp firstLoopBegin_
	continueSecondLoop_ :
			mov ebx, dword ptr[edx + esi * 4] //ebx = length + i
			mov eax, dword ptr[edx + edi * 4]
			cmp ebx, eax //if (length + i) == (length + j)
			je thirdLoop_ //HERE IS AN ERROR!!!
			dec edi
			jmp secondLoopBegin_
	
	thirdLoop_ :

			mov ecx, dword ptr [edx] //ecx = length
			sub ecx, edi //(length - j) - the way to go
			//add ecx, 1
			mov i, esi //mov esi to i in order not to loose the i value
			mov esi, edi //esi in now k

	thirdLoopBegin_:

			//mov eax, dword ptr [edx + esi * 4] //putting the length + k value to eax
			mov ebx, dword ptr [edx + esi * 4 + 4] //putting the length + k + 1 value to ebx
			mov dword ptr[edx + esi * 4], ebx //length + k = length + k + 1
			inc esi
			loop thirdLoopBegin_

			dec dword ptr [edx]

			mov esi, i

			jmp continueSecondLoop_
	end__ :
	}

	spdlog::debug("__asm finished.");

	spdlog::trace("vectorRebuild func. finished.");

}

#endif //EX9_H