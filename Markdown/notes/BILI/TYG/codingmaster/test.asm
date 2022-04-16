mov dest 

mov eax,3 
mov bx,ax 
;赋值
add eax,4 
add al,ah 

sub bx,10 
sub eax,edi 
;加减
inc ecx
dec dl
;自增与自减

symbol equ value
;常量声明
%define SIZE 100
    mov eax,SIZE 

L1 db 0
L2 dw 1000
;字节变量与字变量
L3 db 110101b
L4 db 12h
L5 db 17o
L6 dd 1A92h
;字节变量初始化
;双字节变量初始化
L7 resb 1
;1个未初始化的字节
L8 db "A"
;字节变量初始化为"A"
times 100 db 0
resw 100
;数据指示符

;指定 byte字节 word字 qword四字 tword十字