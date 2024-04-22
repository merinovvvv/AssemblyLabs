.686

public _CreateVectorB

.model flat

.data
	columnValue dd ?
	counter dd ?
	tmp dd ?
	tmp2 dd ?
	four dd 4
	index dd ?
	var dd ? ;variable for eax


.code

_CreateVectorB proc

	push ebp
	mov esp, ebp

	lea esi, [ebp + 8] ;*A
	mov edi, [ebp + 20] ; *B

	;2 регистра поход по A
	;1 регистра проход по B
	;2 регистра на хранение массивов

	mov eax, 0 ;i
	mov ebx, 0 ;j
	mov ecx, [ebp + 16] ;m
	mov index, 0

	begin_:
		mov counter, 1
		mov edx, 0

		cmp eax, [ebp + 12] ;ebp + 12 = n
		je finish_
	columnsCheck_:
		cmp ebx, ecx ;сравниваем j и кол-во столбцов
		jg addI_
		mov edx, ebx
		add edx, counter
		cmp edx, ecx ;сравниваем j+1 и кол-во столбцов
		jg addJ_


		mov tmp, edx
		mul ecx ;i * m
		mul four ;i * m * 4
		mov var, eax
		mov edx, tmp
		

		mov tmp2, ecx
		mov ecx, dword ptr[esi + var + ebx * 4]
		cmp ecx, dword ptr[esi + var + edx * 4]
		xor edx, edx
		mov ecx, tmp2
		je vecWrite_
		inc counter
		jmp columnsCheck_
	addJ_:
		inc ebx
		jmp columnsCheck_
	addI_:
		inc eax
		mov ebx, 0
		jmp begin_

	vecWrite_:

		mov tmp, ebx ; для временного хранения eax
		mov ebx, index
		
		;mov tmp2, edx
		;mov edx, [edi]     ; загружаем указатель на массив указателей (int*)

		mov dword ptr [edx + ebx * 4], eax
		inc index
		mov ebx, tmp
		mov edx, tmp2
		jmp addI_

	finish_:

		mov esp, ebp
		pop ebp
		ret
    
    
_CreateVectorB ENDP

END