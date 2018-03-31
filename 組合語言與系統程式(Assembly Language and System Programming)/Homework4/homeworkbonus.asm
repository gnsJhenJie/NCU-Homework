TITLE homework (homework.asm)

INCLUDE Irvine32.inc

.stack 4096
ExitProcess PROTO,dwExitCode:DWORD
CountMatches PROTO ar1ptr:PTR SDWORD,ar2ptr:PTR SDWORD,arlen:DWORD


.data
Array1 SDWORD 10,5,4,-6,2,11,12
Array2 SDWORD 10,5,3,1,4,2,-6
Arraysize = LENGTHOF Array1


.code

CountMatches PROC,ar1ptr:PTR SDWORD,ar2ptr:PTR SDWORD,arlen:DWORD
    push esi
    push edi
    push ecx
    push ebx
    push edx
    mov ecx,arlen
    mov esi,ar1ptr

L1:
    mov edi,ar2ptr
    mov ebx,[esi]
    push ecx
    mov ecx,arlen
LL:
    mov edx,[edi]
    cmp ebx,edx
    jz L2
    jmp LL2
L2:
    inc eax
LL2:
    add edi,4
    loop LL
L3:
    pop ecx
    add esi,4
    loop L1

    pop edx
    pop ebx
    pop ecx
    pop edi
    pop esi
    ret

CountMatches ENDP

start@0 PROC

    mov eax,0
    INVOKE CountMatches,ADDR Array1,ADDR Array2,Arraysize
    call WriteInt

    call Crlf
    call WaitMsg
    INVOKE ExitProcess,0
    exit
start@0 ENDP
END start@0


