/*
 * In The Name Of God
 * ========================================
 * [] File Name : mac-hello.S
 *
 * [] Creation Date : 15-01-2015
 *
 * [] Last Modified : Thu Jan 15 19:42:09 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/

/*
* I think all 64-bit code on Mac is required to be rip relative.
* Absolute addresses are not supported, so you can't load one in a register.
* On OS X, the symbols are prefixed with an underscore.
*
* 0x2000001 : exit syscall number
* 0x2000004 : write syscall number
*
* I HATE OSX ......
*/

.data
	str: .asciz "Hello world of Mac binary\n"
	.equ strlen, . - str
.text
	.global _main
_main:
	movq	$0x2000004, %rax
	movq	$1, %rdi
	leaq	str(%rip), %rsi
	movq	$strlen, %rdx
	syscall
	movq	$0x2000001, %rax
	movq	$0, %rdi
	syscall	
