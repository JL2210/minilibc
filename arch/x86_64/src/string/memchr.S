.globl memchr
memchr:
	mov %rdx, %rcx
	movzbl %sil, %eax
	repne scasb
	sete %cl
	lea -1(%rdi), %rax
	test %cl, %cl
	cmovz %rcx, %rax
	ret
