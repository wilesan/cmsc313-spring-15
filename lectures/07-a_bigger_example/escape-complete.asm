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

msg_unknown_escape: db "Error: unknown escape sequence \ ", 10 ; Unknown escape sequence message
len_unknown_escape: equ $-msg_unknown_escape

msg_octal_overflow: db "Error: octal value overflow in \   ", 10 ; Unknown escape sequence message
len_octal_overflow: equ $-msg_octal_overflow

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
		xor		ebx, ebx				; Zero character check register
loop:
		mov		bl, [rbuf + esi]		; get a character into the buffer
		cmp		bl, '\'					; Check if it is a backslash
		je		is_backslash			; It is a backslash
		mov		[dbuf + edi], bl		; Copy source into destination
		inc		esi						; Increment source
		inc		edi						; Increment destination
		cmp		esi, [rlen]				; Compare esi to the length of the original buffer
		jne		loop					; Loop if they aren't equal
		jmp		done					; If they are equal - jump to done

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
		xor		eax, eax				; Zero eax
		xor		ecx, ecx				; Zero ecx

octal_loop:
		cmp		bl, '0'					; See if we're in octal range
		jl		not_octal_digit			; Handle case where this isn't an octal digit
		cmp		bl, '7'					; See if we're within hi end of octal
		jg		not_octal_digit			; Handle case where this isn't an octal digit
		sub		bl, '0'					; Convert ASCII to number
		shl		eax, 3					; Multiply anything in eax by 8
		add		eax, ebx				; Add the current digit to the total
		inc		ecx						; Increment the octal byte count
		inc		esi						; Increment the source index
		mov		bl, [rbuf + esi]		; get a character into the buffer
		cmp		ecx, 3					; Check if we've gotten 3 octal characters
		jne		octal_loop				; Loop for next character
		cmp		eax, 255				; Check if eax is 255 or less
		jg		octal_out_of_range		; Octal code is out of range

not_octal_digit:
		cmp		ecx, 0					; No octal digits were found - output error string
		je		invalid_escape			; If ecx > 0, continue loop
		mov		[dbuf + edi], al		; Move octal code into destination
		inc		edi
		jmp		loop

invalid_escape:
		mov		[msg_unknown_escape+len_unknown_escape-2], byte bl
		mov		eax, SYSCALL_WRITE
		mov		ebx, STDOUT
		mov		ecx, msg_unknown_escape
		mov		edx, len_unknown_escape
		int		080h
		inc		esi
		jmp		loop

octal_out_of_range:
		; An octal overflow MUST be 3-digits long
		mov		al, [rbuf + esi - 3]
		mov		[msg_octal_overflow + len_octal_overflow - 4], al
		mov		al, [rbuf + esi - 2]
		mov		[msg_octal_overflow + len_octal_overflow - 3], al
		mov		al, [rbuf + esi - 1]
		mov		[msg_octal_overflow + len_octal_overflow - 2], al
		mov     eax, SYSCALL_WRITE      ; write message
        mov     ebx, STDOUT
        mov     ecx, msg_octal_overflow
        mov     edx, len_octal_overflow
        int     080h

		jmp		loop					; We're done

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
