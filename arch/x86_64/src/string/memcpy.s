.globl _memcpy
.globl memcpy
_memcpy:
memcpy:
	mov %rdx, %rcx
	mov %rdi, %rax
	rep movsb
	ret
