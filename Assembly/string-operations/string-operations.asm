section .date
	s1: db "Hello world of assmebly", 10
	s1_len: equ $ - s1
section .bss
	s2: resb 100
section .text
	global _start
_start:
	mov rcx, s1_len
	mov rsi, s1
	mov rdi, s2

	rep movsb

	mov eax, 4
	mov ebx, 1
	mov ecx, s2
	mov edx, s1_len
	int 80H

	mov eax, 1
	mov ebx, 0
	int 80H
