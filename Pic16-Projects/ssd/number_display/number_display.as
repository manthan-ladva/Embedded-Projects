opt subtitle "HI-TECH Software Omniscient Code Generator (Lite mode) build 5239"

opt pagewidth 120

	opt lm

	processor	16F876A
clrc	macro
	bcf	3,0
	endm
clrz	macro
	bcf	3,2
	endm
setc	macro
	bsf	3,0
	endm
setz	macro
	bsf	3,2
	endm
skipc	macro
	btfss	3,0
	endm
skipz	macro
	btfss	3,2
	endm
skipnc	macro
	btfsc	3,0
	endm
skipnz	macro
	btfsc	3,2
	endm
indf	equ	0
indf0	equ	0
pc	equ	2
pcl	equ	2
status	equ	3
fsr	equ	4
fsr0	equ	4
c	equ	1
z	equ	0
pclath	equ	10
;COMMON:	_main->_display_ssd
;COMMON:	_display_ssd->_ssd_switch
;BANK0:	_main->_display_ssd
;COMMON:	_display_ssd->_ssd_switch
	FNCALL	_main,_tris
	FNCALL	_main,_display_ssd
	FNCALL	_display_ssd,_ssd_switch
	FNCALL	_display_ssd,_delay
	FNROOT	_main
	global	_numbers
psect	idataBANK0,class=CODE,space=0,delta=2
global __pidataBANK0
__pidataBANK0:
	file	"C:\Users\Prolific\Desktop\Manthan Ladva\Pic16-Projects\ssd\number_display\number_display.c"
	line	8

;initializer for _numbers
	retlw	0FCh
	retlw	0

	retlw	060h
	retlw	0

	retlw	0DAh
	retlw	0

	retlw	0F2h
	retlw	0

	retlw	066h
	retlw	0

	retlw	0B6h
	retlw	0

	retlw	0BEh
	retlw	0

	retlw	0E0h
	retlw	0

	retlw	0FEh
	retlw	0

	retlw	0F6h
	retlw	0

	global	_ADCON0
_ADCON0  equ     31
	global	_ADRESH
_ADRESH  equ     30
	global	_CCP1CON
_CCP1CON  equ     23
	global	_CCP2CON
_CCP2CON  equ     29
	global	_CCPR1H
_CCPR1H  equ     22
	global	_CCPR1L
_CCPR1L  equ     21
	global	_CCPR2H
_CCPR2H  equ     28
	global	_CCPR2L
_CCPR2L  equ     27
	global	_FSR
_FSR  equ     4
	global	_INDF
_INDF  equ     0
	global	_INTCON
_INTCON  equ     11
	global	_PCL
_PCL  equ     2
	global	_PCLATH
_PCLATH  equ     10
	global	_PIR1
_PIR1  equ     12
	global	_PIR2
_PIR2  equ     13
	global	_PORTA
_PORTA  equ     5
	global	_PORTB
_PORTB  equ     6
	global	_PORTC
_PORTC  equ     7
	global	_RCREG
_RCREG  equ     26
	global	_RCSTA
_RCSTA  equ     24
	global	_SSPBUF
_SSPBUF  equ     19
	global	_SSPCON
_SSPCON  equ     20
	global	_STATUS
_STATUS  equ     3
	global	_T1CON
_T1CON  equ     16
	global	_T2CON
_T2CON  equ     18
	global	_TMR0
_TMR0  equ     1
	global	_TMR1H
_TMR1H  equ     15
	global	_TMR1L
_TMR1L  equ     14
	global	_TMR2
_TMR2  equ     17
	global	_TXREG
_TXREG  equ     25
	global	_ADCS0
_ADCS0  equ     254
	global	_ADCS1
_ADCS1  equ     255
	global	_ADDEN
_ADDEN  equ     195
	global	_ADGO
_ADGO  equ     250
	global	_ADIF
_ADIF  equ     102
	global	_ADON
_ADON  equ     248
	global	_BCLIF
_BCLIF  equ     107
	global	_CARRY
_CARRY  equ     24
	global	_CCP1IF
_CCP1IF  equ     98
	global	_CCP1M0
_CCP1M0  equ     184
	global	_CCP1M1
_CCP1M1  equ     185
	global	_CCP1M2
_CCP1M2  equ     186
	global	_CCP1M3
_CCP1M3  equ     187
	global	_CCP1X
_CCP1X  equ     189
	global	_CCP1Y
_CCP1Y  equ     188
	global	_CCP2IF
_CCP2IF  equ     104
	global	_CCP2M0
_CCP2M0  equ     232
	global	_CCP2M1
_CCP2M1  equ     233
	global	_CCP2M2
_CCP2M2  equ     234
	global	_CCP2M3
_CCP2M3  equ     235
	global	_CCP2X
_CCP2X  equ     237
	global	_CCP2Y
_CCP2Y  equ     236
	global	_CHS0
_CHS0  equ     251
	global	_CHS1
