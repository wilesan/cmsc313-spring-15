; File: rep.asm
; 
; Demonstrates the use of the REP prefix with
; string instructions.
;
; This program does no I/O. Use gdb to examine its effects.
;
	SECTION	.data			; Data section

msg:	db "Hello, world", 10		; The string to print.
len: 	equ $-msg

	SECTION .text			; Code section.
	global _start
_start: nop				; Entry point.

find:	mov	al, 'o'			; look for an 'o'
	mov	edi, msg		; here
	mov	ecx, len		; limit repetitions
	cld				; auto inc edi
	repne scasb			; while (al != [edi])
	jnz	not_found		; 
	mov	bl, [edi-1]		; what did we find?
not_found:

erase:	mov	edi, msg		; where?
	mov	ecx, len		; how many bytes?
	mov	al, '?'			; with which char?
	cld				; auto inc edi
	rep stosb

alldone:
	mov	ebx, 0			; exit code, 0=normal
	mov	eax, 1			; Exit.
	int	80H			; Call kernel.
