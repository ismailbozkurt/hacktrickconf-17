;nasm -felf32 deneme.asm -o deneme.o
;ld -m elf_i386 deneme.o -o deneme


section     .text
	global      _start                              ;ld(linker) icin tanımlanmak zorunda !

_start:                                         ;linker'a entry point gosteriyoruz.


	; stdout write "hello world !"
	mov     edx,len_hello                       ;message length
	mov     ecx,msg                             ;message 
	mov     ebx,1                               ;file descriptor (stdout)
	mov     eax,4                               ;system call number (sys_write)
	int     0x80                                ;call kernel

	; stdout write A
	mov edx, len_chrt 
	mov ecx, chrt
	mov eax, 4
	int 0x80



	; stdin read
	mov ebx, 0
	mov ecx, A1
	mov edx, 1
	mov eax, 3
	int 0x80

	nop
	nop
	nop

	; exit routine
	mov     eax,1                               ;system call number (sys_exit)
	int     0x80                                ;call kernel


section	.bss

	A1 	resb 	1 		; 1 bytelık değer atanmamış yer ayrılmıştır.

section	.data

	A2	db 	0 		; 1 byte yer alınmıştır ve değeri 0'dır.
	A3 	dw 	1000		; 1 word yer alınmıştır ve değeri 1000'dir.
	A4 	db 	110101b 	; 1 byte yer alınmıştır ve değeri 53 olan binary karşılığı yazılmıstır.
	A5 	db 	12h 		; 1 byte yer alınmıştır ve değeri 18 olan hex karşığı yazılmıştır.
	A6 	db 	17o 		; 1 byte yer alınmıştır ve değeri 15 olan octal karşılığı yazılmıştır.
	A7 	dd 	1A92h 		; 1 double dword yer alınmıştır ve hex 1A92 değeri atanmıştır.
	

	chrt 	db 	'A',0xa, 0x0         ; byte initialized to ASCII code for A (0x41, 65)
	len_chrt       equ $ - chrt

	msg     db  'Hello, world!',0xa,0x0                 ;our dear string
	len_hello     equ $ - msg                             ;length of string
