;
; ADC_PRAC.asm
;
; Created: 5/18/2017 1:05:30 AM
; Author : aligholamee
;

.include "m16_LCD_4bit.inc"
;======================DEF_SECTION=======================================
.def ADC_LOW_BYTE=R21
.def ADC_HIGH_BYTE=R22
.def VOLT_REF1_LOW=R23
.def VOLT_REF1_HIGH=R24
.def VOLT_REF2_LOW=R25
.def VOLT_REF2_HIGH=R26
.def COMPARISON_RESULT=R27
.def CNT1=R28
.def CNT2=R29
;======================DEF_SECTION=======================================

;======================INT_VECTOR========================================
.org 0x001c
	rjmp ADC_COMPLETE_ISR
;======================INT_VECTOR========================================

start:
;======================INITIALIZE========================================
INITIALIZE:
	ldi CNT1,0x00
	ldi R16,low(RAMEND)
	out SPL,R16
	ldi R16,high(RAMEND)
	out SPH,R16
	ldi R16,(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADATE)|(1<<ADIE)
	out ADCSRA,R16
	sei
	ldi R16,0x00
	out DDRB,R16
	ldi R16,0xff
	out DDRC,R16
	call REF2_ADC_ANALYZE
	call REF1_ADC_ANALYZE
	rjmp RE_COMPARE
;======================INITIALIZE========================================

;======================RE_COMPARE========================================
RE_COMPARE:
	call GENERAL_ADC_ANALYZE
	call COMPARE_REF_1
	cpi COMPARISON_RESULT,0x01
	breq LED_1_ON_MODE
	call COMPARE_REF_2
	cpi COMPARISON_RESULT,0x00
	breq LED_OFF_MODE
	cpi COMPARISON_RESULT,0x02
	breq LED_2_ON_MODE
LED_1_ON_MODE:
	ldi R16,0x01
	out portc,R16
	rjmp END_OF_ROUTINE
LED_2_ON_MODE:
	ldi R16,0x02
	out portc,R16
	rjmp END_OF_ROUTINE
LED_OFF_MODE:
	ldi R16,0x00
	out portc,R16
	rjmp END_OF_ROUTINE
COMPARE_REF_1:
	cp ADC_HIGH_BYTE,VOLT_REF1_HIGH
	brlo GENERALIZE_1
	cp ADC_LOW_BYTE,VOLT_REF1_LOW
	brlo GENERALIZE_1
	ldi  COMPARISON_RESULT,0x01
	ret
GENERALIZE_1:
	ldi COMPARISON_RESULT,0x00
	ret
COMPARE_REF_2:
	cp VOLT_REF2_HIGH,ADC_HIGH_BYTE
	brlo GENERALIZE_2
	cp VOLT_REF2_LOW,ADC_LOW_BYTE
	brlo GENERALIZE_2
	ldi  COMPARISON_RESULT,0x02
	ret
GENERALIZE_2:
	ldi COMPARISON_RESULT,0x00
	ret
END_OF_ROUTINE:
	inc CNT1
	cpi CNT1,0xff
	breq DISPLAY_ON_LCD
	rjmp RE_COMPARE
;======================RE_COMPARE========================================

;======================DISPLAY_ON_LCD====================================
DISPLAY_ON_LCD:
	call LCD_INIT
	call LCD_WAIT
	ldi CNT1,0x00
;======================DISPLAY_ON_LCD====================================

;======================INTEGER_CONVERSION================================
INTEGER_CONVERSION:
	cpi ADC_LOW_BYTE,0x0a
	brlo DISPLAY_ON_LCD10
	cpi ADC_LOW_BYTE,0x14
	brlo DISPLAY_ON_LCD20
	cpi ADC_LOW_BYTE,0x1e
	brlo DISPLAY_ON_LCD30
	cpi ADC_LOW_BYTE,0x28
	brlo DISPLAY_ON_LCD40
	cpi ADC_LOW_BYTE,0x32
	brlo DISPLAY_ON_LCD50
	cpi ADC_LOW_BYTE,0x3c
	brlo DISPLAY_ON_LCD60
	cpi ADC_LOW_BYTE,0x46
	brlo DISPLAY_ON_LCD70
	cpi ADC_LOW_BYTE,0x50
	brlo DISPLAY_ON_LCD80
	cpi ADC_LOW_BYTE,0x64
	brlo DISPLAY_ON_LCD90
