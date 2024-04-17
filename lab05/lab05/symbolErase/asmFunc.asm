.686
PUBLIC _DelSymbol@12
.model flat
.code

_DelSymbol@12 proc
push ebp
mov ebp, esp
mov esi, [ebp+8] ; начало строки
mov ecx, [ebp+12] ; длина строки

;mov bl, [ebp+16] Ч удал€емый элемент
mov edx, 0
mainLoop_:
	cmp ecx, edx
	je end_
	mov bl, [ebp+16]
	cmp bl, [esi + edx]
	jne contMainLoop_
	mov ebx, edx
	dec ecx
loopChange_:
	cmp ebx, ecx
	je preContMainLoop_
	mov al, [esi + ebx + 1]
	mov [esi + ebx], al
	inc ebx
	jmp loopChange_
preContMainLoop_:
	mov dword ptr[esi + ebx], 0
	dec edx
contMainLoop_:
	inc edx
	jmp mainLoop_
end_:
mov eax, esi
pop ebp
ret 12 
_DelSymbol@12 endp
end