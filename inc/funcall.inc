%ifndef _FUNCALL_INC_
	%define _FUNCALL_INC_

	%macro funcall_movreg1 1
		mov rdi, %1
	%endmacro

	%macro funcall_movreg2 1
		mov rsi, %1
	%endmacro

	%macro funcall_movreg3 1
		mov rdx, %1
	%endmacro

	%macro funcall_movreg4 1
		mov r10, %1
	%endmacro

	%macro funcall_movreg5 1
		mov r8, %1
	%endmacro

	%macro funcall_movreg6 1
		mov r9, %1
	%endmacro

	%macro funcall_join 3
		%1%2 %3
	%endmacro

	%macro funcall 1-*

		; Skip the first parameter what is the function to call.
		%rotate 1

		%assign %%i 1

		%rep %0 - 1
			funcall_join funcall_movreg, %%i, %1
			%rotate 1
			%assign %%i %%i + 1
		%endrep

		call %1
	%endmacro

%endif
