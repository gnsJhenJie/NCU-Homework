TITLE homework01 (homework01.asm)

INCLUDE Irvine32.inc

; The data section is used for declaring initialized data or constants.
; This data does not change at runtime.
; You can declare various constant values, file names, or buffer size, etc., in this section.
.data
                    ;my last 4 studentID is 2518
Digit0 BYTE 2h      ;store 2 in variable Digit0
Digit1 BYTE 5h      ;store 5 in variable Digit1
Digit2 BYTE 1h      ;store 1 in variable Digit2
Digit3 BYTE 8h      ;store 8 in variable Digit3
MyID WORD ?         ;initialize variable MyID


; The code section is a phrase used to refer to a portion of memory or of an object file
; that contains executable instructions.
.code
; main procedure
start@0 PROC

	mov ah,Digit0   ;store 2 into ah, now register ax is 0x02??
	shl ah,4        ;left shift ah, now register ax is 0x20??
	add ah,Digit1   ;add 5 into ah, now register ax is 0x25??

	mov al,Digit2   ;store 1 into al, now register ax is 0x2501
	shl al,4        ;left shift al, now register ax is 0x2510
	add al,Digit3   ;add 8 into al, now register ax is 0x2518

	mov MyID,ax     ;store 2518 into variable MyID, now MyID is 0x2518



	exit
start@0 ENDP
END start@0
