	.file	"swap.c"
	.globl	bufp0
	.data
	.align 4
	.type	bufp0, @object
	.size	bufp0, 4
bufp0:
	.long	buf
	.comm	bufp1,4,4
	.text
	.globl	swap
	.type	swap, @function
swap:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$buf+4, bufp1
	movl	bufp0, %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
	movl	bufp0, %eax
	movl	bufp1, %edx
	movl	(%edx), %edx
	movl	%edx, (%eax)
	movl	bufp1, %eax
	movl	-4(%ebp), %edx
	movl	%edx, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	swap, .-swap
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
