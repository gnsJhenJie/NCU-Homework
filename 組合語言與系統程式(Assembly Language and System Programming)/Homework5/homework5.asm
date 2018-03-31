TITLE homework5 (homework5.asm)

INCLUDE Irvine32.inc

.stack 4096
Str_nextWord PROTO,pString:PTR DWORD,delimiter:BYTE
                   ;pointer to string ;delimiter to find

.data
testStr BYTE "ABC\DE\FGHIJK\LM",0


.code

Str_nextWord PROC,pString:PTR DWORD,delimiter:BYTE
    mov bh,delimiter
    mov edi,pString
LL1:
    mov bl,[edi]
    cmp bh,bl
    jz LL3
LL2:
    cmp bl,0
    jz LLend
    inc edi
    jmp LL1
LL3:
    mov bl,0
    mov [edi],bl
    inc edi
LLend:
    mov ebx,edi
    ret



Str_nextWord ENDP

start@0 PROC

    call Clrscr
    mov edx,OFFSET testStr   ;display string
    call WriteString
    call Crlf
;Loop through the string, replace each delimiter, and display the remaining string.
    mov esi,OFFSET testStr
L1:
    INVOKE Str_nextword,esi,"\"
    jz Exit_prog            ;quit if not found
    mov esi,ebx             ;point to next substring
    mov edx,esi
    call WriteString         ;display remainder of string
    call Crlf
    jmp L1

Exit_prog:
    call WaitMsg

    exit
start@0 ENDP
END start@0


