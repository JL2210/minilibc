.globl memcmp
memcmp:
	mov %rdx, %rcx
	repe cmpsb
	movzbl -1(%rdi), %eax
	movzbl -1(%rsi), %edx
	sub %edx, %eax
	ret
