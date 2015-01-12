.section .text
	.global main
main:
	movq	$0, %rax
	movq	$0, %rdx

	rdtsc

	movq	$1, %rax
	movq	$0, %rbx
	int	$0x80
