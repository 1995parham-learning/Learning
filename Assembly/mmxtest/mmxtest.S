/*
 * In The Name Of God
 * ========================================
 * [] File Name : mmxtest.S
 *
 * [] Creation Date : 21-01-2015
 *
 * [] Last Modified : Wed 21 Jan 2015 09:53:53 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
.section .data
values1:
	.int 1, -1
values2:
	.byte 0x10, 0x05, 0xff, 0x32, 0x47, 0xe4, 0x00, 0x01
.section .text
.global main
main:
	movq	values1, %xmm0
	movq	values2, %xmm1
	movq	$60, %rax
	movq	$0, %rdi
	syscall
