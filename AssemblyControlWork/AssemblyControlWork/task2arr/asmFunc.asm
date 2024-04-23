;можно 10 пожалуйста =)
.686
.model flat
public _CreateVectorB

	.data

	index dd ?
	tmp dd ?
	tmpEsi dd ?
	tmpEdi dd ?
	tmpEax dd ?
	
	.code
_CreateVectorB proc

	push ebp
	mov ebp, esp


	mov ebx, dword ptr [ebp + 8] ;A
	mov eax, dword ptr [ebp + 12] ;N
	mov edx, dword ptr [ebp + 16] ;M
	mov ecx, dword ptr [ebp + 20] ;*B

	mov esi, 0 ;i
	mov edi, 0 ;j



	push edi ;j

		mov tmp, eax
		pop eax
		inc eax
		push eax
		mov eax, tmp

	cycle1_:
		cmp esi, eax; while i < N
		je finish_

	cycle2_:
		

		cmp edi, edx ; while j < M
		je addI_

	cycle3_:

		mov tmp, ebx
		pop ebx ;j
		;inc ebx ;k = j + 1


		cmp ebx, edx ; while k < M
		push ebx
		mov ebx, tmp

		;mov eax, tmp
		je addJ_


		;cmp [ebx + (esi * edx * 4) + (edi * 4)], [ebx + (esi * edx * 4) + ([ebp + 8] * 4)]:
		;cmp [ebx + 4 * (edx * esi + edi)], [ebx + 4 * (edx * esi + [ebp + 8])]

		;first

		mov tmp, ebx
		mov tmpEsi, esi
		imul esi, edx ; esi * edx
		add esi, edi ;esi * edx + edi


		;error
		imul esi, 4 ;4 * (esi * edx + edi)

		add ebx, esi ;ebx + 4 * (edx * esi + edi)
		mov tmpEax, eax
		mov eax, [ebx]
		mov ebx, tmp
		mov esi, tmpEsi

		;second


		;error
		mov tmp, ebx
		mov tmpEsi, esi
		imul esi, edx ; esi * edx
		mov tmpEdi, edi
		pop edi
		add esi, edi ;esi * edx + k
		imul esi, 4 ;4 * (esi * edx + k)
		add ebx, esi ; ebx + 4 * (edx * esi + k)
		mov esi, tmpEsi
		push edi
		mov edi, tmpEdi

		cmp eax, dword ptr [ebx]
		mov ebx, tmp
		mov eax, tmpEax
		
		je vecWrite_
		jmp addK_

	addI_:
		inc esi
		mov edi, 0
		mov tmp, eax
		pop eax
		mov eax, edi
		inc eax
		push eax
		mov eax, tmp
		jmp cycle1_


	addJ_:
		inc edi
		mov tmp, eax
		pop eax
		mov eax, edi
		inc eax
		push eax
		mov eax, tmp
		jmp cycle2_

	addK_:
		mov tmp, ebx
		pop ebx
		inc ebx
		push ebx
		mov ebx, tmp
		jmp cycle3_

	vecWrite_:

		mov tmp, ebx
		mov ebx, index
		mov [ecx + ebx * 4], esi
		mov ebx, tmp
		inc index

		inc esi
		mov edi, 0
		mov tmp, eax
		pop eax
		mov eax, 1
		push eax
		mov eax, tmp

		jmp cycle1_


	finish_:
		
		mov esp, ebp
		pop ebp
		ret

_CreateVectorB endp
end