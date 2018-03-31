TITLE homework092 (homework092.asm)

INCLUDE Irvine32.inc


main EQU start@0

Str_remove PROTO,
    pStart:PTR BYTE,
    nChars:DWORD

.data
target1 BYTE "104502517",0
target2 BYTE "104502518",0
target3 BYTE "999999999",0

.code
main PROC
	invoke Str_remove, ADDR target1, 5       ; �Ĥ@�Ӧr�겾��5�Ӧr��
	mov edx,OFFSET target1
	call WriteString
	call Crlf

	mov ebx, OFFSET target2
	invoke Str_remove, ebx, 2                ; �ĤG�Ӧr�겾��2�Ӧr��
	mov edx,OFFSET target2
	call WriteString
	call Crlf

	invoke Str_remove, ADDR [target2+1], 15  ; �ĤG�Ӧr�겾���W�L�r����ת��r��
	mov edx,OFFSET target2
	call WriteString
	call Crlf
	call WaitMsg
	exit
main ENDP

Str_remove PROC,
	pStart:PTR BYTE,	; points to first character to delete
	nChars:DWORD	    ; number of characters to delete

	invoke Str_length, pStart
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
