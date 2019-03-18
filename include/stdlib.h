#ifndef _STDLIB_H
#define _STDLIB_H

#include <stdnoreturn.h>
#include <stddef.h>

extern int atexit(void (*)(void));
extern _Noreturn void exit(int);
extern _Noreturn void _exit(int);
#define _Exit(ret) _exit(ret)
extern void *calloc(size_t, size_t);
extern void *malloc(size_t);
extern long _syscall(long, long, long, long, long, long, long, long);
extern long syscall(long, ...);
extern void _start(void);
extern void _init(void);
extern void _fini(void);
extern int __libc_start_main
(
int (*)(int, char**, char**),
int,
char **,
void (*)(void),
void (*)(void),
void (*)(void),
void *
);

#endif
