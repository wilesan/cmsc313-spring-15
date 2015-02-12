; File: index2.asm
; 
; This program demonstrates the use of an indexed addressing mode
; to access 2 dimensional array elements.
;
; This program has no I/O. Use the debugger to examine its effects.
;
	SECTION	.data			; Data section

	; simulates a 2-dim array
twodim:
row1:	dd 00, 01, 02, 03, 04, 05, 06, 07, 08, 09 
row2:	dd 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 
	dd 20, 21, 22, 23, 24, 25, 26, 27, 28, 29 
	dd 30, 31, 32, 33, 34, 35, 36, 37, 38, 39 
	dd 40, 41, 42, 43, 44, 45, 46, 47, 48, 49 
	dd 50, 51, 52, 53, 54, 55, 56, 57, 58, 59 
	dd 60, 61, 62, 63, 64, 65, 66, 67, 68, 69 
	dd 70, 71, 72, 73, 74, 75, 76, 77, 78, 79 
	dd 80, 81, 82, 83, 84, 85, 86, 87, 88, 89 
	dd 90, 91, 92, 93, 94, 95, 96, 97, 98, 99 

rowlen: equ row2 - row1

	SECTION .text			; Code section.
	global _start
_start: nop				; Entry point.

	; Add 5 to each element of row 7. Simulate:
	;
	;  for (i = 0 ; i < 10 ; i++) {
	;     twodim[7][i] += 5 ;
	;  }

init1:	mov	ecx, 0			; ecx simulates i
	mov	eax, rowlen		; compute offset of twodim[7][0] 
	mov	edx, 7
	mul	edx			; eax := eax * edx
	jc	alldone			; 64-bit value product is bad

loop1:	cmp	ecx, 10			; i < 10 ?
	jge	done1
	add	[eax+4*ecx+twodim], dword 5
	inc	ecx			; i++
	jmp	loop1
done1:

alldone:
	mov	ebx, 0			; exit code, 0=normal
	mov	eax, 1			; Exit.
	int	80H			; Call kernel.
