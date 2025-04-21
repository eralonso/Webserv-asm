%include "syscall/io.inc"
%include "syscall/std.inc"
%include "profile.inc"
%include "funcall.inc"

global _start 

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

section .text

print:
	prologue 8

	mov [rbp - 8], rdi
.loop_start:

	cmpdd1 rbp - 8, 0, byte
	je .loop_end

	write STDOUT_FILENO, [rbp - 8], 1

	inc byte [rbp - 8]
	jmp .loop_start

.loop_end:
	epilogue
	ret
	

introduction:

	; write STDOUT_FILENO, msg, msg.len
	funcall print, msg

	ret

_start:

	funcall introduction

	exit 0

section .data
msg: db `Starting Webserver...\n\0`
	.len equ $ - msg
