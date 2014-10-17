BITS 64
section .data
	string: db "Hello world of syscall !!!", 10, 0
	len: equ $ - string
section .text
	global _start
_start:
	mov rax, 1
	mov rdi, 1
	mov rsi, string
	mov rdx, len
	syscall

	mov rax, 60
	mov rdi, 0
	syscall
