.686

PUBLIC _maxNum@8

.model flat

.code

 _maxNum@8 proc

	push ebp
	mov ebp, esp

	mov eax, dword ptr [ebp + 12] ; length
	mov ebx, dword ptr [ebp + 8] ; str pointer
	mov esi, 0 ; str index
	mov edi, 0 ; current sequence length
	mov edx, 0 ; max sequence length

	begin_:
		
		cmp esi, eax
		je end_

		mov cl, byte ptr [ebx + esi] ;char

		cmp cl, '0'
		jl notADigit_

		cmp cl, '9'
		jg notADigit_


		inc edi

		cmp edi, edx          ; Сравниваем текущую длину последовательности с максимальной
		jg changeMax_
		jmp nextChar_

	changeMax_:
		mov edx, edi

	nextChar_:
	
		inc esi
		jmp begin_

		

	notADigit_:
		mov edi, 0            ; Сбрасываем текущую длину последовательности
		jmp nextChar_

	end_:
		mov esp, ebp
		pop ebp
		mov eax, edx

	ret 8

_maxNum@8 endp
end

	

	