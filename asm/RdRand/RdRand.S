/*
 * In The Name Of God
 * ========================================
 * [] File Name : RdRand.S
 *
 * [] Creation Date : 06-02-2015
 *
 * [] Last Modified : Fri 06 Feb 2015 11:37:59 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
.section .text
.global main
main:
	rdrand	%rax
	movq	$60, %rax
	movq	$0, %rdi
	syscall
