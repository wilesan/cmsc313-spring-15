; File: jmp.asm
;
; Demonstrating near and short jumps
;
	section .text
	global _start
_start:		nop
	; initialize
start:
	mov 	eax, 	17 	; eax := 17
	cmp 	eax, 	42 	; 17 - 42 is ...
	jge 	exit 		; exit if 17 >= 42
	jge 	short exit
	jge 	near exit

	jmp 	exit
	jmp 	short exit
	jmp 	near exit
exit:
	mov 	ebx, 	0 	; exit code, 0=normal
	mov 	eax, 	1 	; Exit.
 	int 	080H 		; Call kernel.
