.globl longjmp
longjmp:
	mov %esi, %eax
	test %eax, %eax
	jnz 0f
	inc %eax
0:
	mov (%rdi), %rsp
	mov 8(%rdi), %rbx
	mov 16(%rdi), %rbp
	mov 24(%rdi), %r12
	mov 32(%rdi), %r13
	mov 40(%rdi), %r14
	mov 48(%rdi), %r15
	jmp *56(%rdi)
