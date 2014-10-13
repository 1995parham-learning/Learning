section .text
	global parham_print
parham_print:
	push rcx
	mov rcx, rdi
	
	push rdx
	mov rdx, rsi

	mov rax, 4

	push rbx
	mov rbx, 1

	int 80h

	pop rbx
	pop rdx
	pop rcx

	ret
