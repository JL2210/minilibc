__asm__(
".text \n"
".globl _start \n"
"_start: \n"
"\txor %ebp, %ebp \n"
#ifdef _ERROR_ON_UNALIGNED_ACCESS
"\tpushf \n"
"\torl $0x040000, (%esp) \n"
"\tpopf \n"
#endif
"\tmov %esp, %eax \n"
"\tand $-0x0f, %esp \n"
"\tpush %eax \n"
"\tpush %eax \n"
"\tpush %eax \n"
"\tcall _c_start \n"
);
