TITLE homework2 (homework2.asm)

INCLUDE Irvine32.inc

; The data section is used for declaring initialized data or constants.
; This data does not change at runtime.
; You can declare various constant values, file names, or buffer size, etc., in this section.
.data
BitStrs BYTE 8 dup(?)           ;initialize BitStrs
ChStrs BYTE "########"          ;initialize ChStrs
       BYTE "########"
       BYTE "##    ##"
       BYTE "########"
       BYTE "########"
       BYTE "##    ##"
       BYTE "########"
       BYTE "########"



.code

change PROC
L2:
    mov ah,[esi]                ;use ah to store value of ChStrs
    cmp ah,32                   ;compare ChStrs is # or blank, if it is # jump to L3
    jnz L3
    mov al,48                   ;it is blank, so store '0' ASCII code into al
    jmp L4
L3:
    mov al,49                   ;it is #, so store '1' ASCII code into al
L4:
    mov [ebx],al                ;store ASCII into BitStrs
    inc ebx                     ;point to next BitStrs
    inc esi                     ;point to next ChStrs
    inc dl                      ;increase counter dl
    cmp dl,8                    ;if dl is not 8,jump to L2 to continue the same line
    jnz L2

    ret                         ;return to main
change ENDP

start@0 PROC
    mov ecx,8                   ;count is 8
    mov esi,OFFSET ChStrs       ;point to ChStrs
L1:
    mov ebx,OFFSET BitStrs      ;use ebx to point BitStrs
    mov dl,0                    ;initialize counter dl
    call change                 ;call the function change
    mov dl,0                    ;initialize counter dl to be used to output BitStrs
    mov ebx,OFFSET BitStrs      ;point to the beginning of BitStrs
L5:                             ;L5 for output BitStrs
    mov al,[ebx]
    call WriteChar
    inc ebx
    inc dl
    cmp dl,8
    jnz L5
    call Crlf                   ;jump to next line in terminal
    loop L1                     ;loop L1 for 8 times

    call WaitMsg                ;call the function WaitMsg
	exit                 ;end
start@0 ENDP
END start@0
