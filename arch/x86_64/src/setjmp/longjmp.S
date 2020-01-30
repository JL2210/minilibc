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
	mov %esi, %eax
	xor %rcx, %rcx
	test %eax, %eax
	jnz 0f
	inc %eax
0:
	mov (JB_SP * 8)(%rdi), %rsp
	mov %rcx, (JB_SP * 8)(%rdi)
	mov (JB_BX * 8)(%rdi), %rbx
	mov %rcx, (JB_BX * 8)(%rdi)
	mov (JB_BP * 8)(%rdi), %rbp
	mov %rcx, (JB_BP * 8)(%rdi)
	mov (JB_12 * 8)(%rdi), %r12
	mov %rcx, (JB_12 * 8)(%rdi)
	mov (JB_13 * 8)(%rdi), %r13
	mov %rcx, (JB_13 * 8)(%rdi)
	mov (JB_14 * 8)(%rdi), %r14
	mov %rcx, (JB_14 * 8)(%rdi)
	mov (JB_15 * 8)(%rdi), %r15
	mov %rcx, (JB_15 * 8)(%rdi)
	xchg %rcx, (JB_PC * 8)(%rdi)
	jmp *%rcx
