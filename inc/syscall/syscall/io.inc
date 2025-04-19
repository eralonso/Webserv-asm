%ifndef _SYSCALL_IO_INC_
	%define _SYSCALL_IO_INC_

	%include "syscall.inc"

	%assign STDIN_FILENO 0
	%assign STDOUT_FILENO 1
	%assign STDERR_FILENO 2

	%assign SYS_write 1
	%assign SYS_read 0

	%macro write 3
		syscall SYS_write, %1, %2, %3
	%endmacro

	%macro read 3
		syscall SYS_read, %1, %2, %3
	%endmacro

%endif
