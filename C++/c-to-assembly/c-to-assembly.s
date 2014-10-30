	.file	"c-to-assembly.c"
	.intel_syntax noprefix
	.stabs	"/home/parham/Documents/Git/Learning/C++/c-to-assembly/",100,0,2,.Ltext0
	.stabs	"c-to-assembly.c",100,0,2,.Ltext0
	.text
.Ltext0:
	.stabs	"gcc2_compiled.",60,0,0,0
	.stabs	"int:t(0,1)=r(0,1);-2147483648;2147483647;",128,0,0,0
	.stabs	"char:t(0,2)=r(0,2);0;127;",128,0,0,0
	.stabs	"long int:t(0,3)=@s64;r(0,3);01000000000000000000000;0777777777777777777777;",128,0,0,0
	.stabs	"unsigned int:t(0,4)=r(0,4);0;037777777777;",128,0,0,0
	.stabs	"long unsigned int:t(0,5)=@s64;r(0,5);0;01777777777777777777777;",128,0,0,0
	.stabs	"__int128:t(0,6)=@s128;r(0,6);02000000000000000000000000000000000000000000;01777777777777777777777777777777777777777777;",128,0,0,0
	.stabs	"__int128 unsigned:t(0,7)=@s128;r(0,7);0;03777777777777777777777777777777777777777777;",128,0,0,0
	.stabs	"long long int:t(0,8)=@s64;r(0,8);01000000000000000000000;0777777777777777777777;",128,0,0,0
	.stabs	"long long unsigned int:t(0,9)=@s64;r(0,9);0;01777777777777777777777;",128,0,0,0
	.stabs	"short int:t(0,10)=@s16;r(0,10);-32768;32767;",128,0,0,0
	.stabs	"short unsigned int:t(0,11)=@s16;r(0,11);0;65535;",128,0,0,0
	.stabs	"signed char:t(0,12)=@s8;r(0,12);-128;127;",128,0,0,0
	.stabs	"unsigned char:t(0,13)=@s8;r(0,13);0;255;",128,0,0,0
	.stabs	"float:t(0,14)=r(0,1);4;0;",128,0,0,0
	.stabs	"double:t(0,15)=r(0,1);8;0;",128,0,0,0
	.stabs	"long double:t(0,16)=r(0,1);16;0;",128,0,0,0
	.stabs	"_Decimal32:t(0,17)=r(0,1);4;0;",128,0,0,0
	.stabs	"_Decimal64:t(0,18)=r(0,1);8;0;",128,0,0,0
	.stabs	"_Decimal128:t(0,19)=r(0,1);16;0;",128,0,0,0
	.stabs	"void:t(0,20)=(0,20)",128,0,0,0
	.stabs	"main:F(0,1)",36,0,3,main
	.stabs	"argc:p(0,3)",160,0,3,-8
	.globl	main
	.type	main, @function
main:
	.stabd	46,0,0
	.stabn	68,0,3,.LM0-.LFBB1
.LM0:
.LFBB1:
.LFB0:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR [rbp-8], rdi
	.stabn	68,0,4,.LM1-.LFBB1
.LM1:
	mov	edx, 3
	mov	esi, 2
	mov	edi, 1
	call	f
	.stabn	68,0,5,.LM2-.LFBB1
.LM2:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
.Lscope1:
	.stabs	"",36,0,0,.Lscope1-.LFBB1
	.stabd	78,0,0
	.stabs	"f:F(0,1)",36,0,7,f
	.stabs	"a:p(0,1)",160,0,7,-4
	.stabs	"b:p(0,1)",160,0,7,-8
	.stabs	"c:p(0,1)",160,0,7,-12
	.globl	f
	.type	f, @function
f:
	.stabd	46,0,0
	.stabn	68,0,7,.LM3-.LFBB2
.LM3:
.LFBB2:
.LFB1:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR [rbp-4], edi
	mov	DWORD PTR [rbp-8], esi
	mov	DWORD PTR [rbp-12], edx
	.stabn	68,0,8,.LM4-.LFBB2
.LM4:
	mov	eax, DWORD PTR [rbp-4]
	imul	eax, DWORD PTR [rbp-8]
	imul	eax, DWORD PTR [rbp-12]
	.stabn	68,0,9,.LM5-.LFBB2
.LM5:
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	f, .-f
.Lscope2:
	.stabs	"",36,0,0,.Lscope2-.LFBB2
	.stabd	78,0,0
	.stabs	"",100,0,0,.Letext0
.Letext0:
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
