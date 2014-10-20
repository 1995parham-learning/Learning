section .data
	format: db "multiplication asnwer is : %d", 10, 0
section .text
	global main
	extern printf
main:
	mov rax, 10
	mov rbx, 22
	call bit_mul
	mov rsi, rdi

	mov rax, 0
	mov rdi, format
	call printf

	mov eax, 1
	mov ebx, 0
	int 80H

bit_mul:
	mov rdx, 1	; bit-mask
	mov cl, 0	; counter
	mov rdi, 0	; answer destination

bit_mul_loop:
	test rdx, rbx
	jz bit_mul_shift
	
	mov rsi, rax
	shl rsi, cl
	add rdi, rsi

bit_mul_shift:
	shl rdx, 1
	jc bit_mul_ret
	inc cl
	jmp bit_mul_loop

bit_mul_ret:
	ret
