TITLE homework05 (homework05.asm)

INCLUDE Irvine32.inc

; The data section is used for declaring initialized data or constants.
; This data does not change at runtime.
; You can declare various constant values, file names, or buffer size, etc., in this section.
.data
ninenine BYTE 81 DUP(?)

.code

start@0 PROC

    mov ecx,9
    mov esi,OFFSET ninenine

    L:
        mov bh,10
        sub bh,cl
        mov bl,1

        L1:

        movzx eax,bh
        mul bl
        mov [esi],al
        inc esi
        inc bl
        cmp bl,10
        jnz L1

    loop L

	exit                 ;end
start@0 ENDP
END start@0
