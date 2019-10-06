.globl _memset
.globl memset
_memset:
memset:
	push %edi
	mov 8(%esp), %edi
	movzbl 12(%esp), %eax
	mov 16(%esp), %ecx
	mov %edi, %edx
	rep stosb
	mov %edx, %eax
	pop %edi
	ret
