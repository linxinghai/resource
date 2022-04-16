%define "asm_io.inc"

segment .data 
prompt1 db "Enter a number:",0
prompt2 db "Enter another number",0
outmsg1 db "You entered",0
outmsg2 db "and",0
outmsg3 db ",the sum of these is",0

segment .bss

input1 resd 1
input2 resd 1

segment .text
    global_asm_main
_asm_main:
    enter 0,0
    pusha

    mov eax,prompt1
    call print_string

    call read_int
    mov [input1],eax
    
    mov eax,prompt2
    call print_string

    call read_int
    mov [input2],eax

    mov eax,[input1]
    add eax,[input2]
    mov ebx,eax

    dump_regs 1
    dump_mem 2,outmsg1,1
    