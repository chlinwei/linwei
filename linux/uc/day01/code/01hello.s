	.file	"01hello.c"
	.section	.rodata
	.align 4
.LC0:
	.string	"\344\273\212\345\244\251\345\214\227\344\272\254\347\232\204\351\233\276\351\234\276\346\257\224\350\276\203\345\244\247\357\274\214\350\257\267\345\244\247\345\256\266\345\207\217\345\260\221\346\210\267\345\244\226\346\264\273\345\212\250!"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$16, %esp
	movl	$.LC0, (%esp)
	call	puts
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.4.7-1ubuntu2) 4.4.7"
	.section	.note.GNU-stack,"",@progbits
