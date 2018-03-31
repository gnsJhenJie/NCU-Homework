TITLE homework03 (homework03.asm)

INCLUDE Irvine32.inc

.data
 myID BYTE "104502518"
 size_ID = LENGTHOF myID
 myID2 BYTE "104502517"
 size_ID2 = LENGTHOF myID2

.code

Convert PROC USES eax

    L1:

        mov al,[esi]
        add al,41h
        mov [esi],al

    loop L1

    ret
Convert ENDP

Convert2 PROC

    PUSH eax

    L1:

        mov al,[esi]
        add al,41h
        mov [esi],al

    loop L1

    POP eax

    ret
Convert ENDP

start@0 PROC

    mov eax,9999h
    mov ebx,9999h
    mov edx,9999h
    mov esi, OFFSET myID
    mov ecx, size_ID
    call Convert
    mov esi, OFFSET myID2
    mov ecx, size_ID2
    call Convert2

    exit
start@0 ENDP
END start@0
