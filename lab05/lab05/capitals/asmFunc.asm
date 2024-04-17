.686

PUBLIC _capitals

.model flat

.code

_capitals proc

	push ebp
	mov ebp, esp

	mov eax, dword ptr [ebp + 8] ;str ptr
	mov ebx, dword ptr [ebp + 12] ;length

	mov esi, 0 ;str index
	mov cl, byte ptr [eax + esi] ;char
	cmp cl, 97
	jl nextCheck_
	cmp cl, 122
	jg nextCheck_
	sub cl, 32
	mov byte ptr[eax + esi], cl ; «аписываем обратно в пам€ть измененное значение cl

	nextCheck_:
		inc esi
		cmp esi, ebx
		je end_
		mov cl, byte ptr [eax + esi] ;char
		cmp cl, 32
		je begin_
		jmp nextCheck_

	begin_:
		inc esi
		cmp esi, ebx
		je end_
		mov cl, byte ptr [eax + esi] ;char
		cmp cl, 97
		jl nextCheck_
		cmp cl, 122
		jg nextCheck_
		sub cl, 32
		mov byte ptr[eax + esi], cl ; «аписываем обратно в пам€ть измененное значение cl
		jmp nextCheck_
	
	end_:
		mov esp, ebp
		pop ebp
		ret

_capitals endp
end