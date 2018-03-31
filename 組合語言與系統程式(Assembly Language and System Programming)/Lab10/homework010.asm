TITLE homework010 (homework010.asm)

INCLUDE Irvine32.inc

Str_copyN PROTO,
    source: PTR DWORD,
    target: PTR DWORD,
    maxChars: DWORD

main EQU start@0

.stack 4096

.data

string_1 BYTE "104502517",0
string_2 BYTE "104502518",0

.code

main PROC

    INVOKE Str_copyN,
    ADDR string_1,
    ADDR string_2+9,
    (SIZEOF string_2)-1

;Display the destination string
    mov edx,OFFSET string_2
    call WriteString
    call Crlf
    call WaitMsg

    exit

main ENDP

Str_copyN PROC USES eax ecx esi edi,
    source: PTR DWORD,
    target: PTR DWORD,
    maxChars: DWORD

;Copy a string from source to target, limiting the number
;of characters to copy. Value in maxChars does not include
;the null byte.

    mov ecx,maxChars
    mov esi,source
    mov edi,target
    cld

    rep movsb
    mov dl,0
    mov [esi],dl
    movsb
    ret
Str_copyN ENDP

END main
