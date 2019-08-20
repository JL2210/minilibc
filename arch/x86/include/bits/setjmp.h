#ifndef _BITS_SETJMP_H
#define _BITS_SETJMP_H 1

#ifndef _SETJMP_H
# error "Never include <bits/setjmp.h> directly; use <setjmp.h> instead."
#endif

#ifdef __amd64__
# define _JMP_BUF_SIZE 8
#else
# define _JMP_BUF_SIZE 0
#endif

#endif
