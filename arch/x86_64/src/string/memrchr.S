.globl memrchr
memrchr:
	mov %rdx, %rcx
	add %rdx, %rdi
	movzbl %sil, %eax
	std
	repne scasb
	sete %cl
	cld
	lea 1(%rdi), %rax
	test %cl, %cl
	cmovz %rcx, %rax
	ret
