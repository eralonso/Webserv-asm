%include "syscall/io.inc"
%include "syscall/std.inc"
%include "profile.inc"
%include "funcall.inc"
%include "instructions.inc"
%include "statements.inc"

global _start 

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

putchar:

	prologue 1

	mov byte [rbp - 1], dil
	lea rsi, [rbp - 1]

	write STDOUT_FILENO, rsi, 1

	epilogue

	ret

_start:

	prologue 1

	; funcall introduction

	mov byte [rbp - 1], 1

	while byte [rbp - 1], le, 5

		movzx rdi, byte [rbp - 1]
		add rdi, '0'
		funcall putchar, rdi

		if byte [rbp - 1], e, 3
			break
		endif

		inc byte [rbp - 1]

	endwhile

	funcall putchar, `\n` 

	epilogue

	exit 0

section .data
msg: db `Starting Webserver...\n\0`
	.len equ $ - msg
