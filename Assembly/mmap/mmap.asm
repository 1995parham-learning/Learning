; vim: ft=nasm
; In The Name of God
; =======================================
; [] File Name : mmap.asm
;
; [] Creation Date : 12-07-2018
;
; [] Created By : Parham Alvani <parham.alvani@gmail.com>
; =======================================
;

; These macro definitions are copied from linux sources
%define O_RDONLY 0
%define PROT_READ 0x1
%define MAP_PRIVATE 0x2

section .data
	fname: db 'test.txt', 0

section .text
global _start

print_string:
	push rdi
	call string_length
	; write to stdout
	pop rsi		; message
	mov rdx, rax	; message length
	mov rax, 1	; syscall number
	mov rdi, 1	; stdout
	syscall
	ret

string_length:
	xor rax, rax
.loop:
	cmp byte [rdi + rax], 0
	je .end
	inc rax
	jmp .loop
.end:
	ret

_start:
	; open test.txt
	mov rax, 2		; syscall number
	mov rdi, fname		; file name
	mov rsi, O_RDONLY	; open flags
	mov rdx, 0		; open modes
	syscall

	; mmap
	mov r8, rax		; rax holds opened file descriptor, it is the fourth argument of mmap
	mov rax, 9		; syscall number
	mov rdi, 0		; operating system will choose mapping destination
	mov rsi, 4096		; page size
	mov rdx, PROT_READ	; read only
	mov r10, MAP_PRIVATE	; private page
	mov r9, 0		; offset inside test.txt
	syscall

	mov rdi, rax
	call print_string

	; exit
	mov rax, 60
	xor rdi, rdi
	syscall
