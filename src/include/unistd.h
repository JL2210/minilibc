#ifndef UNISTD_H
#define UNISTD_H 1

#include "../../include/unistd.h"

extern int __unlink(const char *);
extern int __unlinkat(int, const char *, int);

extern long __syscall(long, ...);

extern char **__environ;

extern pid_t __getpid(void);

extern ssize_t __read(int, void *, size_t);
extern ssize_t __write(int, const void *, size_t);
extern off_t __lseek(int, off_t, int);
extern int __close(int);
extern int __fsync(int);

extern int __brk(void *);
extern void *__sbrk(intptr_t);

#endif
