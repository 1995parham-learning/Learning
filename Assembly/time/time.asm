section .text
	global main
main:
	mov rax, 0
	mov rdx, 0

	rdtsc

	mov rax, 1
	mov rbx, 0
	int 80H
