.686

public @calculateSqrt@8

.model flat

.code

	@calculateSqrt@8 proc
	finit  
	fld dword ptr[edx] 
	fld dword ptr[edx]
	_loop:

		fld1
		fld1
		fadd
		fdivp st(1), st(0) ; x/2 a
		fld st(0) ; x/2 x/2 a

		fld1
		fld1
		fadd
		fmul ; x x/2 a
		fld st(2)
		fld1
		fld1
		fadd

		fdivp st(1), st(0) ; a/2 x x/2 x a

		fdivrp
		faddp st(1), st(0)
   
		loop _loop

		;ret
	@calculateSqrt@8 endp

END