%include "syscall/io.inc"
%include "syscall/std.inc"
%include "profile.inc"

global _start 

%assign SIZE 4

section .text

_start:
	prologue SIZE

	lea rbp, [rbp - SIZE]

	read STDIN_FILENO, rbp, SIZE
	write STDOUT_FILENO, rbp, SIZE

	lea rbp, [rbp + SIZE]

	epilogue

	exit 0
