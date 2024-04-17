.686

PUBLIC _zCalc

.MODEL FLAT

.data
    one dq 1.0   ; ����������� ��������� 1.0

.code

_zCalc PROC

    push ebp
    mov ebp, esp

    finit

    ;x^2 * tan(x/y)

    fld qword ptr [ebp + 16]   ; ��������� �������� y �� ����� � ���� FPU
    fld qword ptr [ebp + 8]  ; ��������� �������� x �� ����� � ���� FPU
    fdiv st(0), st(1)
    fptan                       ; ��������� ������� st(0), ��������� ���������� � st(0), ������� ���������� st(1)
    fstp st(0)                 ; ��������� ������� � �����

    fld qword ptr [ebp + 8]   ; ��������� �������� x �� ����� � ���� FPU
    fmul ; st(0) * st(1)
    fld qword ptr [ebp + 8]   ; ��������� �������� x �� ����� � ���� FPU
    fmul; st(0) * st(1) ;!!!

    ;fstp qword ptr [a]  ; ��������� ��������� � ���������� a


    ;y^2 * ctg(x/y)

    fld qword ptr [ebp + 16]   ; ��������� �������� y �� ����� � ���� FPU
    fld qword ptr [ebp + 8]  ; ��������� �������� x �� ����� � ���� FPU
    fdiv st(0), st(1)
    fptan                       ; ��������� ������� st(0), ��������� ���������� � st(0), ������� ���������� st(1)
    fstp st(0)                 ; ��������� ������� � �����

    fld qword ptr [one]
    fdiv st(0), st(1) ; ��������� ���������
    fld qword ptr [ebp + 16]   ; ��������� �������� y �� ����� � ���� FPU
    fmul ;st(0) * st(1)
    fld qword ptr [ebp + 16]   ; ��������� �������� y �� ����� � ���� FPU
    fmul ;st(0) * st(1) ;!!!


    fadd st(0), st(3)


    mov esp, ebp
    pop ebp
    ret
    
    
_zCalc ENDP

END