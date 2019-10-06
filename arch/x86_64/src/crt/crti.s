.section .init
.globl __init
.globl _init
__init:
_init:
	push %rax

.section .fini
.globl __fini
.globl _fini
__fini:
_fini:
	push %rax
