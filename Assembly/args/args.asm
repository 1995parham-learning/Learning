section .text
	global _start
_start:
	pop rax
	pop rsi
	mov rax, 1
	mov rdi, 1
	mov rdx, 4
	syscall

	mov rax, 60
	mov rdi, 1
	syscall
