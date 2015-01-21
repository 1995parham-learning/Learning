/*
 * In The Name Of God
 * ========================================
 * [] File Name : movsxtest.S
 *
 * [] Creation Date : 21-01-2015
 *
 * [] Last Modified : Wed 21 Jan 2015 09:34:04 PM IRST
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
	movsx	%cx, %eax
	movq	$60, %rax
	movq	$0, %rdi
	syscall
