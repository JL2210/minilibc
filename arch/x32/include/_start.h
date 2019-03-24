__asm__(
".text \n"
".globl _start \n"
"_start: \n"
"	xor %ebp, %ebp \n"
"	mov %esp, %edi \n"
"	and $-0x0f, %esp \n"
"	call _c_start \n"
);
