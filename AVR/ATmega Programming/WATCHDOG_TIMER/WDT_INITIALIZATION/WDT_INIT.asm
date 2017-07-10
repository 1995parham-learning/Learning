;
; WDT_INIT.asm
;
; Created: 4/2/2017 9:01:52 AM
; Author : Ali Gholami
;
; A program to initialize the watchdog timer and configure it for a 2.1 second reset timer.
; This program will cause the WDT to be reseted after 2.1 if we dont reset it manualy.

; Replace with your application code
start:
    ; WDP2, WDP1, WDP0 must be confgure in order to use the 2.1 s timeout in wdt prescaling
	; those bits are in WDTCR
	; to use 2.1(s) timeout we need to put WDP2..WDP0 to "111" according to the data sheet
	
	/* Prepare the number that must be written in WDTCR */
	ldi R20,0x0F	; Write 0b00011111 in R20

	/* 5TH 1 is for the WDTOE - has to be enabled in order to use wdt */
	/* 4TH 1 is for the WDE(Watchdog Enable) */
	/* First three 1s are for the 2.1s config */
	/* Put the result in the WDTCR */
	out WDTCR,R20

	/* Now we have the initialized WDT for a 2.1(s) delay */
    rjmp start
