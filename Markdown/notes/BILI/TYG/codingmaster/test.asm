mov dest 

mov eax,3 
mov bx,ax 
;��ֵ
add eax,4 
add al,ah 

sub bx,10 
sub eax,edi 
;�Ӽ�
inc ecx
dec dl
;�������Լ�

symbol equ value
;��������
%define SIZE 100
    mov eax,SIZE 

L1 db 0
L2 dw 1000
;�ֽڱ������ֱ���
L3 db 110101b
L4 db 12h
L5 db 17o
L6 dd 1A92h
;�ֽڱ�����ʼ��
;˫�ֽڱ�����ʼ��
L7 resb 1
;1��δ��ʼ�����ֽ�
L8 db "A"
;�ֽڱ�����ʼ��Ϊ"A"
times 100 db 0
resw 100
;����ָʾ��

;ָ�� byte�ֽ� word�� qword���� twordʮ��