_CHS1  equ     252
	global	_CHS2
_CHS2  equ     253
	global	_CKP
_CKP  equ     164
	global	_CMIF
_CMIF  equ     110
	global	_CREN
_CREN  equ     196
	global	_DC
_DC  equ     25
	global	_EEIF
_EEIF  equ     108
	global	_FERR
_FERR  equ     194
	global	_GIE
_GIE  equ     95
	global	_GODONE
_GODONE  equ     250
	global	_INTE
_INTE  equ     92
	global	_INTF
_INTF  equ     89
	global	_IRP
_IRP  equ     31
	global	_OERR
_OERR  equ     193
	global	_PD
_PD  equ     27
	global	_PEIE
_PEIE  equ     94
	global	_RA0
_RA0  equ     40
	global	_RA1
_RA1  equ     41
	global	_RA2
_RA2  equ     42
	global	_RA3
_RA3  equ     43
	global	_RA4
_RA4  equ     44
	global	_RA5
_RA5  equ     45
	global	_RB0
_RB0  equ     48
	global	_RB1
_RB1  equ     49
	global	_RB2
_RB2  equ     50
	global	_RB3
_RB3  equ     51
	global	_RB4
_RB4  equ     52
	global	_RB5
_RB5  equ     53
	global	_RB6
_RB6  equ     54
	global	_RB7
_RB7  equ     55
	global	_RBIE
_RBIE  equ     91
	global	_RBIF
_RBIF  equ     88
	global	_RC0
_RC0  equ     56
	global	_RC1
_RC1  equ     57
	global	_RC2
_RC2  equ     58
	global	_RC3
_RC3  equ     59
	global	_RC4
_RC4  equ     60
	global	_RC5
_RC5  equ     61
	global	_RC6
_RC6  equ     62
	global	_RC7
_RC7  equ     63
	global	_RCIF
_RCIF  equ     101
	global	_RP0
_RP0  equ     29
	global	_RP1
_RP1  equ     30
	global	_RX9
_RX9  equ     198
	global	_RX9D
_RX9D  equ     192
	global	_SPEN
_SPEN  equ     199
	global	_SREN
_SREN  equ     197
	global	_SSPEN
_SSPEN  equ     165
	global	_SSPIF
_SSPIF  equ     99
	global	_SSPM0
_SSPM0  equ     160
	global	_SSPM1
_SSPM1  equ     161
	global	_SSPM2
_SSPM2  equ     162
	global	_SSPM3
_SSPM3  equ     163
	global	_SSPOV
_SSPOV  equ     166
	global	_T0IE
_T0IE  equ     93
	global	_T0IF
_T0IF  equ     90
	global	_T1CKPS0
_T1CKPS0  equ     132
	global	_T1CKPS1
_T1CKPS1  equ     133
	global	_T1OSCEN
_T1OSCEN  equ     131
	global	_T1SYNC
_T1SYNC  equ     130
	global	_T2CKPS0
_T2CKPS0  equ     144
	global	_T2CKPS1
_T2CKPS1  equ     145
	global	_TMR0IE
_TMR0IE  equ     93
	global	_TMR0IF
_TMR0IF  equ     90
	global	_TMR1CS
_TMR1CS  equ     129
	global	_TMR1IF
_TMR1IF  equ     96
	global	_TMR1ON
_TMR1ON  equ     128
	global	_TMR2IF
_TMR2IF  equ     97
	global	_TMR2ON
_TMR2ON  equ     146
	global	_TO
_TO  equ     28
	global	_TOUTPS0
_TOUTPS0  equ     147
	global	_TOUTPS1
_TOUTPS1  equ     148
	global	_TOUTPS2
_TOUTPS2  equ     149
	global	_TOUTPS3
_TOUTPS3  equ     150
	global	_TXIF
_TXIF  equ     100
	global	_WCOL
_WCOL  equ     167
	global	_ZERO
_ZERO  equ     26
	global	_ADCON1
_ADCON1  equ     159
	global	_ADRESL
_ADRESL  equ     158
	global	_CMCON
_CMCON  equ     156
	global	_CVRCON
_CVRCON  equ     157
	global	_OPTION
_OPTION  equ     129
	global	_PCON
_PCON  equ     142
	global	_PIE1
_PIE1  equ     140
	global	_PIE2
_PIE2  equ     141
	global	_PR2
_PR2  equ     146
	global	_SPBRG
_SPBRG  equ     153
	global	_SSPADD
_SSPADD  equ     147
	global	_SSPCON2
_SSPCON2  equ     145
	global	_SSPSTAT
_SSPSTAT  equ     148
	global	_TRISA
_TRISA  equ     133
	global	_TRISB
_TRISB  equ     134
	global	_TRISC
_TRISC  equ     135
	global	_TXSTA
_TXSTA  equ     152
	global	_ACKDT
_ACKDT  equ     1165
	global	_ACKEN
_ACKEN  equ     1164
	global	_ACKSTAT
