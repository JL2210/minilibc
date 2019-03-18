.text
.globl _start
.type _start, STT_FUNC
_start:
	xor %ebp, %ebp
	pop %rsi
	mov %rsp, %rdx
	and $-0x0f, %rsp
	mov main@GOTPCREL(%rip), %rdi
	call *__libc_start_main@GOTPCREL(%rip)
	hlt
