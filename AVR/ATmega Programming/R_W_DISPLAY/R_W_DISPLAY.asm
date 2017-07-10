;
; R_W_DISPLAY.asm
;
; Created: 3/22/2017 11:05:18 PM
; Author : Ali Gholami
;
start:
	/* Stack Setup */ 
    ldi r16, 0
    out SPH, r16
    ldi r16, 0xf0
    out SPL, r16

	/***********************************/
		/*  EEPROM WRITE  */

	/* Define a counter in R16 */
	ldi R16,9
	/* EEPROM Address to be written */
	ldi R18,0x00
	ldi R19,0x00
	/* Loop through this untill 9 numbers are written */
EEPROM_WRITE:
    /* Wait untill the EEWE gets 0 */
	/* Skip next instruction if EEWE is clear in EECR */
	sbic EECR,EEWE
	rjmp EEPROM_WRITE	
	/* Write the address to be filled with the number :D */
	out EEARL,R18
	out EEARH,R19	
	/* Write the data */
	/* Counter can be used itself */
	out EEDR,R16
	/* Write logical one to the EEMWE */
	sbi EECR,EEMWE
	/* Start write */
	sbi EECR,EEWE
	/* dec the counter */
	dec R16
	/* Go to the next address on EEPROM */
	inc R18
	/* Check the loop end point */
	brne EEPROM_WRITE
	/**************************/


	/**************************/
	/* Store Conversion Numbers in Program Memory */

	/* Connect the PORT B to the 7-Segment */
	/* This part must be done in the proteus simulator */

	/* Put the direction of port B to output */
	/* to do this we use DDR(Data Direction Register) and turn all ports to 1 */
	ldi R16,(1 << PB0)|(1 << PB1)|(1 << PB2)|(1 << PB3)|(1 << PB4)|(1 << PB5)|(1 << PB6)|(1 << PB7) ; Load 0b11111111 in R16
    out DDRB,R16	; Configure the PORT B as output 

	/* To reserve some place for the 7Segment encoding table in the memory
	* we need to use .db directive :)
	* The DB directive reserves memory resources in the program memory or the EEPROM memory.
	* In order to be able to refer to the reserved locations, the DB directive should be preceded by a label. 
	* The DB directive takes a list of expressions,
	* and must contain at least one expression. The DB directive must be placed in a Code Segment or an EEPROM Segment. */
	.CSEG	; write to the program memory 
	BCDTo7_Seg: .DB 0xCF, 0xA4, 0xB0, 0x00, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x00	; The size of reserved memory using .db directive must be even number	
	/*****************************/


	/*****************************/
	/* Read & Display */

	/* Start the reading loop */
	/* Just reload R16 with 0 and R17 with 9 */
	ldi R17,9
	/* INITIALIZE Z POINTER */
	ldi ZH,high(BCDTo7_Seg << 1)
	ldi ZL,low(BCDTo7_Seg << 1)
R_W:
	/* Wait for completion of write procedure */
	sbic EECR,EEWE
	rjmp R_W
	/* Set up the reading address */
	ldi R18,0
	ldi R19,0
	out EEARH,R19
	out EEARH,R18
	/* set bit EERE in EECR */
	sbi EECR,EERE
	/* Read data from data register */
	in R20,EEDR

	/* The data is in the R20 Register */ 
	/* Simply start reading from program memory */
	/* The reading from program memory must be done with the starting address: BCDTo7_Seg LABEL */
	/* we can access the other stored data by simply adding the value of R20 each time to the address of BCDTo7_Seg value */
	clr R23
	/* R23 contains the data must be written to the 7 segment */
	lpm R23,Z+

	/* Display R23 Value on the 7-Segment */
	/* Port B is set to the output before */ 
	/* Send the result to the port B */
	out PORTB,R23
	/* Call the delay function */
	call LONG_DELAY
	/* decrement R16 */
	dec R16
	/* Check the loop end point */
	brne R_W
	rjmp start

	    /* Delay function */
LONG_DELAY:
    ldi r25,10
LOOP:
    dec R25
    brne LOOP
    ret

