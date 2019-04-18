#ifndef _UNISTD_H
#define _UNISTD_H 1

#include <features.h>
#include <sys/types.h>
#include <bits/unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#define __environ environ
#define _environ environ
extern char **environ;

extern _Noreturn void _exit(int);

extern intptr_t syscall(intptr_t, ...);

extern void *sbrk(intptr_t);
extern int brk(void *);
extern ssize_t write(int, const void *, size_t);
extern ssize_t read(int, void *, size_t);

#ifdef __cplusplus
}
#endif

#endif
