TITLE homework091 (homework091.asm)

INCLUDE Irvine32.inc
.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword	                ;�ŧi proto type
DifferentInputs proto, v1:DWORD,v2:DWORD ,v3:DWORD	;�ŧi proto type

.data
.code
start@0 PROC

    invoke DifferentInputs,2,2,3
    invoke DifferentInputs,2,3,2
    invoke DifferentInputs,3,5,5
    invoke DifferentInputs,2,2,2
    invoke DifferentInputs,104522064,104502517,104502518

    call WaitMsg
    invoke ExitProcess,0
start@0 ENDP

DifferentInputs proc,v1:dword, v2:dword, v3:dword
    mov eax,v1   	 ; ���X v1
    cmp v2,eax       ; �Pv2���
    je Label_Equal   ; �Y�۵��h����Label_Equal,�^��0
    cmp v3,eax       ; �Pv3�����
    je Label_Equal   ; �Y�۵��h����Label_Equal,�^��0

    mov eax,v2       ; ���X v2
    cmp v3, eax      ; �Pv3�����
    je Label_Equal   ; �Y�۵��h����Label_Equal,�^��0
    mov eax,1        ; �^��1
    jmp exit_label   ; return true

Label_Equal:
    mov  eax,0       ; return false

exit_label:
    call DumpRegs
    ret

DifferentInputs ENDP


END start@0
