; File: switch.asm
;
; Demonstrate jump tables
;
;

%define STDIN 0
%define STDOUT 1
%define SYSCALL_EXIT  1
%define SYSCALL_READ  3
%define SYSCALL_WRITE 4
%define BUFLEN 256


        SECTION .data                   ; initialized data section

mesg1:  db "Make a selection [a, b, c, d or f]: "           
len1:   equ $ - mesg1

err_mesg:       db "Read Error", 10
err_len:        equ $ - err_mesg
        

mesga:  db "Good choice!", 10 
lena:   equ $ - mesga

mesgb:  db "b is my favorite", 10 
lenb:   equ $ - mesgb

mesgc:  db "c is a popular selection", 10 
lenc:   equ $ - mesgc

mesgd:  db "Sorry, we are fresh out of d", 10 
lend:   equ $ - mesgd

mesgf:   db "Not a good day for f. Try something else.", 10
lenf:   equ $-mesgf

dflt_mesg: db "Please pick one of the choices!", 10
dflt_len:  equ $ - dflt_mesg

jump_table:
        dd do_a         ; dd = "define double" = 32-bit data
        dd do_b
        dd do_c
        dd do_d
        dd do_default
        dd do_f


        SECTION .bss                    ; uninitialized data section
buf:    resb BUFLEN                     ; buffer for read


        SECTION .text                   ; Code section.
        global  _start                  ; let loader see entry point

_start: 

        ; prompt user for input
        ;
        mov     eax, SYSCALL_WRITE      ; write function
        mov     ebx, STDOUT             ; Arg1: file descriptor
        mov     ecx, mesg1              ; Arg2: addr of message
        mov     edx, len1               ; Arg3: length of message
        int     080h                    ; ask kernel to write

        ; read user input
        ;
        mov     eax, SYSCALL_READ       ; read function
        mov     ebx, STDIN              ; Arg 1: file descriptor
        mov     ecx, buf                ; Arg 2: address of buffer
        mov     edx, BUFLEN             ; Arg 3: buffer length
        int     080h

        ; error check
        ;
        cmp     eax, 0                  ; check if any chars read
        jg      read_OK                 ; >0 chars read = OK
        mov     eax, SYSCALL_WRITE      ; ow print error mesg
        mov     ebx, STDOUT
        mov     ecx, err_mesg
        mov     edx, err_len
        int     080h
        jmp     exit                    ; skip over rest
read_OK:

        mov     eax, 0
        mov     al, [buf]               ; get a character
        cmp     al, 'a'                 ; below 'a'?
        jb      do_default 
        cmp     al, 'f'                 ; above 'f'?
        ja      do_default 

        sub     eax, 'a'                ; calculate offset      
        jmp     [4*eax + jump_table]


do_a:
        mov     eax, SYSCALL_WRITE      ; write message for choice a
        mov     ebx, STDOUT
        mov     ecx, mesga
        mov     edx, lena
        int     080h
        jmp     exit

do_b:
        mov     eax, SYSCALL_WRITE      ; write message for choice b
        mov     ebx, STDOUT
        mov     ecx, mesgb
        mov     edx, lenb
        int     080h
        jmp     exit

do_c:
        mov     eax, SYSCALL_WRITE      ; write message for choice c
        mov     ebx, STDOUT
        mov     ecx, mesgc
        mov     edx, lenc
        int     080h
        jmp     exit

do_d:
        mov     eax, SYSCALL_WRITE      ; write message for choice d
        mov     ebx, STDOUT
        mov     ecx, mesgd
        mov     edx, lend
        int     080h
        jmp     exit

do_f:
        mov     eax, SYSCALL_WRITE      ; write message for choice f
        mov     ebx, STDOUT
        mov     ecx, mesgf
        mov     edx, lenf
        int     080h
        jmp     exit

do_default:
        mov     eax, SYSCALL_WRITE      ; write message for default
        mov     ebx, STDOUT
        mov     ecx, dflt_mesg
        mov     edx, dflt_len
        int     080h
        jmp     exit


        ; final exit
        ;
exit:   mov     EAX, SYSCALL_EXIT       ; exit function
        mov     EBX, 0                  ; exit code, 0=normal
        int     080h                    ; ask kernel to take over
