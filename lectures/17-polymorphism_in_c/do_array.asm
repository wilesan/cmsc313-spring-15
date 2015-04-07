; File: do_array.asm
;
; Implements a C function with prototype:
;
;    void do_array(int A[], int size, INT_INT_FPTR fptr) ;
;
; do_array will apply *ftpr to each item of the array A[]
; and store the results in that item. The equivalent C
; code is:
;
;
;   void do_array(int A[], int size, INT_INT_FPTR fptr) {
;      int i ;
;   
;      for ( i = size ; i > 0 ; i--) {
;         A[i-1] = (* fptr) (A[i-1]) ;
;      }
;   }


	section .text
	global do_array


do_array:	push	ebp			; set up stack frame
		mov	ebp, esp

		push	esi			; save registers
		push	ebx

		mov	esi, [ebp+8]		; address of A[]
		mov	ebx, [ebp+12]		; size


	; use EBX as index and count down to process each int in A[]
	; 
loop:		cmp	ebx, 0			; done?
		jbe	done
		mov	eax, [esi+4*ebx-4]	; get A[i-1]

		push	eax			; parameter for (*fptr)
		mov	edx, [ebp+16]		; get fptr
		call	edx			; execute (*fptr)
		add	esp, 4			; "pop off" parameter

		mov	[esi+4*ebx-4], eax	; store return value

		dec	ebx			; do next item
		jmp	loop			

done:		pop	ebx			; restore registers
		pop	esi

		mov	esp, ebp	;	 take down stack frame
		pop	ebp
		ret

