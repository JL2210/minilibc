#ifndef _UNISTD_H
#define _UNISTD_H 1

#include <sys/types.h>
#include <bits/unistd.h>

extern char **__environ;

extern _Noreturn void _exit(int);

extern intptr_t syscall(intptr_t, ...);

extern void *sbrk(intptr_t);
extern intptr_t brk(void *);

#endif