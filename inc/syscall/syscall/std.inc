%ifndef _SYSCALL_STD_INC_
	%define _SYSCALL_STD_INC_

	%include "syscall.inc"

	%assign SYS_exit 60

	%macro exit 1
		syscall SYS_exit, %1
	%endmacro

%endif
