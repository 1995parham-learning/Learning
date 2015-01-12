	.file	"c-to-assembly.c"
	.globl	A
	.data
	.align 4
	.type	A, @object
	.size	A, 4
A:
	.long	10
	.section	.rodata
.LC0:
	.string	"%p\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movl	$10, -16(%rbp)
	movl	$20, -12(%rbp)
	movl	A(%rip), %eax
	addl	$20, %eax
	movl	%eax, A(%rip)
	movl	$A, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -20(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L2
.L3:
	addl	$1, -20(%rbp)
.L2:
	cmpl	$9, -20(%rbp)
	jle	.L3
	movl	$3, %edx
	movl	$2, %esi
	movl	$1, %edi
	call	f
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	f
	.type	f, @function
f:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movl	A(%rip), %eax
	addl	$30, %eax
	movl	%eax, A(%rip)
	movl	-4(%rbp), %eax
	imull	-8(%rbp), %eax
	imull	-12(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	f, .-f
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
