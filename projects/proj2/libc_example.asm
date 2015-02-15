; libc_example.asm - example code using printf and atoi from the standard C library
; Last edited 02/15/2015
;
; Assemble using NASM:  nasm -f elf -g -F stabs libc_example.asm
; Link with gcc:  gcc -m32 -g -o libc_example libc_example.o
;


%define SYSCALL_EXIT  1

        SECTION .data                   ; initialized data section

numbers:   db "52 7000000", 0			; Numbers to convert
										; note the '0' at the end - all strings in C
										; are NULL-terminated, that is, there's a character
										; '0' at the end.

print_str:	db "Returned number: %d", 10, 0
										; Format string for printf
										; Note the use of the newline (10) and NULL (0)
										; characters.

        SECTION .text                   ; Code section.
extern printf							; Request access to printf
extern atoi								; Request access to atoi


        global  main					; let loader see entry point

main: nop                             	; Entry point- note NOT _start anymore
start:                                  ; address for gdb

        ; prompt user for input
        ;
        mov     esi, numbers			; Get address of numbers string
        push	esi						; Push address onto stack
        call	atoi					; Call atoi
        								; The resulting number is in eax
        add		esp, 4					; Remove esi from the stack
        push	eax						; Push the result of atoi onto the stack
        push	print_str				; Push the address of the formatted string onto the stack
        call	printf					; Call printf on the string
        								; Output should be: Returned number: 52
        add		esp, 8					; Remove message and previous atoi conversion from the stack

		inc		esi						; Advance the buffer pointer by one
        push	esi						; Push address onto stack
        call	atoi					; Call atoi
        								; The resulting number is in eax
        add		esp, 4					; Remove esi from the stack
        push	eax						; Push the result of atoi onto the stack
        push	print_str				; Push the address of the formatted string onto the stack
        call	printf					; Call printf on the string
        								; Output should be: Returned number: 2
        add		esp, 8					; Remove message and previous atoi conversion from the stack
        add		esi, 2					; Advance the buffer pointer by two
        push	esi						; Push address onto stack
        call	atoi					; Call atoi
        								; The resulting number is in eax
        add		esp, 4					; Remove esi from the stack
        push	eax						; Push the result of atoi onto the stack
        push	print_str				; Push the address of the formatted string onto the stack
        call	printf					; Call printf on the string
        								; Output should be: Returned number: 7000000
        add		esp, 8					; Remove message and previous atoi conversion from the stack
        add		esi, 2					; Advance the buffer pointer by two

        ; final exit
        ;
exit:   mov     eax, SYSCALL_EXIT       ; exit function
        mov     ebx, 0                  ; exit code, 0=normal
        int     080h                    ; ask kernel to take over
