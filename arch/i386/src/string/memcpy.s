.globl _memcpy
.globl memcpy
_memcpy:
memcpy:
	push %edi
	push %esi
	mov 12(%esp), %edi
	mov 16(%esp), %esi
	mov 20(%esp), %ecx
	mov %edi, %eax
	rep movsb
	pop %esi
	pop %edi
	ret
