/*
 * In The Name Of God
 * ========================================
 * [] File Name : floattest.S
 *
 * [] Creation Date : 23-01-2015
 *
 * [] Last Modified : Fri 23 Jan 2015 03:26:15 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
.section .data
value1:
	.float 12.34
value2:
	.double 2353.631
.section .bss
	.lcomm data, 8
.section .text
.global main
main:
	flds	value1
	fldl	value2
	fstl	data

	movq	$60, %rax
	movq	$0, %rdi
	syscall
