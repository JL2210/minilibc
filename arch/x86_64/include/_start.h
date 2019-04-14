__asm__(
".text \n"
".globl _start \n"
"_start: \n"
"\txor %rbp, %rbp \n"
"\tmov %rsp, %rdi \n"
"\tandq $-0x0f, %rsp \n"
"\tcall _c_start \n"
);
