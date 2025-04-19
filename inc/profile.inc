%ifndef _PROFILE_INC_
	%define _PROFILE_INC_

	%macro prologue 1
		push rbp
		mov rbp, rsp
		sub rsp, %1
	%endmacro

	%macro epilogue 0
		mov rsp, rbp
		pop rbp
	%endmacro

%endif
