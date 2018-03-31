TITLE homework05 (homework05.asm)

INCLUDE Irvine32.inc

; The data section is used for declaring initialized data or constants.
; This data does not change at runtime.
; You can declare various constant values, file names, or buffer size, etc., in this section.
.data

myID BYTE 1,0,4,5,0,2,5,1,8   ;Student ID
size_ID = LENGTHOF myID       ;size_ID is length of myID
myID_odd BYTE ?
myID_even BYTE ?
myID_result BYTE ?

.code

start@0 PROC

    mov ecx,size_ID      ;count=size_ID=9
    xor esi,esi          ;turn esi,bl,dl to 0
    xor bl,bl
    xor dl,dl
L1:
    mov al,myID[esi]     ;store the value in myID to al
    test al,1            ;test al is a odd or even
    jnz L2               ;if it is odd, jump to L2
    add bl,al            ;if it is even, add the value into bl
    jmp L3               ;after adding, jump to L3
L2:
    add dl,1             ;add one odd count
L3:
    inc esi              ;point to next myID address
    loop L1

    mov myID_odd,dl      ;store odd count into myID_odd
    mov myID_even,bl     ;store even sum into myID_even

    mov cl,myID_odd      ;use odd count to be loop count
    xor al,al            ;turn al to 0

L:                       ;this loop will add even sum for odd count times

    add al,myID_even

    loop L

	mov myID_result,al


	exit                 ;end
start@0 ENDP
END start@0
