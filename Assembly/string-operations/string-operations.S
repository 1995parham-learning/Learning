/*
 * In The Name Of God
 * ========================================
 * [] File Name : string-operations.S
 *
 * [] Creation Date : 12-01-2015
 *
 * [] Last Modified : Mon 12 Jan 2015 09:50:14 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
.section .data
	s1: .asciz "Hello world of assmebly\n"
	.equ s1_len, . - s1
.section .bss
	.lcomm s2, 100
.section .text
	.global main
main:
	movq	$s1_len, %rcx
	movq	$s1, %rsi
	movq	$s2, %rdi
	rep	movsb

	movl	$4, %eax
	movl	$1, %ebx
	movl	$s2, %ecx
	movl	$s1_len, %edx
	int	$0x80

	movl	$1, %eax
	movl	$0, %ebx
	int	$0x80
