; vim: ft=nasm
; In The Name of God
; =======================================
; [] File Name : loop_mapping.asm
;
; [] Creation Date : 07-07-2018
;
; [] Created By : Parham Alvani <parham.alvani@gmail.com>
; =======================================
;
section .data
	correct: dq -1

section .text
global _start
_start:
	jmp _start
