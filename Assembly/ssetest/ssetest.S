/*
 * In The Name Of God
 * ========================================
 * [] File Name : ssetest.S
 *
 * [] Creation Date : 23-01-2015
 *
 * [] Last Modified : Fri 23 Jan 2015 01:07:51 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
.section .data
values1:
	.int 1, -1, 0, 135246
values2:
	.align 16
	.quad 1, -1
.section .text
.global main
main:
	movdqu	values1, %xmm0
	movdqa	values2, %xmm1

	movq	$60, %rax
	movq	$0, %rdi
	syscall
