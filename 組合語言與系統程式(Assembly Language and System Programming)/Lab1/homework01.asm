TITLE homework01 (homework01.asm)

INCLUDE Irvine32.inc

; The data section is used for declaring initialized data or constants. 
; This data does not change at runtime. 
; You can declare various constant values, file names, or buffer size, etc., in this section.
.data 


; The code section is a phrase used to refer to a portion of memory or of an object file 
; that contains executable instructions.
.code
; main procedure
start@0 PROC
	mov al,10010b ;last two digits of leader's student ID in binary
	mov ah,17     ;last two digits of member's student ID in decimal
	mov ax,2518h  ;last four digits of student's ID in hexadecimal
	mov dx,0EEEAh ;let the value of dx is eeea
	sub dx,ax     ;value of dx subtracting by ax
start@0 ENDP
END start@0