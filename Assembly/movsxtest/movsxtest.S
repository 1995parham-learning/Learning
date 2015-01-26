/*
 * In The Name Of God
 * ========================================
 * [] File Name : movsxtest.S
 *
 * [] Creation Date : 21-01-2015
 *
 * [] Last Modified : Mon 26 Jan 2015 11:19:16 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
.section .text
.global main
main:
	movw	$-79, %cx
	movl	$0, %ebx
	movw	%cx, %bx
	movswl	%cx, %eax
	movq	$60, %rax
	movq	$0, %rdi
	syscall
