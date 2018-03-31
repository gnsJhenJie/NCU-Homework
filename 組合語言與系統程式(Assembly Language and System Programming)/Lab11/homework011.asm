TITLE homework011 (homework011.asm)

INCLUDE Irvine32.inc

Str_remove PROTO,
    pStart: PTR BYTE,
    nChars: DWORD

main EQU start@0

.stack 4096

.data
target BYTE "104502517104502518ABCDEF",0

.code

main PROC

    mov edi,OFFSET target    ;edi = target�_�l��m
    mov al,[edi+17]          ;al = �Ǹ�2�̫�@�X(�r��)
    mov ecx,lengthof target  ;ecx = target �r�ꪺ����
    cld                      ;clear direction flag
    repne scasb              ;repeat searching while not equal
    dec edi                  ;�N��쪺�r����m��@
    mov eax,OFFSET target    ;eax = target�_�l��m
    sub edi,eax              ;edi -= target�_�l��m
    call DumpRegs            ;��ܥثe�Ȧs�����p

    mov edx,OFFSET target
    call WriteString
    call Crlf
    INVOKE Str_remove,ADDR target,edi
    mov edx,OFFSET target
    call WriteString
    call Crlf
    call WaitMsg

    exit
main ENDP

Str_remove PROC,
	pStart:PTR BYTE,	; points to first character to delete
	nChars:DWORD	    ; number of characters to delete

	INVOKE Str_length, pStart
	mov	ecx,eax		    ; ���r����צs��b ecx ������ƻs�j���

	.IF nChars <= ecx	; �ˬd�����r���O�_�W�L�r��j�p
	  sub ecx,nChars	; �p�G�S���W�L�A�N�ű��������r���ƶq
	.ENDIF

	mov	esi, pStart		; �]�w�ƻs�ӷ��r�ꪺ�_�l�I
	add	esi, nChars	    ; �N�_�l�I���쥿�T�n�ƻs����m
	mov	edi, pStart		; �N�ت��_�l�I�]�w�n

	cld					; clear direction flag(forward)
	rep	movsb			; do the move
	mov	BYTE PTR [edi],0; insert new null byte

Exit_proc:
	ret
Str_remove ENDP
END main
