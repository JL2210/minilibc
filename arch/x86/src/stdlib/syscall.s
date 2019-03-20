.hidden __sysinfo

# The calling convention for __vsyscall has the syscall number
# and 5 args arriving as:  eax, edx, ecx, edi, esi, 4(%esp).
# This ensures that the inline asm in the C code never has to touch
# ebx or ebp (which are unavailable in PIC and frame-pointer-using
# code, respectively), and optimizes for size/simplicity in the caller.

.globl __vsyscall
.type __vsyscall, STT_FUNC
__vsyscall:
	push %edi
	push %ebx
	mov %edx, %ebx
	mov %edi, %edx
	mov 12(%esp), %edi
	push %eax
	call 1f
2:	mov %ebx, %edx
	pop %ebx
	pop %ebx
	pop %edi
	ret

1:	mov (%esp), %eax
	add $[__sysinfo-2b], %eax
	mov (%eax), %eax
	test %eax, %eax
	jz 1f
	push %eax
	mov 8(%esp), %eax
	ret                     # tail call to kernel vsyscall entry
1:	mov 4(%esp), %eax
	int $0x80
	ret

# The __vsyscall6 entry point is used only for 6-argument syscalls.
# Instead of passing the 5th argument on the stack, a pointer to the
# 5th and 6th arguments is passed. This is ugly, but there are no
# register constraints the inline asm could use that would make it
# possible to pass two arguments on the stack.

.globl __vsyscall6
.type __vsyscall6, STT_FUNC
__vsyscall6:
	push %ebp
	push %eax
	mov 12(%esp), %ebp
	mov (%ebp), %eax
	mov 4(%ebp), %ebp
	push %eax
	mov 4(%esp), %eax
	call __vsyscall
	pop %ebp
	pop %ebp
	pop %ebp
	ret

.globl syscall
.type syscall, STT_FUNC
syscall:
	lea 24(%esp), %eax
	push %esi
	push %edi
	push %eax
	mov 16(%esp), %eax
	mov 20(%esp), %edx
	mov 24(%esp), %ecx
	mov 28(%esp), %edi
	mov 32(%esp), %esi
	call __vsyscall6
	pop %edi
	pop %edi
	pop %esi
	cmp $-0x0fff, %eax
	je 0f
	ret
0:
	mov $-1, %eax
	ret
