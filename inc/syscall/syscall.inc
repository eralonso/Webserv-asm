%ifndef _SYSCALL_INC_
	%define _SYSCALL_INC_

	%macro syscall_movreg1 1
		mov rax, %1
	%endmacro

	%macro syscall_movreg2 1
		mov rdi, %1
	%endmacro

	%macro syscall_movreg3 1
		mov rsi, %1
	%endmacro

	%macro syscall_movreg4 1
		mov rdx, %1
	%endmacro

	%macro syscall_movreg5 1
		mov r10, %1
	%endmacro

	%macro syscall_movreg6 1
		mov r8, %1
	%endmacro

	%macro syscall_movreg7 1
		mov r9, %1
	%endmacro

	%macro syscall_join 3
		%1%2 %3
	%endmacro

	; The limit of 7 can be replaced by * to accept unlimited parameters.
	; But then it must have created the function syscall_movreg*.
	%macro syscall 1-7

		%assign %%i 1

		%rep %0
			syscall_join syscall_movreg, %%i, %1
			%rotate 1
			%assign %%i %%i + 1
		%endrep

		syscall

	%endmacro

%endif
