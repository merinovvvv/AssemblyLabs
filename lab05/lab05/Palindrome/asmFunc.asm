.686

PUBLIC @isPalindrome@8

.MODEL FLAT

.code

@isPalindrome@8 PROC
    
    mov ebx, ecx ;first param
    mov eax, edx ;second param
    dec eax
    mov esi, 0 ; index begin
    mov edi, eax ; index end

isPalindromeCheck:
    cmp esi, edi
    jge isPalindrome

    mov al, byte PTR [ebx + esi ]
    mov cl, byte PTR [ebx + edi ]
    cmp al, cl
    jne notPalindrome

    inc esi
    dec edi
    jmp isPalindromeCheck

isPalindrome:
    mov eax, 1
    ret
notPalindrome:
    mov eax, 0
    ret
@isPalindrome@8 ENDP

END