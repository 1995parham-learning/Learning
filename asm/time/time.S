/*
 * In The Name Of God
 * ========================================
 * [] File Name : time.S
 *
 * [] Creation Date : 12-01-2015
 *
 * [] Last Modified : Mon 12 Jan 2015 09:51:18 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
.section .text
	.global main
main:
	movq	$0, %rax
	movq	$0, %rdx

	rdtsc

	movq	$1, %rax
	movq	$0, %rbx
	int	$0x80
