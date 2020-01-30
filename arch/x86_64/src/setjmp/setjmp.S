#ifndef __ASSEMBLER__
# define __ASSEMBLER__
#endif
#include <bits/setjmp.h>

.globl __sigsetjmp
.globl __setjmp
.globl _setjmp
__sigsetjmp:
__setjmp:
_setjmp:
	pop %rsi
	mov %rsp, (JB_SP * 8)(%rdi)
	push %rsi
	mov %rsi, (JB_PC * 8)(%rdi)
	mov %rbx, (JB_BX * 8)(%rdi)
	mov %rbp, (JB_BP * 8)(%rdi)
	mov %r12, (JB_12 * 8)(%rdi)
	mov %r13, (JB_13 * 8)(%rdi)
	mov %r14, (JB_14 * 8)(%rdi)
	mov %r15, (JB_15 * 8)(%rdi)
	xor %eax, %eax
	ret
