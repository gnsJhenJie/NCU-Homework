TITLE homework012 (homework012.asm)

INCLUDE Irvine32.inc
main	EQU start@0
BoxWidth = 9
BoxHeight = 9

.data
boxTop    BYTE 0DAh,(BoxWidth - 2) DUP(0C4h),0BFh
boxBody   BYTE 0B3h,(BoxWidth - 2) DUP(' '),0B3h
boxBottom BYTE 0C0h,(BoxWidth - 2) DUP(0C4h),0D9h

outputHandle DWORD 0
bytesWritten DWORD 0
count DWORD 0
xyPosition COORD <10,5>

cellsWritten DWORD ?
attributes0 WORD BoxWidth DUP(0Eh)
attributes1 WORD (BoxWidth-1) DUP(0Bh),0Ch
attributes2 WORD BoxWidth DUP(0Ah)


.code
main PROC

    INVOKE GetStdHandle,STD_OUTPUT_HANDLE; Get the console ouput handle
    mov outputHandle,eax ; save console handle
    call Clrscr
    ; 畫出box的第一行

    INVOKE WriteConsoleOutputAttribute,
      outputHandle,
      ADDR attributes0,
      BoxWidth,
      xyPosition,
      ADDR bytesWritten

    INVOKE WriteConsoleOutputCharacter,
       outputHandle,   ; console output handle
       ADDR boxTop,   ; pointer to the top box line
       BoxWidth,   ; size of box line
       xyPosition,   ; coordinates of first char
       ADDR bytesWritten    ; output count

    inc xyPosition.Y   ; 座標換到下一行位置

    mov ecx,BoxHeight-2    ; number of lines in body



L1: push ecx  ; save counter 避免invoke 有使用到這個暫存器
    INVOKE WriteConsoleOutputAttribute,
      outputHandle,
      ADDR attributes1,
      BoxWidth,
      xyPosition,
      ADDR bytesWritten

 INVOKE WriteConsoleOutputCharacter,
       outputHandle,
       ADDR boxBody,   ; pointer to the box body
       BoxWidth,
       xyPosition,
       ADDR bytesWritten

    inc xyPosition.Y   ; next line
    pop ecx   ; restore counter
    loop L1

    INVOKE WriteConsoleOutputAttribute,
      outputHandle,
      ADDR attributes2,
      BoxWidth,
      xyPosition,
      ADDR bytesWritten

    ; draw bottom of the box
    INVOKE WriteConsoleOutputCharacter,
       outputHandle,
       ADDR boxBottom,   ; pointer to the bottom of the box
       BoxWidth,
       xyPosition,
       ADDR bytesWritten

    call WaitMsg
    call Clrscr
    exit
main ENDP
END main
