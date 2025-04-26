%ifndef _STATEMENTS_INC_
	%define _STATEMENTS_INC_

	%assign BREAK_MAX_DEEP 6 

	%macro if 3
		%push if

		cmp %1, %3
		j%-2 %$ifnot
	%endmacro

	%macro else 0
		%ifctx if
			%repl else
			jmp %$ifend

			%$ifnot:
		%elifnctx break
			%error "Expected 'if' before 'elif'"
		%endif

	%endmacro

	%macro endif 0
		%ifctx if
			%$ifnot:
				%pop
		%elifctx else
			%$ifend:
				%pop
		%elifnctx break
			%error "Expected 'if' or 'else' before 'endif'"
		%endif

	%endmacro

	%macro while 3

		%push while

		%$whilecmp:
			cmp %1, %3
			j%-2 %$whilenot

	%endmacro

	; while -> + while
	; 	if -> + if
	; 		break -> - if -> while <-> break
	; 	endif -> break
	; endwhile -> - break

	%macro break 0

		%rep BREAK_MAX_DEEP
			%ifctx while
				%repl break
				jmp %$whileend
			%elifnctx break
				%pop
				; %pop
				; %error "Expected some kind of loop before 'break'"
			%endif
		%endrep

		%ifnctx break
			%error "Expected some kind of loop before 'break'"
		%endif

	%endmacro

	%macro endwhile 0

		%ifctx while
			jmp %$whilecmp

			%$whilenot:
				%pop
		%elifctx break
			%$whileend:
				%pop
		%else
			%error "Expected 'while' before 'endwhile'"
		%endif


	%endmacro

%endif
