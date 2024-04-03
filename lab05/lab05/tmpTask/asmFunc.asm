.686
PUBLIC @mul2@4

.MODEL FLAT

.CODE
@mul2@4 proc
mov eax, ecx ;first param
mov ebx, 2
imul ebx
ret
@mul2@4 ENDP

END