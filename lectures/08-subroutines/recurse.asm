; File: recursive.asm
;
; example of subroutines in assembly language.

%define STDOUT 1
%define SYSCALL_EXIT  1
%define SYSCALL_WRITE 4

        SECTION .data                   ; initialized data section

msg1:   db "Hello World", 10, 0         ; C-style \0 terminated string

msg2:   db 10, "Good-bye, blue sky", 10, 0

char:   db 0, 0                         ; single char followed by \0


        SECTION .text                   ; Code section.
        global  _start                  ; let loader see entry point

_start: nop                             ; Entry point.
pstart:                                 ; address for gdb

        mov     eax, msg1               ; print first string
        call    print

        mov     al, '5'
        call    recurse

        mov     eax, msg2               ; print second string
        call    print


        ; final exit
        ;
pexit:  mov     eax, SYSCALL_EXIT       ; exit function
        mov     ebx, 0                  ; exit code, 0=normal
        int     080h                    ; ask kernel to take over


; A recursive subroutine
; counts down to '0'
; parameter stored in register al

recurse:
        cmp     al, '0'                 ; don't go below '0'
        jae     rcont   
        ret                             ; go back       

rcont:  push    ax                      ; save al 
        dec     al                      ; param for recursive call
        call    recurse                 ; recursively count down
        pop     ax                      ; restore count 
        mov     [char], al              ; prepare string for printing
        mov     eax, char               ; parameter for print subroutine
        call    print
        ret


; Subroutine print
; writes null-terminated string with address in eax
;
print:
        ; find \0 character and count length of string
        ;
        mov     edi, eax                ; use edi as index
        mov     edx, 0                  ; initialize count

count:  cmp     [edi], byte 0           ; null char?
        je      end_count
        inc     edx                     ; update index & count
        inc     edi
        jmp     short count
end_count:

        ; make syscall to write
        ; edx already has length of string
        ;
        mov     ecx, eax                ; Arg3: addr of message
        mov     eax, SYSCALL_WRITE      ; write function
        mov     ebx, STDOUT             ; Arg1: file descriptor
        int     080h                    ; ask kernel to write
        ret                             

; end of subroutine
