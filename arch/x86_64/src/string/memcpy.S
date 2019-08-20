.globl memcpy
memcpy:
	mov %rdx, %rcx
	mov %rdi, %rax
	rep movsb
	ret
