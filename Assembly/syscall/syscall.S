/*
 * In The Name Of God
 * ========================================
 * [] File Name : syscall.S
 *
 * [] Creation Date : 12-01-2015
 *
 * [] Last Modified : Mon 12 Jan 2015 09:50:39 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
.section .data
	string: .asciz "Hello world of syscall !!!\n"
	.equ len, . - string
.section .text
	.global main
main:
	movq	$1, %rax
	movq	$1, %rdi
	leaq	string(%rip), %rsi
	movq	$len, %rdx
	syscall

	movq	$60, %rax
	movq	$0, %rdi
	syscall
