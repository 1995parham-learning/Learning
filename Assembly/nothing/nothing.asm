; In The Name Of God
; ========================================
; [] File Name : nothing.asm
; 
; [] Creation Date : 21-12-2014
;
; [] Last Modified : Sun 21 Dec 2014 01:59:43 AM IRST
;
; [] Created By : Parham Alvani (parham.alvani@gmail.com)
; =======================================
section .data
	hello: db "Hello world!", 10, 0
	hello_len equ $-hello

section .text
	global hello_writer
hello_writer:
	mov eax, 4
	mov ebx, 1
	mov ecx, hello
	mov edx, hello_len
	int 0x80
	mov eax, 4
	mov ebx, 1
	mov rcx, rdi
	mov rdx, rsi
	int 0x80
	mov eax, -1
	ret
