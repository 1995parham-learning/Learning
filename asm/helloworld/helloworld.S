/*
 * In The Name Of God
 * ========================================
 * [] File Name : helloworld.S
 *
 * [] Creation Date : 03-02-2015
 *
 * [] Last Modified : Tue 03 Feb 2015 03:11:22 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
.section .text
.global main
main:
	movl	$4, %eax
	movl	$1, %ebx
	movl	$message, %ecx
	movl	msglength, %edx
	int	$0x80
	movl	$1, %eax
	movl	$0, %ebx
	int	$0x80

.section .data
	message: .ascii "Hello world!\n"
	msglength: .word 13
