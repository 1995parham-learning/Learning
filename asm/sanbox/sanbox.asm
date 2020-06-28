section .data
	n1: dq 100
	n2: db 100
	n3: db 100
section .text
	global _start
_start:
	mov eax, n1
	neg rax

	mov rax, _start

	mov bl, 2
	mov al, 2
	mul bl

	mov eax, 1
	mov ebx, 0
	int 80H
