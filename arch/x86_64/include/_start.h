__asm__(
".text \n"
".globl _start \n"
"_start: \n"
"	xor %rbp, %rbp \n"
"	mov %rsp, %rdi \n"
"	andq $-0x0f, %rsp \n"
"	call _c_start \n"
);
