.section .text
.global main
main:
	movq $0, %rax
	movq $2, %rbx
wall:
	leaq wall(%rip), %rax
	nop
	jmpq *%rax
