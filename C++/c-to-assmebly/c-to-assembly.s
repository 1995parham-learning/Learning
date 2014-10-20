	.file	"c-to-assembly.c"
	.intel_syntax noprefix
	.globl	b
	.data
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	10
	.comm	c,4,4
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR [rbp-20], edi
	mov	QWORD PTR [rbp-32], rsi
	mov	DWORD PTR [rbp-4], 20
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
