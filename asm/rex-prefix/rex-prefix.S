/*
 * In The Name Of God
 * ========================================
 * [] File Name : rex-prefix.S
 *
 * [] Creation Date : 21-01-2015
 *
 * [] Last Modified : Wed 21 Jan 2015 10:57:14 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
.section .text
.global main
main:
	movw	$10, %ax
	movzx	%ax, %rax
	movw	%ax, %r8w
