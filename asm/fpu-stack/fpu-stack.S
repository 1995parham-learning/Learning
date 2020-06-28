/*
 * In The Name Of God
 * ========================================
 * [] File Name : fpu-stack.S
 *
 * [] Creation Date : 05-02-2015
 *
 * [] Last Modified : Thu 05 Feb 2015 09:38:14 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
.section .data
value1:
	.int 40
value2:
	.float 92.4405
value3:
	.double 221.440321

.section .bss
	.lcomm _int, 4
	.lcomm control, 2
	.lcomm status, 2
	.lcomm result, 4
.section .text
.global main
main:
	finit
	fstcw	control
	fstsw	status
	filds	value1
	fists	_int
	flds	value2
	fldl	value3
	fst	%st(4)
	fxch	%st(1)
	fstps	result
	movq	$60, %rax
	movq	$0, %rdi
	syscall
