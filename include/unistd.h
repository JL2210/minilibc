#ifndef _UNISTD_H
#define _UNISTD_H 1

#include <sys/types.h>
#include <bits/unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

#define environ __environ
extern char **environ;

extern _Noreturn void _exit(int);

extern intptr_t syscall(intptr_t, ...);

extern void *sbrk(intptr_t);
extern int brk(void *);
extern ssize_t write(int, const void *, int);

#ifdef __cplusplus
}
#endif

#endif
