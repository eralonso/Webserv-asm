%ifndef _INSTRUCTIONS_INC_
	%define _INSTRUCTIONS_INC_

	; Move by dereference twice the first parameter
	%macro movdd1 3

		push rax
		mov rax, [%1]
		mov %3 [rax], %2
		pop rax

	%endmacro

	; Move by dereference twice the second parameter
	%macro movdd2 3

		push rax
		mov rax, [%2]
		mov %1, %3 [rax]
		pop rax

	%endmacro

	; Compare by dereference twice the first parameter
	%macro cmpdd1 3

		push rax
		mov rax, [%1]
		cmp %3 [rax], %2
		pop rax

	%endmacro

%endif
