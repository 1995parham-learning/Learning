/*
 * In The Name Of God
 * ========================================
 * [] File Name : cmovtest.S
 *
 * [] Creation Date : 12-01-2015
 *
 * [] Last Modified : Thu Jan 15 18:28:50 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
.section .data
output:
	.asciz	"The largest value is %d\n"
values:
	.long	105, 235, 61, 315, 134, 221, 53, 145, 5
.section .text
.global main
main:
	xorq	%rbx, %rbx
	/* Move 105 to %rbx */
	movl	values, %ebx
	movq	$0, %rdi
loop:
	movl	values(, %rdi, 4), %eax
	cmp	%rbx, %rax
	cmova	%rax, %rbx
	inc	%rdi
	cmp	$10, %rdi
	jne	loop
	xorq	%rax, %rax
	movq	%rbx, %rsi
	/* Move address of output in %rdi */
	movq	$output, %rdi
	call	printf
	xorq	%rax, %rax
	movq	$0, %rdi
	call	exit
