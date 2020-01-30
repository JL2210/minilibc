#ifndef _SETJMP_H
#define _SETJMP_H 1

#include <features.h>
#include <bits/setjmp.h>

#define __need_jmp_buf

#include <bits/defs.h>

__BEGIN_DECLS

extern int __sigsetjmp(sigjmp_buf);

#if defined(_GNU_SOURCE) || \
    defined(_BSD_SOURCE) || \
    defined(_XOPEN_SOURCE) || \
    defined(_POSIX_SOURCE) || \
    defined(_POSIX_C_SOURCE)
typedef jmp_buf sigjmp_buf;

/* fake function to catch undefined behavior */
extern int sigsetjmp(sigjmp_buf);

/* real function */
extern int _setjmp(jmp_buf);

extern _Noreturn void siglongjmp(sigjmp_buf, int);
extern _Noreturn void _longjmp(jmp_buf, int);

/* macro */
# define sigsetjmp(sigjmp_buf) __sigsetjmp(sigjmp_buf)
#endif

/* fake function to catch undefined behavior */
extern int setjmp(jmp_buf);

/* real function */
extern int __setjmp(jmp_buf);

extern _Noreturn void longjmp(jmp_buf);

#if defined(_BSD_SOURCE) && \
   !defined(_GNU_SOURCE) && \
   !defined(_SVID_SOURCE) && \
   !defined(_POSIX_SOURCE) && \
   !defined(_XOPEN_SOURCE) && \
   !defined(_POSIX_C_SOURCE) && \
   !defined(_XOPEN_SOURCE_EXTENDED)
# define setjmp(sigjmp_buf) __sigsetjmp(sigjmp_buf)
#else
# define setjmp(jmp_buf) __setjmp(jmp_buf)
#endif

__END_DECLS

#endif
