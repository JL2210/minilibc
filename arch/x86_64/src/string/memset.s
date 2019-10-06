.globl _memset
.globl memset
_memset:
memset:
	mov %rdx, %rcx
	mov %rdi, %rdx
	movzbl %sil, %eax
	rep stosb
	mov %rdx, %rax
	ret
