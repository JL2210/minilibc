.globl _memmove
.globl memmove
_memmove:
memmove:
	mov %rdx, %rcx
	mov %rdi, %rax
	cmp %rdi, %rsi
	jae 0f
	dec %rdx
	add %rdx, %rdi
	add %rdx, %rsi
	std
0:
	rep movsb
	cld
	ret
