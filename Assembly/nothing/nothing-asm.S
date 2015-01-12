/*
 * In The Name Of God
 * ========================================
 * [] File Name : nothing-asm.S
 *
 * [] Creation Date : 12-01-2015
 *
 * [] Last Modified : Mon 12 Jan 2015 09:50:02 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
.section .data
	hello: .asciz "Hello world!\n"
	.equ hello_len, . - hello
.section .text
	.global hello_writer
hello_writer:
	movl	$4, %eax
	movl	$1, %ebx
	movl	$hello, %ecx
	movl	$hello_len, %edx
	int	$0x80
	
	movl	$4, %eax
	movl	$1, %ebx
	movq	%rdi, %rcx
	movq	%rsi, %rdx
	int	$0x80
	movl	$-1, %eax
	ret