_ACKSTAT  equ     1166
	global	_ADCS2
_ADCS2  equ     1278
	global	_ADFM
_ADFM  equ     1279
	global	_ADIE
_ADIE  equ     1126
	global	_BCLIE
_BCLIE  equ     1131
	global	_BF
_BF  equ     1184
	global	_BOR
_BOR  equ     1136
	global	_BRGH
_BRGH  equ     1218
	global	_C1INV
_C1INV  equ     1252
	global	_C1OUT
_C1OUT  equ     1254
	global	_C2INV
_C2INV  equ     1253
	global	_C2OUT
_C2OUT  equ     1255
	global	_CCP1IE
_CCP1IE  equ     1122
	global	_CCP2IE
_CCP2IE  equ     1128
	global	_CIS
_CIS  equ     1251
	global	_CKE
_CKE  equ     1190
	global	_CM0
_CM0  equ     1248
	global	_CM1
_CM1  equ     1249
	global	_CM2
_CM2  equ     1250
	global	_CMIE
_CMIE  equ     1134
	global	_CSRC
_CSRC  equ     1223
	global	_CVR0
_CVR0  equ     1256
	global	_CVR1
_CVR1  equ     1257
	global	_CVR2
_CVR2  equ     1258
	global	_CVR3
_CVR3  equ     1259
	global	_CVREN
_CVREN  equ     1263
	global	_CVROE
_CVROE  equ     1262
	global	_CVRR
_CVRR  equ     1261
	global	_DA
_DA  equ     1189
	global	_EEIE
_EEIE  equ     1132
	global	_GCEN
_GCEN  equ     1167
	global	_INTEDG
_INTEDG  equ     1038
	global	_PCFG0
_PCFG0  equ     1272
	global	_PCFG1
_PCFG1  equ     1273
	global	_PCFG2
_PCFG2  equ     1274
	global	_PCFG3
_PCFG3  equ     1275
	global	_PEN
_PEN  equ     1162
	global	_POR
_POR  equ     1137
	global	_PS0
_PS0  equ     1032
	global	_PS1
_PS1  equ     1033
	global	_PS2
_PS2  equ     1034
	global	_PSA
_PSA  equ     1035
	global	_RBPU
_RBPU  equ     1039
	global	_RCEN
_RCEN  equ     1163
	global	_RCIE
_RCIE  equ     1125
	global	_RSEN
_RSEN  equ     1161
	global	_RW
_RW  equ     1186
	global	_SEN
_SEN  equ     1160
	global	_SMP
_SMP  equ     1191
	global	_SSPIE
_SSPIE  equ     1123
	global	_START
_START  equ     1187
	global	_STOP
_STOP  equ     1188
	global	_SYNC
_SYNC  equ     1220
	global	_T0CS
_T0CS  equ     1037
	global	_T0SE
_T0SE  equ     1036
	global	_TMR1IE
_TMR1IE  equ     1120
	global	_TMR2IE
_TMR2IE  equ     1121
	global	_TRISA0
_TRISA0  equ     1064
	global	_TRISA1
_TRISA1  equ     1065
	global	_TRISA2
_TRISA2  equ     1066
	global	_TRISA3
_TRISA3  equ     1067
	global	_TRISA4
_TRISA4  equ     1068
	global	_TRISA5
_TRISA5  equ     1069
	global	_TRISB0
_TRISB0  equ     1072
	global	_TRISB1
_TRISB1  equ     1073
	global	_TRISB2
_TRISB2  equ     1074
	global	_TRISB3
_TRISB3  equ     1075
	global	_TRISB4
_TRISB4  equ     1076
	global	_TRISB5
_TRISB5  equ     1077
	global	_TRISB6
_TRISB6  equ     1078
	global	_TRISB7
_TRISB7  equ     1079
	global	_TRISC0
_TRISC0  equ     1080
	global	_TRISC1
_TRISC1  equ     1081
	global	_TRISC2
_TRISC2  equ     1082
	global	_TRISC3
_TRISC3  equ     1083
	global	_TRISC4
_TRISC4  equ     1084
	global	_TRISC5
_TRISC5  equ     1085
	global	_TRISC6
_TRISC6  equ     1086
	global	_TRISC7
_TRISC7  equ     1087
	global	_TRMT
_TRMT  equ     1217
	global	_TX9
_TX9  equ     1222
	global	_TX9D
_TX9D  equ     1216
	global	_TXEN
_TXEN  equ     1221
	global	_TXIE
_TXIE  equ     1124
	global	_UA
_UA  equ     1185
	global	_EEADR
_EEADR  equ     269
	global	_EEADRH
_EEADRH  equ     271
	global	_EEADRL
_EEADRL  equ     269
	global	_EEDATA
_EEDATA  equ     268
	global	_EEDATH
_EEDATH  equ     270
	global	_EECON1
_EECON1  equ     396
	global	_EECON2
_EECON2  equ     397
	global	_EEPGD
