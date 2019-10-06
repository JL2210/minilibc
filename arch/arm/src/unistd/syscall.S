.globl syscall
syscall:
	mov r7, r0
	mov r0, r1
	mov r1, r2
	mov r2, r3
	mov r3, r4
	mov r4, r5
	mov r5, r6
	swi #0
