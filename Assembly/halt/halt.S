/*
 * In The Name Of God
 * ========================================
 * [] File Name : halt.S
 *
 * [] Creation Date : 12-01-2015
 *
 * [] Last Modified : Mon 12 Jan 2015 11:02:51 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
.section .text
	.global main
main:
	hlt

	movl	$1, %eax
	movl	$0, %ebx
	int	$0x80
