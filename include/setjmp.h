#ifndef _SETJMP_H
#define _SETJMP_H 1

#include <features.h>
#include <bits/setjmp.h>

#define __need_jmp_buf
#define __need_sigjmp_buf

#include <bits/alldefs.h>

__BEGIN_DECLS

extern int setjmp(jmp_buf);
extern _Noreturn void longjmp(jmp_buf, int);
extern int _setjmp(jmp_buf);
extern _Noreturn void _longjmp(jmp_buf, int);
extern int sigsetjmp(sigjmp_buf);
extern _Noreturn void siglongjmp(sigjmp_buf, int);

#if defined(_BSD_SOURCE)
# define setjmp sigsetjmp
# define longjmp siglongjmp
#endif

__END_DECLS

#endif
