	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp2:
	.cfi_def_cfa_offset 16
Ltmp3:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp4:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	leaq	L_.str(%rip), %rax
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$100, -20(%rbp)
	movl	-20(%rbp), %esi
	movq	%rax, %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str(%rip), %rdi
	movl	-20(%rbp), %esi
	## InlineAsm Start
	xorl	%esi, %esi

	## InlineAsm End
	movl	%esi, -20(%rbp)
	movl	-20(%rbp), %esi
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movl	$0, %esi
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	movl	%esi, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d\n"


.subsections_via_symbols
