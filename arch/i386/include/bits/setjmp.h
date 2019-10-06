#ifndef _BITS_SETJMP_H
#define _BITS_SETJMP_H 1

#if !defined(_SETJMP_H) && !defined(__ASSEMBLER__)
# error "Never include <bits/setjmp.h> directly; use <setjmp.h> instead."
#endif

#define JB_SP 0
#define JB_PC 1
#define JB_BX 2
#define JB_BP 3

#ifdef __amd64__
# define JB_12 4
# define JB_13 5
# define JB_14 6
# define JB_15 7
# define _JMP_BUF_SIZE 8
# ifdef _ILP32
#  define _JMP_BUF_TYPE long long
# else
#  define _JMP_BUF_TYPE long
# endif
#else
# define JB_DI 4
# define JB_SI 5
# define _JMP_BUF_SIZE 6
# define _JMP_BUF_TYPE long
#endif

#endif
