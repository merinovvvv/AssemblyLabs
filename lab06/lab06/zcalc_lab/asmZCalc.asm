.686

PUBLIC _zCalc

.MODEL FLAT

.data
    one dq 1.0   ; Определение константы 1.0

.code

_zCalc PROC

    push ebp
    mov ebp, esp

    finit

    ;x^2 * tan(x/y)

    fld qword ptr [ebp + 16]   ; Загружаем параметр y из стека в стек FPU
    fld qword ptr [ebp + 8]  ; Загружаем параметр x из стека в стек FPU
    fdiv st(0), st(1)
    fptan                       ; Вычисляем тангенс st(0), результат помещается в st(0), тангенс становится st(1)
    fstp st(0)                 ; Сохраняем тангенс в стеке

    fld qword ptr [ebp + 8]   ; Загружаем параметр x из стека в стек FPU
    fmul ; st(0) * st(1)
    fld qword ptr [ebp + 8]   ; Загружаем параметр x из стека в стек FPU
    fmul; st(0) * st(1) ;!!!

    ;fstp qword ptr [a]  ; Сохраняем результат в переменной a


    ;y^2 * ctg(x/y)

    fld qword ptr [ebp + 16]   ; Загружаем параметр y из стека в стек FPU
    fld qword ptr [ebp + 8]  ; Загружаем параметр x из стека в стек FPU
    fdiv st(0), st(1)
    fptan                       ; Вычисляем тангенс st(0), результат помещается в st(0), тангенс становится st(1)
    fstp st(0)                 ; Сохраняем тангенс в стеке

    fld qword ptr [one]
    fdiv st(0), st(1) ; вычисляем котангенс
    fld qword ptr [ebp + 16]   ; Загружаем параметр y из стека в стек FPU
    fmul ;st(0) * st(1)
    fld qword ptr [ebp + 16]   ; Загружаем параметр y из стека в стек FPU
    fmul ;st(0) * st(1) ;!!!


    fadd st(0), st(3)


    mov esp, ebp
    pop ebp
    ret
    
    
_zCalc ENDP

END