_EEPGD  equ     3175
	global	_RD
_RD  equ     3168
	global	_WR
_WR  equ     3169
	global	_WREN
_WREN  equ     3170
	global	_WRERR
_WRERR  equ     3171
	file	"number_display.as"
	line	#
psect cinit,class=CODE,delta=2
global start_initialization
start_initialization:

psect	dataBANK0,class=BANK0,space=1
global __pdataBANK0
__pdataBANK0:
	file	"C:\Users\Prolific\Desktop\Manthan Ladva\Pic16-Projects\ssd\number_display\number_display.c"
	line	8
_numbers:
       ds      20

global btemp
psect inittext,class=CODE,delta=2
global init_fetch,btemp
;	Called with low address in FSR and high address in W
init_fetch:
	movf btemp,w
	movwf pclath
	movf btemp+1,w
	movwf pc
global init_ram
;Called with:
;	high address of idata address in btemp 
;	low address of idata address in btemp+1 
;	low address of data in FSR
;	high address + 1 of data in btemp-1
init_ram:
	fcall init_fetch
	movwf indf,f
	incf fsr,f
	movf fsr,w
	xorwf btemp-1,w
	btfsc status,2
	retlw 0
	incf btemp+1,f
	btfsc status,2
	incf btemp,f
	goto init_ram
; Initialize objects allocated to BANK0
psect cinit,class=CODE,delta=2
global init_ram, __pidataBANK0
	bcf	status, 7	;select IRP bank0
	movlw low(__pdataBANK0+20)
	movwf btemp-1,f
	movlw high(__pidataBANK0)
	movwf btemp,f
	movlw low(__pidataBANK0)
	movwf btemp+1,f
	movlw low(__pdataBANK0)
	movwf fsr,f
	fcall init_ram
psect cinit,class=CODE,delta=2
global end_of_initialization

;End of C runtime variable initationation code

end_of_initialization:
clrf status
ljmp _main	;jump to C main() function
psect	cstackCOMMON,class=COMMON,space=1
global __pcstackCOMMON
__pcstackCOMMON:
	global	?_tris
?_tris: ;@ 0x0
	global	??_delay
??_delay: ;@ 0x0
	global	?_ssd_switch
?_ssd_switch: ;@ 0x0
	global	??_ssd_switch
??_ssd_switch: ;@ 0x0
	global	??_tris
??_tris: ;@ 0x0
	global	delay@i
delay@i:	; 2 bytes @ 0x0
	global	ssd_switch@a
ssd_switch@a:	; 2 bytes @ 0x0
	ds	1
	global	??_main
??_main: ;@ 0x1
	ds	1
	global	ssd_switch@b
ssd_switch@b:	; 2 bytes @ 0x2
	global	delay@j
delay@j:	; 2 bytes @ 0x2
	ds	2
	global	?_delay
?_delay: ;@ 0x4
	global	ssd_switch@c
ssd_switch@c:	; 2 bytes @ 0x4
	global	delay@time
delay@time:	; 2 bytes @ 0x4
	ds	2
	global	ssd_switch@d
ssd_switch@d:	; 2 bytes @ 0x6
	ds	2
	global	??_display_ssd
??_display_ssd: ;@ 0x8
	ds	1
	global	?_main
?_main: ;@ 0x9
psect	cstackBANK0,class=BANK0,space=1
global __pcstackBANK0
__pcstackBANK0:
	global	?_display_ssd
?_display_ssd: ;@ 0x0
	global	display_ssd@a
display_ssd@a:	; 2 bytes @ 0x0
	ds	2
	global	display_ssd@b
display_ssd@b:	; 2 bytes @ 0x2
	ds	2
	global	display_ssd@c
display_ssd@c:	; 2 bytes @ 0x4
	ds	2
	global	display_ssd@d
display_ssd@d:	; 2 bytes @ 0x6
	ds	2
;Data sizes: Strings 0, constant 0, data 20, bss 0, persistent 0 stack 0
;Auto spaces:   Size  Autos    Used
; COMMON          14      9       9
; BANK0           80      8      28
; BANK1           80      0       0
; BANK3           96      0       0
; BANK2           96      0       0


;Pointer list with targets:



;Main: autosize = 0, tempsize = 0, incstack = 0, save=0


;Call graph:                      Base Space Used Autos Args Refs Density
;_main                                                0    0  196   0.00
;               _tris
;        _display_ssd
;  _display_ssd                                       1    8  196   0.00
;                                    8 COMMO    1
;                                    0 BANK0    8
;         _ssd_switch
;              _delay
;  _tris                                              0    0    0   0.00
;    _delay                                           4    2   68   0.00
;                                    0 COMMO    6
;    _ssd_switch                                      0    8   64   0.00
;                                    0 COMMO    8
; Estimated maximum call depth 2
; Address spaces:

