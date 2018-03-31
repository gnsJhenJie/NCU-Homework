TITLE example (homework.asm)

INCLUDE Irvine32.inc

.data
myID DWORD 104502518d
size_ID = 9
space BYTE 7 DUP(0)
myID_result BYTE "104502518",0

.code

convert MACRO ID,Siz,Result

    IFB<ID>
        EXIT
    ENDIF
    IFB<Siz>
        EXIT
    ENDIF
    IFB<Result>
        EXIT
    ENDIF

    mov ecx,Siz
    mov eax,ID
    mov ebx,10
L:
    mov edx,0
    div ebx
    test edx,1
    jnz L2      ;odd
L1:             ;even
    mov edx,65
    PUSH edx
    jmp L3
L2:             ;odd
    mov edx,66
    PUSH edx
L3:
    loop L

    mov ecx,Siz
    mov edx,OFFSET Result
LL:
    POP [edx]
    inc edx
    loop LL
ENDM


start@0 PROC

    mov eax,myID
    call WriteDec
    call Crlf

    convert myID, size_ID, myID_result

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	mov edx, OFFSET myID_result
	call WriteString
	call Crlf
	call WaitMsg
	exit


start@0 ENDP
END start@0
