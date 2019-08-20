__asm__(
".text \n"
".globl _start \n"
"_start: \n"
"\tmov fp, 0 \n"
"\tmov lr, 0 \n"
"\tmov r1, sp \n"
"\tand sp, r1, -8 \n"
"\tbl _c_start \n"
);
