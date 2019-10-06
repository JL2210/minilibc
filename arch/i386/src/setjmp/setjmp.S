#ifndef __ASSEMBLER__
# define __ASSEMBLER__
#endif
#include <bits/setjmp.h>

.globl __setjmp
.globl _setjmp
.globl setjmp
__setjmp:
_setjmp:
setjmp:
	pop %eax
	mov (%esp), %edx
	mov %esp, (JB_SP*4)(%edx)
	push %eax
	mov %eax, (JB_PC*4)(%edx)
	mov %ebx, (JB_BX*4)(%edx)
	mov %ebp, (JB_BP*4)(%edx)
	mov %edi, (JB_DI*4)(%edx)
	mov %esi, (JB_SI*4)(%edx)
	xor %eax, %eax
	ret
