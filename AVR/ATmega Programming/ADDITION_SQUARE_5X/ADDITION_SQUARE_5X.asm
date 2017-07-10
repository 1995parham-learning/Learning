;
; ADDITION_SQUARE_5X.asm
;
; Created: 3/17/2017 8:50:57 PM
; Author : Ali Gholami
;
start:
	/* The number n must be stored in R10 according to the problem definition */ 
	ldi R25,25
	mov R10,R25
	/* Register R21 will be used as a immediate container */
	ldi R21,5
	/* Find the square of the number */ 
	/* R20 will start this procedure from 0 and will be added 5 more each time */
	ldi R20,0
adder_subroutine:
	/* Sqaure the R20 and put the result in R1:R0(mul does this by default) */
	mul R20,R20
	/* add the result to the R4:R3 (we need addition! not replacement :D) */
	add R3,R0
	adc R4,R1			
	/* Add immediate 5 to the R20 (because we need the sqaure of 5X numbers) */
	add R20,R21
	/* Check if we have reached the end of the loop */
	cp R20,R10
	brne adder_subroutine
	/* Final addition result is stored in R4:R3 */ 
	/* Put the result back to the R1:R0 */
	mov R1,R4
	mov R0,R3
	.EXIT
  rjmp start
