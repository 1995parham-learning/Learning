/*
 * In The Name Of God
 * ========================================
 * [] File Name : mul.S
 *
 * [] Creation Date : 23-01-2015
 *
 * [] Last Modified : Fri 23 Jan 2015 12:49:40 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/

/*
 * This function get two input parameter in %rdi and %rsi
 * and then put their mul reuslt in %rax
 *
 * long long shift_mul(long long n1, long long n2);
*/

.section .text
.global shift_mul
shift_mul:
	pushq	%rbp
	movq	%rsp, %rbp
	
	/* Bit Mask Register */
	movq	$1, %rax
	/* Bit Counter Register */
	xorq	%rcx, %rcx
	/* Answer Buffer */
	xorq	%rdx, %rdx
L1loop:
	cmp	$64, %rcx
	jae	L1end
	test	%rsi, %rax
	jnz	L1body

L1cont:
	incq	%rcx
	shlq	%rax
	jmp	L1loop

L1body:
	movq	%rdi, %rbx
	shlq	%cl, %rdi
	addq	%rdi, %rdx
	movq	%rbx, %rdi
	jmp	L1cont

L1end:
	movq	%rdx, %rax

	leave
	ret
