.text
.globl _start
.type _start, STT_FUNC
_start:
	xor %ebp, %ebp
	pop %esi
	mov %esp, %ecx
	and $-0x0f, %esp
	call 0f
	add $_GLOBAL_OFFSET_TABLE_, %ebx
	push %ecx
	push %esi
	mov main@GOT(%ebx), %eax
	push %eax
	call __libc_start_main@PLT
	hlt
0:
	mov (%esp), %ebx
	ret
