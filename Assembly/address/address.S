/*
 * In The Name Of God
 * ========================================
 * [] File Name : address.S
 *
 * [] Creation Date : 22-01-2015
 *
 * [] Last Modified : Thu 22 Jan 2015 07:24:02 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
.section .data
A:
	.int	10, 20, 30, 40
B:
	.asciz	"Hello world"
.section .text
.global main
main:
	/*
	 * int A[] = {10, 20, 30, 40}
	 * A is C-like array
	*/
	/* %eax = *A */
	movl	A, %eax
	/*
	 * base_address and index must be register
	 * %ebx = *(A + 1 * 4)
	*/
	movq	$1, %rsi
	movl	A(, %rsi, 4), %ebx
	/* %rcx = A */
	movq	$A, %rcx
	/* %rdx = A */
	leaq	A, %rdx
	/* %rdi = A */
	leaq	A(%rip), %rdi
