.section .init
.globl _init
_init:
	push %ebp
	mov %esp, %ebp

.section .fini
.globl _fini
_fini:
	push %ebp
	mov %esp, %ebp
