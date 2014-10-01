section .text
	global main
main:
	mov eax, 0
	mov ebx, 2
wall:
	add eax, ebx
	jmp wall
