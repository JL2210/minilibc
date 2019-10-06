.section .init
.globl __init
.globl _init
__init:
_init:
	push %ebp
	mov %esp, %ebp

.section .fini
.globl __fini
.globl _fini
__fini:
_fini:
	push %ebp
	mov %esp, %ebp
