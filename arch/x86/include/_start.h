__asm__(
".text\n"
".globl _start\n"
"_start:\n"
"	xor %ebp, %ebp \n"
"	mov %esp, %eax \n"
"	and $-0x0f, %esp \n"
"	push %eax \n"
"	push %eax \n"
"	call 1f \n"
"1:	addl $_DYNAMIC-1b, (%esp) \n"
"	push %eax \n"
"	call _c_start \n"
);
