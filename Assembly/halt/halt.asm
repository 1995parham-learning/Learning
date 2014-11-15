section .text
	global _start
_start:
	hlt

	mov eax, 1
	mov ebx, 0
	int 80H
