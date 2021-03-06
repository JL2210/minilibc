#ifndef _UNISTD_H
#define _UNISTD_H 1

#include <features.h>
#include <bits/whence.h>

#define __need_NULL
#define __need_uid_t
#define __need_gid_t
#define __need_off_t
#define __need_pid_t
#define __need_size_t
#define __need_ssize_t
#define __need_intptr_t
#define __need_useconds_t

#include <bits/defs.h>

__BEGIN_DECLS

#define _POSIX_VERSION 200809L
#define _POSIX2_VERSION 200809L
#define _XOPEN_VERSION 700

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#ifdef _GNU_SOURCE
extern char **_environ;
extern char **environ;
extern long syscall(long, ...);
#endif

extern _Noreturn void _exit(int);

/* Syscalls */
extern void *sbrk(intptr_t);
extern int brk(void *);
extern ssize_t write(int, const void *, size_t);
extern ssize_t read(int, void *, size_t);
extern pid_t getpid(void);
extern pid_t fork(void);
extern int fsync(int);
extern int close(int);
extern off_t lseek(int, off_t, int);

extern int usleep(useconds_t);
extern unsigned sleep(unsigned);

__END_DECLS

#endif
