__asm__(
".text \n"
".globl _start \n"
"_start: \n"
"\txor %ebp, %ebp \n"
"\tmov %esp, %edi \n"
"\tand $-0x0f, %esp \n"
"\tcall _c_start \n"
);
