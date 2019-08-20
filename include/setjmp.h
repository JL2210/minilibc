#ifndef _SETJMP_H
#define _SETJMP_H 1

#include <features.h>
#include <bits/setjmp.h>

#define __need_jmp_buf

#include <bits/alldefs.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int setjmp(jmp_buf);
extern _Noreturn void longjmp(jmp_buf, int);

#ifdef __cplusplus
}
#endif

#endif
