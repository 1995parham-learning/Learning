/*
 * In The Name Of God
 * ========================================
 * [] File Name : address.S
 *
 * [] Creation Date : 22-01-2015
 *
 * [] Last Modified : Thu Jan 22 10:29:22 2015
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
	/* %ebx = *(A + 1 * 4) */
	movl	A(, 1, 4), %ebx
	/* %rcx = A */
	movq	$A, %rcx
	/* %rdx = A */
	leaq	A, %rdx
	/* %rdi = A */
	leaq	A(%rip), %rdi
