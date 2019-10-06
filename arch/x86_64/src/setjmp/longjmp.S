#ifndef __ASSEMBLER__
# define __ASSEMBLER__
#endif
#include <bits/setjmp.h>

.globl __longjmp
.globl _longjmp
__longjmp:
_longjmp:
	mov %esi, %eax
	test %eax, %eax
	jnz 0f
	inc %eax
0:	mov (JB_SP*8)(%rdi), %rsp
	mov (JB_BX*8)(%rdi), %rbx
	mov (JB_BP*8)(%rdi), %rbp
	mov (JB_12*8)(%rdi), %r12
	mov (JB_13*8)(%rdi), %r13
	mov (JB_14*8)(%rdi), %r14
	mov (JB_15*8)(%rdi), %r15
	jmp *(JB_PC*8)(%rdi)
