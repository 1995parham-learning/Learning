/*
 * In The Name Of God
 * ========================================
 * [] File Name : floattest.S
 *
 * [] Creation Date : 23-01-2015
 *
 * [] Last Modified : Sun 15 Feb 2015 10:48:46 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
.section .data
value1:
	.float 12.34
value2:
	.double -0.75
.section .bss
	.lcomm data, 8
.section .text
.global main
main:
	flds	value1
	fldl	value2
	fstl	data
	movq	data, %rax

	movq	$60, %rax
	movq	$0, %rdi
	syscall
