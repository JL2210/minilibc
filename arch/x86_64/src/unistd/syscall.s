.globl ___syscall
.globl __syscall
___syscall:
__syscall:
	mov %rdi, %rax
	mov %rsi, %rdi
	mov %rdx, %rsi
	mov %rcx, %rdx
	mov %r8, %r10
	mov %r9, %r8
	mov 8(%rsp), %r9
	syscall
	cmp $-4096, %rax
	ja 0f
	ret
0:	neg %rax
	mov %rax, %rdi
	call __errno_location
	mov %edi, (%rax)
	mov $-1, %rax
	ret

.weak _syscall
.weak syscall
.set _syscall, ___syscall
.set syscall, __syscall
