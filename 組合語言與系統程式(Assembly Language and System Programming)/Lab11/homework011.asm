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

    mov edi,OFFSET target    ;edi = target起始位置
    mov al,[edi+17]          ;al = 學號2最後一碼(字元)
    mov ecx,lengthof target  ;ecx = target 字串的長度
    cld                      ;clear direction flag
    repne scasb              ;repeat searching while not equal
    dec edi                  ;將找到的字元位置減一
    mov eax,OFFSET target    ;eax = target起始位置
    sub edi,eax              ;edi -= target起始位置
    call DumpRegs            ;顯示目前暫存器狀況

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
	mov	ecx,eax		    ; 抓到字串長度存放在 ecx 給之後複製迴圈用

	.IF nChars <= ecx	; 檢查移除字元是否超過字串大小
	  sub ecx,nChars	; 如果沒有超過，就剪掉移除的字元數量
	.ENDIF

	mov	esi, pStart		; 設定複製來源字串的起始點
	add	esi, nChars	    ; 將起始點移到正確要複製的位置
	mov	edi, pStart		; 將目的起始點設定好

	cld					; clear direction flag(forward)
	rep	movsb			; do the move
	mov	BYTE PTR [edi],0; insert new null byte

Exit_proc:
	ret
Str_remove ENDP
END main
