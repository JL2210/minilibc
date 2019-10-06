.globl ___syscall
.globl __syscall
___syscall:
__syscall:
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
	cmp $-4096, %eax
	ja 0f
	ret
0:	neg %eax
	mov %eax, %ecx
	call __errno_location
	mov %ecx, (%eax)
	mov $-1, %eax
	ret

.weak _syscall
.weak syscall
.set _syscall, ___syscall
.set syscall, __syscall
