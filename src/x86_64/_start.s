.text
.globl _start
.type _start, STT_FUNC
_start:
	xor %rbp, %rbp
	mov %rdx, %r9
	pop %rsi
	mov %rsp, %rdx
	andq $-0x0f, %rsp
	push %rax
	push %rsp
	mov _fini@GOTPCREL(%rip), %r8
	mov _init@GOTPCREL(%rip), %rcx
	mov main@GOTPCREL(%rip), %rdi
	call __libc_start_main@PLT
	hlt
