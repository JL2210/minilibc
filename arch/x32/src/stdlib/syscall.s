.text
.globl syscall
syscall:
	mov %rdi, %rax
	mov %rsi, %rdi
	mov %rdx, %rsi
	mov %rcx, %rdx
	mov %r8, %r10
	mov %r9, %r8
	mov 8(%esp), %r9
	syscall
	cmp $-0x0fff, %rax
	jae 0f
	ret
0:
	neg %rax
	push %rax
	call __get_errno
	mov %eax, %edi
	pop %rax
	mov %rax, (%edi)
	mov $-1, %rax
	ret
