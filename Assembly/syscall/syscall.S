.section .data
	string: .asciz "Hello world of syscall !!!\n"
	.equ len,. - string
.section .text
	.global main
main:
	movq	$1, %rax
	movq	$1, %rdi
	movq	$string, %rsi
	movq	$len, %rdx
	syscall

	movq	$60, %rax
	movq	$0, %rdi
	syscall
