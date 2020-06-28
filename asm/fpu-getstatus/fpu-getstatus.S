/*
 * In The Name Of God
 * ========================================
 * [] File Name : fpu-getstatus.S
 *
 * [] Creation Date : 26-01-2015
 *
 * [] Last Modified : Mon 26 Jan 2015 11:24:45 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
.section .bss
	.lcomm status, 2
.section .text
.global main
main:
	/*
	 * The FPU status register can be read into doubleword
	 * memory location or the AX register, using FSTSW instruction
	*/
	fstsw	%ax
	fstsw	status

	movq	$60, %rax
	movq	$0, %rdi
	syscall
