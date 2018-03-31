TITLE homework03 (homework03.asm)

INCLUDE Irvine32.inc

.data
 ninenine BYTE 9 dup(?)

.code
start@0 PROC
    mov ecx,9
    mov al,0
    mov esi, OFFSET ninenine
    L:
        add al,9
        mov [esi],al
        inc esi
    loop L



start@0 ENDP
END start@0
