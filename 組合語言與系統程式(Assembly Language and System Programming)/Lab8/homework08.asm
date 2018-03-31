TITLE homework03 (homework03.asm)

INCLUDE Irvine32.inc

.stack 4096
ExitProcess PROTO,dwExitCode:DWORD
FindLargest PROTO aPtr:Ptr SDWORD,arrsize:DWORD


.data
Array1 SDWORD 105522063,104502517,104502518
Array2 SDWORD -105522063,-104502517,-104502518
Array1size = LENGTHOF Array1
Array2size = LENGTHOF Array2

.code

FindLargest PROC,aPtr: PTR SDWORD,arrsize:DWORD

    push esi
    push ecx
    mov eax,80000000h
; smallest possible 32bit signed integer
    mov esi,aPtr     ; point to the first element
    mov ecx,arrsize     ; set iteration times

L1: cmp [esi],eax
; compare the current value and current maximum
    jl L2          ; smaller than max,jump to L2
    mov eax,[esi]     ; update max value

L2: add esi,4
    loop L1

    call WriteInt
    call Crlf

    pop ecx
    pop esi
    ret               ; Return from subroutine

FindLargest ENDP

start@0 PROC

    INVOKE FindLargest,ADDR Array1,Array1size
    INVOKE FindLargest,ADDR Array2,Array2size
    call WaitMsg
    INVOKE ExitProcess,0

    exit
start@0 ENDP
END start@0


