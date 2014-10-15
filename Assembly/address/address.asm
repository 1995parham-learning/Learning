section .data
	A: db '1', '2', '3', '4'
section .text
	global main
main:
	mov rax, A
	mov rbx, [rax]
	inc rax
	mov rbx, [rax]
	
	mov rbx, [rax + 1]

	mov rax, 1
	mov rbx, [A + rax]
	mov rbx, [A + 2]

	mov rax, [0x000000000000]

	mov rax, 1
	mov rbx, 0
	int 80H
