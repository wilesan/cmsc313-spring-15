; File: escape.asm
;
; A Linux filter that expands C-style escape codes
;

%define STDIN 0
%define STDOUT 1
%define SYSCALL_EXIT  1
%define SYSCALL_READ  3
%define SYSCALL_WRITE 4
%define BUFLEN 256

        SECTION .data                   ; initialized data section

msg1:   db "String to un-escape: "		; user prompt
len1:   equ $-msg1                      ; length of first message
msg2:   db "Original: "                 ; original string label
len2:   equ $-msg2                      ; length of second message

msg3:   db "Convert:  "                 ; converted string label
len3:   equ $-msg3
msg4:   db 10, "Read error", 10         ; error message
len4:   equ $-msg4


        SECTION .bss                    ; uninitialized data section
rbuf:    resb BUFLEN                    ; buffer for read
rlen:   resb 4                          ; length
dbuf:	resb BUFLEN						; destination buffer

	section .text
	global _start
_start:		nop
	; initialize
start:
        ; prompt user for input
        ;
        mov     eax, SYSCALL_WRITE      ; write function
        mov     ebx, STDOUT             ; Arg1: file descriptor
        mov     ecx, msg1               ; Arg2: addr of message
        mov     edx, len1               ; Arg3: length of message
        int     080h                    ; ask kernel to write

        ; read user input
        ;
        mov     eax, SYSCALL_READ       ; read function
        mov     ebx, STDIN              ; Arg 1: file descriptor
        mov     ecx, rbuf               ; Arg 2: address of buffer
        mov     edx, BUFLEN             ; Arg 3: buffer length
        int     080h

        ; error check
        ;
        cmp     eax, 0                  ; check if any chars read
        jg      read_OK                 ; >0 chars read = OK
        mov     eax, SYSCALL_WRITE      ; print error mesg
        mov     ebx, STDOUT
        mov     ecx, msg4
        mov     edx, len4
        int     080h
        jmp     exit                    ; skip over rest
read_OK:
		; begin checking the input
		mov		[rlen], eax				; store value of rlen
		xor		edi, edi				; Zero destination offset
		xor		esi, esi				; Zero source offset
loop:
		mov		bl, [rbuf + esi]		; get a character into the buffer
		cmp		bl, '\'					; Check if it is a backslash
		je		is_backslash			; It is a backslash
		mov		[dbuf + edi], bl		; Copy source into destination
		inc		esi						; Increment source
		inc		edi						; Increment destination
		cmp		esi, [rlen]				; Compare esi to the length of the original buffer
		jne		loop					; Loop if they aren't equal

is_backslash:
		inc		esi						; We'll skip the backslash
		mov		bl, [rbuf + esi]		; Get the next character from the input stream
		cmp		bl, 'a'					; Check if it is an alert
		jne		not_alert				; Try the next escape character
		mov		[dbuf + edi], byte 7	; Add alert character to output
		jmp		advance_and_loop		; Go to next character

not_alert:
		cmp		bl, 'b'					; Check if it is a backspace
		jne		not_backspace			; Try the next escape character
		mov		[dbuf + edi], byte 8	; Add backspace character to output
		jmp		advance_and_loop		; Go to next character

not_backspace:
		cmp		bl, 't'					; Check if it is a tab
		jne		not_tab					; Try the next escape character
		mov		[dbuf + edi], byte 9	; Add tab character to output
		jmp		advance_and_loop		; Go to next character

not_tab:
		cmp		bl, 'n'					; Check if it is newline
		jne		not_newline				; Try the next escape character
		mov		[dbuf + edi], byte 10	; Add newline character to output
		jmp		advance_and_loop		; Go to next character

not_newline:
		cmp		bl, 'v'					; Check if it is a vertical tab
		jne		not_vtab				; Try the next escape character
		mov		[dbuf + edi], byte 11	; Add vertical tab character to output
		jmp		advance_and_loop		; Go to next character

not_vtab:
		cmp		bl, 'f'					; Check if it is a formfeed
		jne		not_formfeed			; Try the next esacpe character
		mov		[dbuf + edi], byte 12	; Add formfeed character to output
		jmp		advance_and_loop		; Go to next character

not_formfeed:
		cmp		bl, 'r'					; Check if it is a carriage return
		jne		not_carriagereturn		; Try the next escape character
		mov		[dbuf + edi], byte 13	; Add carriage return to output
		jmp		advance_and_loop		; Go to next character

not_carriagereturn:
		cmp		bl, '\'					; Check if it is a backslash
		jne		not_backslash			; Try the next escape character
		mov		[dbuf + edi], byte 92	; Add backslash to output
		jmp		advance_and_loop		; Go to next character

not_backslash:
		cmp		bl, '0'					; See if we're in octal range
		jl		octal_out_of_range		; Handle octal out of range problem
		cmp		bl, '7'					; See if we're within hi end of octal
		jg		octal_out_of_range		; Handle octal out of range problem

		jmp		done					; We're done

advance_and_loop:
		inc		esi						; Increment source
		inc		edi						; Increment destination
		jmp		loop					; Loop to next character

done:
        ; print out user input for feedback
        ;
        mov     eax, SYSCALL_WRITE      ; write message
        mov     ebx, STDOUT
        mov     ecx, msg2
        mov     edx, len2
        int     080h

        mov     eax, SYSCALL_WRITE      ; write user input
        mov     ebx, STDOUT
        mov     ecx, rbuf
        mov     edx, [rlen]
        int     080h

        ; print out converted string
        ;
        mov     eax, SYSCALL_WRITE      ; write message
        mov     ebx, STDOUT
        mov     ecx, msg3
        mov     edx, len3
        int     080h

        mov     eax, SYSCALL_WRITE      ; write out string
        mov     ebx, STDOUT
        mov     ecx, dbuf
        mov     edx, edi
        int     080h


        ; final exit
        ;
exit:   mov     eax, SYSCALL_EXIT       ; exit function
        mov     ebx, 0                  ; exit code, 0=normal
        int     080h                    ; ask kernel to take over
