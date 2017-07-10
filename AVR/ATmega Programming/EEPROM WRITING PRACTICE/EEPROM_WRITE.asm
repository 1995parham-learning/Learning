;
; EEPROM_WRITE_ASM.asm
;
; Created: 3/16/2017 11:17:58 PM
; Author : Ali Gholami
;


; Replace with your application code
start:
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
    .EXIT
	rjmp start

