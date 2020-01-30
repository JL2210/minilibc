.globl _memmove
.globl memmove
_memmove:
memmove:
	push %edi
	push %esi
	mov 12(%esp), %edi
	mov 16(%esp), %esi
	mov 20(%esp), %ecx
	mov %edi, %eax
	cmp %edi, %esi
	jae 0f
	lea -1(%ecx), %edx
	add %edx, %edi
	add %edx, %esi
	std
0:
	rep movsb
	cld
	pop %esi
	pop %edi
	ret
