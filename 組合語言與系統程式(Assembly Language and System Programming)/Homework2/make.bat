@echo off
REM make
REM Assembles and links the 32-bit ASM program into .exe which can be used by WinDBG
REM Uses MicroSoft Macro Assembler version 6.11 and 32-bit Incremental Linker version 5.10.7303
REM Created by Huang

REM delete related files
del homework2.lst
del homework2.obj
del homework2.ilk
del homework2.pdb
del homework2.exe

REM /c          assemble without linking
REM /coff       generate object code to be linked into flat memory model
REM /Zi         generate symbolic debugging information for WinDBG
REM /Fl		Generate a listing file

REM homework2.asm      The name of the source file


ML /c /coff /Zi /Fl homework2.asm
if errorlevel 1 goto terminate

REM /debug              generate symbolic debugging information
REM /subsystem:console  generate console application code
REM /entry:start        entry point from WinDBG to the program
REM                           the entry point of the program must be _start

REM /out:homework2.exe         output homework2.exe code
REM homework2.obj              input homework2.obj
REM Kernel32.lib        library procedures to be invoked from the program
REM irvine32.lib
REM user32.lib

LINK /debug /subsystem:console  /entry:start /out:homework2.exe homework2.obj Kernel32.lib irvine32.lib user32.lib
if errorlevel 1 goto terminate

REM Display all files related to this program:
DIR homework2.*

:terminate
pause
