TITLE homework02 (homework02.asm)

INCLUDE Irvine32.inc

; The data section is used for declaring initialized data or constants.
; This data does not change at runtime.
; You can declare various constant values, file names, or buffer size, etc., in this section.
.data
Val1 SBYTE 03h    ;Val1 = 03h
Val2 SBYTE 02h    ;Val2 = 02h
Val3 SBYTE 8fh    ;Val3 = 8fh
Rval SDWORD ?     ;Rval = 0

; The code section is a phrase used to refer to a portion of memory or of an object file
; that contains executable instructions.
.code
; main procedure
start@0 PROC

	movsx eax,Val1   ;ax = Val1
	movsx ebx,Val2   ;bx = Val2
	movsx ecx,Val3   ;cx = Val3
	mov edx,0      ;dx = 0
	add eax,ebx     ;ax = Val1 + Val2
	shl eax,1      ;ax =(Val1+Val2)*2
	add edx,eax     ;dx =(Val1+Val2)*2
	shl eax,1      ;ax =(Val1+Val2)*4
	add edx,eax     ;dx =(Val1+Val2)*6
	shl eax,1      ;ax =(Val1+Val2)*8
	add edx,eax     ;dx =(Val1+Val2)*14
	sub ecx,edx    ;cx = Val3-(Val1+Val2)*14
	neg ecx       ;cx = -cx
	mov Rval,ecx  ;Rval = -(Val3 - 14*(Val1+Val2))

	exit
start@0 ENDP
END start@0
