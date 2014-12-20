; In The Name Of God
; ========================================
; [] File Name : 
; 
; [] Creation Date : 21-12-2014
;
; [] Last Modified : Sun 21 Dec 2014 01:54:00 AM IRST
;
; [] Created By : Parham Alvani (parham.alvani@gmail.com)
; =======================================
section .data
	hello:	db "Hello world!!",10,0		; 'Hello world!' plus a linefeed character
	helloLen:	equ $-hello	; Length of the 'Hello world!' string
					; (I'll explain soon)
	array: times 64 db 0

section .text
	global main
main:
	mov eax,$		; Current line address move to eax
	
	mov eax,array		; Move array address to eax

	;mov array,10
	;mov array+1,20

	mov al,[array]
	mov ah,[array+1]

	mov eax,4		; The system call for write (sys_write)
	mov ebx,1		; File descriptor 1 - standard output
	mov ecx,hello		; Put the offset of hello in ecx
	mov edx,helloLen	; helloLen is a constant, so we don't need to say
			     	; mov edx,[helloLen] to get it's actual value
	int 80h              	; Call the kernel
	mov eax,1            	; The system call for exit (sys_exit)
	mov ebx,0            	; Exit with return code of 0 (no error)
	int 80h
	ret
