section .bss
	array: resb 10
stack	resb 4096
section .text
	global main
main:
	mov eax, 3
	mov ebx, 0
	mov ecx, array
	mov edx, 10
	int 0x80
	pop rax
	mov eax, 1
	mov ebx, 0
	int 0x80
