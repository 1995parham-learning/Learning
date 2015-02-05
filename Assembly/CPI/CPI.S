/*
 * In The Name Of God
 * ========================================
 * [] File Name : CPI-asm.S
 *
 * [] Creation Date : 05-02-2015
 *
 * [] Last Modified : Thu 05 Feb 2015 10:37:39 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
.section .bss
	.lcomm PI, 8
.section .text
.global getPI
getPI:
	finit
	fldpi
	fstpl	PI
	movsd	PI, %xmm0
	ret