;Name               Size   Autos  Total    Cost      Usage
;BITCOMMON            E      0       0       0        0.0%
;CODE                 0      0       0       0        0.0%
;NULL                 0      0       0       0        0.0%
;COMMON               E      9       9       1       64.3%
;SFR0                 0      0       0       1        0.0%
;BITSFR0              0      0       0       1        0.0%
;BITSFR1              0      0       0       2        0.0%
;SFR1                 0      0       0       2        0.0%
;ABS                  0      0      25       2        0.0%
;STACK                0      0       0       3        0.0%
;BITBANK0            50      0       0       4        0.0%
;SFR3                 0      0       0       4        0.0%
;BITSFR3              0      0       0       4        0.0%
;BANK0               50      8      1C       5       35.0%
;BITSFR2              0      0       0       5        0.0%
;SFR2                 0      0       0       5        0.0%
;BITBANK1            50      0       0       6        0.0%
;BANK1               50      0       0       7        0.0%
;BITBANK3            60      0       0       8        0.0%
;BANK3               60      0       0       9        0.0%
;BITBANK2            60      0       0      10        0.0%
;BANK2               60      0       0      11        0.0%
;DATA                 0      0      25      12        0.0%
;EEDATA             100      0       0    1000        0.0%

	global	_main
psect	maintext,local,class=CODE,delta=2
global __pmaintext
__pmaintext:

; *************** function _main *****************
; Defined at:
;		line 16 in file "C:\Users\Prolific\Desktop\Manthan Ladva\Pic16-Projects\ssd\number_display\number_display.c"
; Parameters:    Size  Location     Type
;		None
; Auto vars:     Size  Location     Type
;		None
; Return value:  Size  Location     Type
;		None               void
; Registers used:
;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
; Tracked objects:
;		On entry : 17F/0
;		On exit  : 0/0
;		Unchanged: 0/0
; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;      Locals:         0       0       0       0       0
;      Temp:     0
;      Total:    0
; This function calls:
;		_tris
;		_display_ssd
; This function is called by:
;		Startup code after reset
; This function uses a non-reentrant model
; 
psect	maintext
	file	"C:\Users\Prolific\Desktop\Manthan Ladva\Pic16-Projects\ssd\number_display\number_display.c"
	line	16
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
;pic168xa.h: 19: volatile unsigned char INDF @ 0x00;
;pic168xa.h: 20: volatile unsigned char TMR0 @ 0x01;
;pic168xa.h: 21: volatile unsigned char PCL @ 0x02;
;pic168xa.h: 22: volatile unsigned char STATUS @ 0x03;
;pic168xa.h: 23: unsigned char FSR @ 0x04;
;pic168xa.h: 24: volatile unsigned char PORTA @ 0x05;
;pic168xa.h: 25: volatile unsigned char PORTB @ 0x06;
;pic168xa.h: 26: volatile unsigned char PORTC @ 0x07;
;pic168xa.h: 31: unsigned char PCLATH @ 0x0A;
;pic168xa.h: 32: volatile unsigned char INTCON @ 0x0B;
	
_main:	
	opt stack 8
; Regs used in _main: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	17
	
l30000381:	
;number_display.c: 17: tris();
	fcall	_tris
	
l30000382:	
	line	18
	movlw	low(01h)
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	0+(?_display_ssd)+02h
	movlw	high(01h)
	movwf	(0+(?_display_ssd)+02h)+1
	movlw	low(09h)
	movwf	(?_display_ssd)
	movlw	high(09h)
	movwf	((?_display_ssd))+1
	movlw	low(0)
	movwf	0+(?_display_ssd)+06h
	movlw	high(0)
	movwf	(0+(?_display_ssd)+06h)+1
	movlw	low(08h)
	movwf	0+(?_display_ssd)+04h
	movlw	high(08h)
	movwf	(0+(?_display_ssd)+04h)+1
	fcall	_display_ssd
	goto	l30000382
	global	start
	ljmp	start
	opt stack 0
GLOBAL	__end_of_main
	__end_of_main:
; =============== function _main ends ============

psect	maintext
	line	19
	signat	_main,88
	global	_display_ssd
psect	text25,local,class=CODE,delta=2
global __ptext25
__ptext25:

; *************** function _display_ssd *****************
; Defined at:
;		line 21 in file "C:\Users\Prolific\Desktop\Manthan Ladva\Pic16-Projects\ssd\number_display\number_display.c"
; Parameters:    Size  Location     Type
;  a               2    0[BANK0 ] unsigned int 
;  b               2    2[BANK0 ] unsigned int 
;  c               2    4[BANK0 ] unsigned int 
;  d               2    6[BANK0 ] unsigned int 
; Auto vars:     Size  Location     Type
;		None
; Return value:  Size  Location     Type
;		None               void
; Registers used:
;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
; Tracked objects:
;		On entry : 0/0
;		On exit  : 0/0
;		Unchanged: 0/0
; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;      Locals:         1       8       0       0       0
;      Temp:     1
;      Total:    9
; This function calls:
;		_ssd_switch
;		_delay
; This function is called by:
;		_main
; This function uses a non-reentrant model
; 
psect	text25
	file	"C:\Users\Prolific\Desktop\Manthan Ladva\Pic16-Projects\ssd\number_display\number_display.c"
	line	21
	global	__size_of_display_ssd
	__size_of_display_ssd	equ	__end_of_display_ssd-_display_ssd
