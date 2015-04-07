; File: main.asm 
;
; Example that calls do_array()
;



        SECTION .data                   ; initialized data section
array: dd 7, 9, 2, 4, 8


        SECTION .text
	extern do_array 
	global main

main:
        push    ebp		; set up stack frame
        mov     ebp,esp

before:
	push	add3		; function "pointer"
	push	dword 5
	push	array
	call	do_array
	add	esp, 12

after:

        mov     esp, ebp	; takedown stack frame
        pop     ebp
        ret

;
;  End of main()
;


; function prototype for add1 is:
;   int add3(int n) 

add3:	push    ebp		; set up stack frame
        mov     ebp,esp

	mov	eax, [ebp+8]	; eax gets first parameter
        add     eax, 3		; note eax also return value
  
        mov     esp, ebp	; takedown stack frame
        pop     ebp
        ret

