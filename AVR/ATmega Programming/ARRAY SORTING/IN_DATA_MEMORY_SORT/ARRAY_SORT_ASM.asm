;
; ARRAY_SORT_2.asm
;
; Created: 4/6/2017 11:07:37 PM
; Author : Ali Gholami
;

;Register defs


		.equ  BLOCK1   =$60        ;start address of SRAM array #1
		.CSEG	; write to the program memory 
	ARRAY: .DB 1, 5, 4, 6, 2, 8, 7, 4, 9, 3	; The stored numbers in program memory
		.def flashsize = R16	; size for the elements block in the flash memory
		.def temp1 = R25
		.def bubble = R19
		.def looplo	= R18
		.def temp2	= R24
		.def spmcrval = R17
	/* Setup the stack */
    ldi r16, 0
    out SPH, r16
    ldi r16, 0xf0
    out SPL, r16

	/* Z pointer configuration (source in flash) */
	ldi ZH,high(ARRAY << 1)
	ldi ZL,low(ARRAY << 1)
	/* Y pointer configuration (destination in sram) */
	ldi YH,high(BLOCK1)
	ldi YL,low(BLOCK1)

	ldi flashsize,10
	ldi bubble,low(BLOCK1)

	rcall flash2ram

	/* X pointer configuration (destination in sram) */
	ldi XH,high(BLOCK1)
	ldi XL,low(BLOCK1)

	/* Sorting logic */
	/* define counters for inner and outer loops */
	ldi R20,9
OUTER_LOOP:
	ldi R21,9

INNER_LOOP:
	/* Load numbers into registers using Y pointer */
	ld R22,X+
	ld R23,X
	
	/* compare two numbers */
	cp R22,R23
	brlt SWAP_ROUTINE
HERE:
	dec R21
	brne INNER_LOOP

	dec R20
	mov XL,bubble
	//inc bubble
	brne OUTER_LOOP
	jmp ram2flash

		/* Copy the data to the ram */
flash2ram:
	lpm 
	st Y+,R0
	adiw Zl,1
	dec flashsize
	brne flash2ram
	ret

SWAP_ROUTINE:
	/* Change the content of R22 and R23 addresses */
	/* We have the address of R23 atm in Y */
	/* We have the address of R22 in the -Y pointer */
	/* We need to swap the contents of R22 and R23 */
	/* Swap */
	st X,R22	; Store the contents of R22 in R23's pointer place in SRAM
	st -X,R23	; Store the contents of R23 in R22's pointer place in SRAM
	inc XL
	jmp HERE

	/* Y pointer configuration (destination in sram) */
	ldi YH,high(BLOCK1)
	ldi YL,low(BLOCK1)
ram2flash:
	 .equ PAGESIZEB = 20	;PAGESIZEB is page size in BYTES, not words
.org SMALLBOOTSTART
write_page:
	;page erase
	ldi spmcrval, (1<<PGERS) + (1<<SPMEN)
	call do_spm
    ;transfer data from RAM to Flash page buffer
	ldi looplo, low(PAGESIZEB) ;init loop variable
	/* Y pointer configuration (destination in sram) */
	ldi YH,high(BLOCK1)
	ldi YL,low(BLOCK1)
	/* Z pointer configuration (source in flash) */
	ldi ZH,high(ARRAY << 1)
	ldi ZL,low(ARRAY << 1)
wrloop:
	ld r0, Y+
	ld r1, Y+
	ldi spmcrval, (1<<SPMEN)
	call do_spm
	adiw ZH:ZL, 2
	subi looplo, 2	;use subi for PAGESIZEB<=256
	brne wrloop

	;execute page write
	subi ZL, low(PAGESIZEB) ;restore pointer
	sbci ZH, high(PAGESIZEB) ;not required for PAGESIZEB<=256
	ldi spmcrval, (1<<PGWRT) + (1<<SPMEN)
	call do_spm

do_spm:
	 ;input: spmcrval determines SPM action
	 ;disable interrupts if enabled, store status
	in temp2, SREG
	cli
	;check for previous SPM complete
wait:
	in temp1, SPMCR
	sbrc temp1, SPMEN
	rjmp wait

	;SPM timed sequence
	out SPMCR, spmcrval
	spm
	;restore SREG (to enable interrupts if originally enabled)
	out SREG, temp2
	ret	
forever:
	rjmp forever