;number_display.c: 21: void display_ssd(unsigned int a, unsigned int b, unsigned int c, unsigned int d){
	
_display_ssd:	
	opt stack 7
; Regs used in _display_ssd: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	22
	
l30000367:	
;number_display.c: 22: ssd_switch(1,1,1,0);
	movlw	low(01h)
	movwf	0+(?_ssd_switch)+02h
	movlw	high(01h)
	movwf	(0+(?_ssd_switch)+02h)+1
	movlw	low(01h)
	movwf	(?_ssd_switch)
	movlw	high(01h)
	movwf	((?_ssd_switch))+1
	movlw	low(0)
	movwf	0+(?_ssd_switch)+06h
	movlw	high(0)
	movwf	(0+(?_ssd_switch)+06h)+1
	movlw	low(01h)
	movwf	0+(?_ssd_switch)+04h
	movlw	high(01h)
	movwf	(0+(?_ssd_switch)+04h)+1
	fcall	_ssd_switch
	
l30000368:	
	line	23
;number_display.c: 23: PORTB = numbers[a];
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movf	(display_ssd@a),w
	movwf	(??_display_ssd+0+0)
	addwf	(??_display_ssd+0+0),w
	addlw	(_numbers)&0ffh
	movwf	fsr0
	bcf	status, 7	;select IRP bank0
	movf	indf,w
	movwf	(6)	;volatile
	
l30000369:	
	line	24
;number_display.c: 24: delay(1);
	movlw	low(01h)
	movwf	(?_delay)
	movlw	high(01h)
	movwf	((?_delay))+1
	fcall	_delay
	
l30000370:	
	line	25
;number_display.c: 25: PORTB = 0x00;
	clrc
	movlw	0
	btfsc	status,0
	movlw	1
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(6)	;volatile
	
l30000371:	
	line	27
;number_display.c: 27: ssd_switch(1,1,0,1);
	movlw	low(01h)
	movwf	0+(?_ssd_switch)+02h
	movlw	high(01h)
	movwf	(0+(?_ssd_switch)+02h)+1
	movlw	low(01h)
	movwf	(?_ssd_switch)
	movlw	high(01h)
	movwf	((?_ssd_switch))+1
	movlw	low(01h)
	movwf	0+(?_ssd_switch)+06h
	movlw	high(01h)
	movwf	(0+(?_ssd_switch)+06h)+1
	movlw	low(0)
	movwf	0+(?_ssd_switch)+04h
	movlw	high(0)
	movwf	(0+(?_ssd_switch)+04h)+1
	fcall	_ssd_switch
	
l30000372:	
	line	28
;number_display.c: 28: PORTB = numbers[b];
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movf	(display_ssd@b),w
	movwf	(??_display_ssd+0+0)
	addwf	(??_display_ssd+0+0),w
	addlw	(_numbers)&0ffh
	movwf	fsr0
	bcf	status, 7	;select IRP bank0
	movf	indf,w
	movwf	(6)	;volatile
	
l30000373:	
	line	29
;number_display.c: 29: delay(1);
	movlw	low(01h)
	movwf	(?_delay)
	movlw	high(01h)
	movwf	((?_delay))+1
	fcall	_delay
	line	30
;number_display.c: 30: PORTB = 0x00;
	clrc
	movlw	0
	btfsc	status,0
	movlw	1
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(6)	;volatile
	
l30000374:	
	line	32
;number_display.c: 32: ssd_switch(1,0,1,1);
	movlw	low(0)
	movwf	0+(?_ssd_switch)+02h
	movlw	high(0)
	movwf	(0+(?_ssd_switch)+02h)+1
	movlw	low(01h)
	movwf	(?_ssd_switch)
	movlw	high(01h)
	movwf	((?_ssd_switch))+1
	movlw	low(01h)
	movwf	0+(?_ssd_switch)+06h
	movlw	high(01h)
	movwf	(0+(?_ssd_switch)+06h)+1
	movlw	low(01h)
	movwf	0+(?_ssd_switch)+04h
	movlw	high(01h)
	movwf	(0+(?_ssd_switch)+04h)+1
	fcall	_ssd_switch
	
l30000375:	
	line	33
;number_display.c: 33: PORTB = numbers[c];
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movf	(display_ssd@c),w
	movwf	(??_display_ssd+0+0)
	addwf	(??_display_ssd+0+0),w
	addlw	(_numbers)&0ffh
	movwf	fsr0
	bcf	status, 7	;select IRP bank0
	movf	indf,w
	movwf	(6)	;volatile
	
l30000376:	
	line	34
;number_display.c: 34: delay(1);
	movlw	low(01h)
	movwf	(?_delay)
	movlw	high(01h)
	movwf	((?_delay))+1
	fcall	_delay
	
l30000377:	
	line	35
;number_display.c: 35: PORTB = 0x00;
	clrc
	movlw	0
	btfsc	status,0
	movlw	1
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(6)	;volatile
	
l30000378:	
	line	37
;number_display.c: 37: ssd_switch(0,1,1,1);
	movlw	low(01h)
	movwf	0+(?_ssd_switch)+02h
	movlw	high(01h)
	movwf	(0+(?_ssd_switch)+02h)+1
	movlw	low(0)
	movwf	(?_ssd_switch)
	movlw	high(0)
	movwf	((?_ssd_switch))+1
	movlw	low(01h)
	movwf	0+(?_ssd_switch)+06h
	movlw	high(01h)
	movwf	(0+(?_ssd_switch)+06h)+1
	movlw	low(01h)
	movwf	0+(?_ssd_switch)+04h
	movlw	high(01h)
	movwf	(0+(?_ssd_switch)+04h)+1
	fcall	_ssd_switch
	
l30000379:	
	line	38
;number_display.c: 38: PORTB = numbers[d];
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movf	(display_ssd@d),w
	movwf	(??_display_ssd+0+0)
	addwf	(??_display_ssd+0+0),w
	addlw	(_numbers)&0ffh
	movwf	fsr0
	bcf	status, 7	;select IRP bank0
	movf	indf,w
	movwf	(6)	;volatile
	line	39
;number_display.c: 39: delay(1);
	movlw	low(01h)
	movwf	(?_delay)
	movlw	high(01h)
	movwf	((?_delay))+1
	fcall	_delay
	
l30000380:	
	line	40
;number_display.c: 40: PORTB = 0x00;
	clrc
	movlw	0
	btfsc	status,0
	movlw	1
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(6)	;volatile
	
l5:	
	return
	opt stack 0
GLOBAL	__end_of_display_ssd
	__end_of_display_ssd:
; =============== function _display_ssd ends ============

psect	text26,local,class=CODE,delta=2
global __ptext26
__ptext26:
	line	41
	signat	_display_ssd,16504
	global	_tris

; *************** function _tris *****************
; Defined at:
;		line 50 in file "C:\Users\Prolific\Desktop\Manthan Ladva\Pic16-Projects\ssd\number_display\number_display.c"
; Parameters:    Size  Location     Type
;		None
; Auto vars:     Size  Location     Type
;		None
; Return value:  Size  Location     Type
;		None               void
; Registers used:
;		wreg, status,2, status,0
; Tracked objects:
;		On entry : 0/0
;		On exit  : 0/0
;		Unchanged: 0/0
; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;      Locals:         0       0       0       0       0
;      Temp:     0
;      Total:    0
; This function calls:
;		Nothing
; This function is called by:
;		_main
; This function uses a non-reentrant model
; 
psect	text26
	file	"C:\Users\Prolific\Desktop\Manthan Ladva\Pic16-Projects\ssd\number_display\number_display.c"
	line	50
	global	__size_of_tris
	__size_of_tris	equ	__end_of_tris-_tris
;number_display.c: 50: void tris(void){
	
_tris:	
	opt stack 7
; Regs used in _tris: [wreg+status,2+status,0]
	line	51
	
l30000359:	
;number_display.c: 51: TRISA1 = 0;
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	bcf	(1065/8)^080h,(1065)&7
	
l30000360:	
	line	52
;number_display.c: 52: TRISB = 0x00;
	clrc
	movlw	0
	btfsc	status,0
	movlw	1
	movwf	(134)^080h	;volatile
	
l30000361:	
	line	53
;number_display.c: 53: TRISC = 0xF8;
	movlw	(0F8h)
	movwf	(135)^080h	;volatile
	
l7:	
	return
	opt stack 0
GLOBAL	__end_of_tris
	__end_of_tris:
; =============== function _tris ends ============

psect	text27,local,class=CODE,delta=2
global __ptext27
__ptext27:
	line	54
	signat	_tris,88
	global	_delay

; *************** function _delay *****************
; Defined at:
;		line 56 in file "C:\Users\Prolific\Desktop\Manthan Ladva\Pic16-Projects\ssd\number_display\number_display.c"
; Parameters:    Size  Location     Type
;  time            2    4[COMMON] unsigned int 
; Auto vars:     Size  Location     Type
;  j               2    2[COMMON] unsigned int 
;  i               2    0[COMMON] unsigned int 
; Return value:  Size  Location     Type
;		None               void
; Registers used:
;		wreg
; Tracked objects:
;		On entry : 0/0
;		On exit  : 0/0
;		Unchanged: 0/0
; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;      Locals:         6       0       0       0       0
;      Temp:     0
;      Total:    6
; This function calls:
;		Nothing
; This function is called by:
;		_display_ssd
; This function uses a non-reentrant model
; 
psect	text27
	file	"C:\Users\Prolific\Desktop\Manthan Ladva\Pic16-Projects\ssd\number_display\number_display.c"
	line	56
	global	__size_of_delay
	__size_of_delay	equ	__end_of_delay-_delay
;number_display.c: 56: void delay(unsigned int time){
	
_delay:	
	opt stack 6
; Regs used in _delay: [wreg]
	line	58
	
l30000383:	
;number_display.c: 57: unsigned int i,j;
;number_display.c: 58: for(i=0;i<time;i++) for(j=0;j<40;j++);
	movlw	low(0)
	movwf	(delay@i)
	movlw	high(0)
	movwf	((delay@i))+1
	goto	l12
	
l30000384:	
	movlw	low(0)
	movwf	(delay@j)
	movlw	high(0)
	movwf	((delay@j))+1
	
l30000386:	
	movlw	low(01h)
	addwf	(delay@j),f
	skipnc
	incf	(delay@j+1),f
	movlw	high(01h)
	addwf	(delay@j+1),f
	movlw	high(028h)
	subwf	(delay@j+1),w
	movlw	low(028h)
	skipnz
	subwf	(delay@j),w
	skipc
	goto	u111
	goto	u110
u111:
	goto	l30000386
u110:
	
l30000387:	
	movlw	low(01h)
	addwf	(delay@i),f
	skipnc
	incf	(delay@i+1),f
	movlw	high(01h)
	addwf	(delay@i+1),f
	
l12:	
	movf	(delay@time+1),w
	subwf	(delay@i+1),w
	skipz
	goto	u125
	movf	(delay@time),w
	subwf	(delay@i),w
u125:
	skipc
	goto	u121
	goto	u120
u121:
	goto	l30000384
u120:
	
l8:	
	return
	opt stack 0
GLOBAL	__end_of_delay
	__end_of_delay:
; =============== function _delay ends ============

psect	text28,local,class=CODE,delta=2
global __ptext28
__ptext28:
	line	59
	signat	_delay,4216
	global	_ssd_switch

; *************** function _ssd_switch *****************
; Defined at:
;		line 43 in file "C:\Users\Prolific\Desktop\Manthan Ladva\Pic16-Projects\ssd\number_display\number_display.c"
; Parameters:    Size  Location     Type
;  a               2    0[COMMON] unsigned int 
;  b               2    2[COMMON] unsigned int 
;  c               2    4[COMMON] unsigned int 
;  d               2    6[COMMON] unsigned int 
; Auto vars:     Size  Location     Type
;		None
; Return value:  Size  Location     Type
;		None               void
; Registers used:
;		None
; Tracked objects:
;		On entry : 0/0
;		On exit  : 0/0
;		Unchanged: 0/0
; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;      Locals:         8       0       0       0       0
;      Temp:     0
;      Total:    8
; This function calls:
;		Nothing
; This function is called by:
;		_display_ssd
; This function uses a non-reentrant model
; 
psect	text28
	file	"C:\Users\Prolific\Desktop\Manthan Ladva\Pic16-Projects\ssd\number_display\number_display.c"
	line	43
	global	__size_of_ssd_switch
	__size_of_ssd_switch	equ	__end_of_ssd_switch-_ssd_switch
;number_display.c: 43: void ssd_switch(unsigned int a, unsigned int b, unsigned int c, unsigned int d){
	
_ssd_switch:	
	opt stack 6
; Regs used in _ssd_switch: []
	line	44
	
l30000388:	
;number_display.c: 44: RA1 = a;
	btfsc	(ssd_switch@a),0
	goto	u131
	goto	u130
	
u131:
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bsf	(41/8),(41)&7
	goto	u144
u130:
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bcf	(41/8),(41)&7
u144:
	line	45
;number_display.c: 45: RC0 = b;
	btfsc	(ssd_switch@b),0
	goto	u151
	goto	u150
	
u151:
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bsf	(56/8),(56)&7
	goto	u164
u150:
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bcf	(56/8),(56)&7
u164:
	line	46
;number_display.c: 46: RC1 = c;
	btfsc	(ssd_switch@c),0
	goto	u171
	goto	u170
	
u171:
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bsf	(57/8),(57)&7
	goto	u184
u170:
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bcf	(57/8),(57)&7
u184:
	line	47
;number_display.c: 47: RC2 = d;
	btfsc	(ssd_switch@d),0
	goto	u191
	goto	u190
	
u191:
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bsf	(58/8),(58)&7
	goto	u204
u190:
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bcf	(58/8),(58)&7
u204:
	
l6:	
	return
	opt stack 0
GLOBAL	__end_of_ssd_switch
	__end_of_ssd_switch:
; =============== function _ssd_switch ends ============

psect	text29,local,class=CODE,delta=2
global __ptext29
__ptext29:
	line	48
	signat	_ssd_switch,16504
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	end
