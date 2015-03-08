/*
 * In The Name Of God
 * ========================================
 * [] File Name : sub.S
 *
 * [] Creation Date : 09-03-2015
 *
 * [] Last Modified : Mon 09 Mar 2015 12:24:58 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
.section .data
str:
	.asciz	"Hello 2-complement\n"
	

.section .text
.global main
main:
	movq	$10, %rax
	movq	$20, %rbx
	subq	%rbx, %rax

	jnc	quit
	movq	$0, %rax
	movq	$str, %rdi
	call	printf

quit:
	movq	$80, %rax
	movq	$0, %rdi
	syscall
