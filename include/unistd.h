#ifndef _UNISTD_H
#define _UNISTD_H 1

#include <features.h>
#include <sys/types.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define _POSIX_VERSION 200809L
#define _POSIX2_VERSION 200809L
#define _XOPEN_VERSION 700

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#define _environ __environ
#define environ __environ
extern char **environ;

extern _Noreturn void _exit(int);

extern long syscall(long, ...);

/* Syscalls */
extern void *sbrk(intptr_t);
extern int brk(void *);
extern ssize_t write(int, const void *, size_t);
extern ssize_t read(int, void *, size_t);
extern pid_t getpid(void);

extern int usleep(useconds_t);
extern unsigned sleep(unsigned);

#ifdef __cplusplus
}
#endif

#endif
