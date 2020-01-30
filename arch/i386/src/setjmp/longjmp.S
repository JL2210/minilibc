#ifndef __ASSEMBLER__
# define __ASSEMBLER__
#endif
#include <bits/setjmp.h>

.globl siglongjmp
.globl _longjmp
.globl longjmp
siglongjmp:
_longjmp:
longjmp:
	mov 4(%esp), %edx
	mov 8(%esp), %eax
	xor %ecx, %ecx
	test %eax, %eax
	jnz 0f
	inc %eax
0:
	mov (JB_SP * 4)(%edx), %esp
	mov %ecx, (JB_SP * 4)(%edx)
	mov (JB_BX * 4)(%edx), %ebx
	mov %ecx, (JB_BX * 4)(%edx)
	mov (JB_BP * 4)(%edx), %ebp
	mov %ecx, (JB_BP * 4)(%edx)
	mov (JB_DI * 4)(%edx), %edi
	mov %ecx, (JB_DI * 4)(%edx)
	mov (JB_SI * 4)(%edx), %esi
	mov %ecx, (JB_SI * 4)(%edx)
	xchg %ecx, (JB_PC * 4)(%edx)
	jmp *%ecx
