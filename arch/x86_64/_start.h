__asm__(
".text \n"
".globl _start \n"
"_start: \n"
"\txor %rbp, %rbp \n"
#ifdef _ERROR_ON_UNALIGNED_ACCESS
"\tpushf \n"
"\torl $0x040000, (%rsp) \n"
"\tpopf \n"
#endif
"\tmov %rsp, %rdi \n"
"\tandq $-0x0f, %rsp \n"
"\tcall _c_start \n"
);
