#ifndef __ASSEMBLER__
# define __ASSEMBLER__
#endif
#include <bits/setjmp.h>

.globl __longjmp
.globl _longjmp
.globl longjmp
__longjmp:
_longjmp:
longjmp:
	mov 4(%esp), %edx
	mov 8(%esp), %eax
	test %eax, %eax
	jnz 0f
	inc %eax
0:	mov (JB_SP*4)(%edx), %esp
	mov (JB_BX*4)(%edx), %ebx
	mov (JB_BP*4)(%edx), %ebp
	mov (JB_DI*4)(%edx), %edi
	mov (JB_SI*4)(%edx), %esi
	jmp *(JB_PC*4)(%edx)
