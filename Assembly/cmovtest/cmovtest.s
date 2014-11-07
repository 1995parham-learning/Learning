.section .data
output:
	.asciz	"The largest value is %d\n"
values:
	.long	105, 235, 61, 315, 134, 221, 53, 145, 5
.section .text
.global main
main:
	movq values, %rbx
	movq $1, %rdi
loop:
	movq values(,%rdi,8), %rax
	cmp %rbx, %rax
	cmova %rax, %rbx
	inc %rdi
	cmp $10, %rdi
	jne loop
	movq %rbx, %rsi
	movq $output, %rdi
	call printf
	addq $8, %rsp
	pushq $0
	call exit
