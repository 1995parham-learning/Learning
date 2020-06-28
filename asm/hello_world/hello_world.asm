; vim: ft=nasm
; In The Name of God
; =======================================
; [] File Name : hello_world.asm
;
; [] Creation Date : 21-12-2014
;
; [] Created By : Parham Alvani <parham.alvani@gmail.com>
; =======================================
;
section .data
	hello: db "Hello world!!", 10 	; 'Hello world!\n'
	hello_length: equ $-hello	; Length of the 'Hello world!' string

section .text
global _start
_start:
	mov rax, 1		; The system call for write (sys_write)
	mov rdi, 1		; File descriptor 1 - standard output
	mov rsi, hello		; Put the offset of hello in rsi
	mov rdx, hello_length	; hello_length is a constant, so we don't need to say
			     	; mov rdx, [hello_length] to get it's actual value
	syscall              	; Call the kernel
	mov rax,60            	; The system call for exit (sys_exit)
	mov rdi,0            	; Exit with return code of 0 (no error)
	syscall
	ret
