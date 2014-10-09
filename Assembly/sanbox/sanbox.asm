section .text
	global main
main:
	mov eax, 1
	neg eax

	mov bl, 2
	mov al, 2
	mul bl

	mov eax, 1
	mov ebx, 0
	int 80H
