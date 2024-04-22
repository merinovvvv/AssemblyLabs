.686
.model flat
public _CreateVectorB

	.data
	count dd 0
	inner_counter dd 0
	N dd 0
	M dd 0
	cur dd 0
	.code
_CreateVectorB proc


	mov eax, [esp + 8]
	mov N, eax
	mov eax, [esp + 12]
	mov M, eax
	mov ebx, [esp + 4] 
	mov esi, [esp + 16]
	xor edx, edx
	xor ecx, ecx
	xor edi, edi


cycle :
	mov eax, 0
	mov inner_counter, eax
	mov edi, ecx
	imul edi, M
	imul edi, edi, 4; first elem index
	mov eax, [ebx][edi]
	mov cur, eax
	mov edx, 1

rows_eq:
	add edi, 4
	mov eax, [ebx][edi]
	cmp eax, cur
	jne skip
	mov edx, count
	mov[esi][edx * 4], ecx
	inc count
	jmp exit_
skip:
	inc edx
	cmp edx, M
	jl rows_eq


	mov edi, ecx
	imul edi, M
	imul edi, edi, 4

	inc inner_counter
	mov eax, inner_counter
	cmp eax, M
	je exit_
	imul eax, eax, 4
	add edi, eax
	mov eax, [ebx][edi]
	mov cur, eax
	mov edx, inner_counter
	inc edx
	jmp rows_eq

exit_:
	xor edx, edx
	xor edi, edi
	inc ecx
	cmp ecx, N
	jl cycle
	mov eax, count
	ret
_CreateVectorB endp
end