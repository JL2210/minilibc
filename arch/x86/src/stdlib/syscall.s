.text
.globl syscall
.type syscall, STT_FUNC
syscall:
	push %ebp
	push %edi
	push %esi
	push %ebx
	mov 44(%esp), %ebp
	mov 40(%esp), %edi
	mov 36(%esp), %esi
	mov 32(%esp), %edx
	mov 28(%esp), %ecx
	mov 24(%esp), %ebx
	mov 20(%esp), %eax
	int $0x80
	pop %ebx
	pop %esi
	pop %edi
	pop %ebp
	cmp $-0x0fff, %eax
	jae 0f
	ret
0:
	mov $-1, %eax
	ret