;======================INTEGER_CONVERSION================================

END_OF_ROUTINE2:
	rjmp RE_COMPARE

;======================DISPLAY_ON_LCD====================================
DISPLAY_ON_LCD10:
	ldi argument,'1'
	call lcd_putchar
	ldi argument,'0'
	call lcd_putchar
	rjmp END_OF_ROUTINE2

DISPLAY_ON_LCD20:
	ldi argument,'2'
	call lcd_putchar
	ldi argument,'0'
	call lcd_putchar
	rjmp END_OF_ROUTINE2

DISPLAY_ON_LCD30:
	ldi argument,'3'
	call lcd_putchar
	ldi argument,'0'
	call lcd_putchar
	rjmp END_OF_ROUTINE2

DISPLAY_ON_LCD40:
	ldi argument,'4'
	call lcd_putchar
	ldi argument,'0'
	call lcd_putchar
	rjmp END_OF_ROUTINE2

DISPLAY_ON_LCD50:
	ldi argument,'5'
	call lcd_putchar
	ldi argument,'0'
	call lcd_putchar
	rjmp END_OF_ROUTINE2

DISPLAY_ON_LCD60:
	ldi argument,'6'
	call lcd_putchar
	ldi argument,'0'
	call lcd_putchar
	rjmp END_OF_ROUTINE2

DISPLAY_ON_LCD70:
	ldi argument,'7'
	call lcd_putchar
	ldi argument,'0'
	call lcd_putchar
	rjmp END_OF_ROUTINE2

DISPLAY_ON_LCD80:
	ldi argument,'8'
	call lcd_putchar
	ldi argument,'0'
	call lcd_putchar
	rjmp END_OF_ROUTINE2

DISPLAY_ON_LCD90:
	ldi argument,'9'
	call lcd_putchar
	ldi argument,'0'
	call lcd_putchar
	rjmp END_OF_ROUTINE2
;======================DISPLAY_ON_LCD====================================

;======================WAIT HERE==========================================
WAIT_HERE:
	ldi R16,(1<<ADSC)
	in R17,ADCSRA;ADSC
	and R16,R17
	cpi R16,(1<<ADSC)
	breq WAIT_HERE
	ret
;======================WAIT HERE=========================================


;================MAIN SENSOR ADC CONVERSION + SLEEP MODE HERE============
GENERAL_ADC_ANALYZE:
	ldi R16,0x00
    out ADMUX,R16
	in R16,ADCSRA
	ori R16,(1<<ADSC)
	out ADCSRA,R16
	in R16,MCUCR
	ori R16,(1<<SE)|(1<<SM0)|(0<<SM1)|(0<<SM2)
	out MCUCR,R16
	sleep
;================MAIN SENSOR ADC CONVERSION + SLEEP MODE HERE============

;======================RETURN HERE=========================================
RETURN_HERE:
		in ADC_LOW_BYTE,ADCL
		in ADC_HIGH_BYTE,ADCH
		ret
;======================RETURN HERE=========================================

;======================REF1_ADC_ANALYZE====================================
REF1_ADC_ANALYZE:
	ldi R16,0x01
    out ADMUX,R16
	in R16,ADCSRA
	ori R16,(1<<ADSC)
	out ADCSRA,R16
	call WAIT_HERE
	in VOLT_REF1_LOW,ADCL
	in VOLT_REF1_HIGH,ADCH
	out portc,VOLT_REF1_LOW
	ret
;======================REF1_ADC_ANALYZE====================================

;======================REF2_ADC_ANALYZE====================================
REF2_ADC_ANALYZE:
	ldi R16,0x02
    out ADMUX,R16
	in R16,ADCSRA
	ori R16,(1<<ADSC)
	out ADCSRA,R16
	call WAIT_HERE
	in VOLT_REF2_LOW,ADCL
	in VOLT_REF2_HIGH,ADCH
	ret
;======================REF2_ADC_ANALYZE====================================

;======================ADC Conversion Complete ISR=========================
ADC_COMPLETE_ISR:
	ldi R16,(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADATE)|(1<<ADIE)
	out ADCSRA,R16
	sei
	rjmp RETURN_HERE
;======================ADC Conversion Complete ISR=========================