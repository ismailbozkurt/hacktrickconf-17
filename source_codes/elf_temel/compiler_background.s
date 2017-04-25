// gcc deneme.s -o deneme
.section .data
	format:   .string "hello yolo"  

.section .text
            .global main  
main:
	pushl 	%ebp
	movl 	%esp, %ebp
	pushl	$format
	call	puts
	xorl 	%eax, %eax
	leave
	ret
