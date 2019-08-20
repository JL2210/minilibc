.globl setjmp
setjmp:
	pop %rsi
	mov %rsp, (%rdi)
	push %rsi
	mov %rbx, 8(%rdi)
	mov %rbp, 16(%rdi)
	mov %r12, 24(%rdi)
	mov %r13, 32(%rdi)
	mov %r14, 40(%rdi)
	mov %r15, 48(%rdi)
	mov %rsi, 56(%rdi)
	xor %eax, %eax
	ret
