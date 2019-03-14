#ifndef _STDLIB_H
#define _STDLIB_H

#include <stdnoreturn.h>

extern int atexit(void (*func)(void));
extern _Noreturn void exit(int ret);
extern _Noreturn void _exit(int ret);
#define _Exit(ret) _exit(ret)
extern void _start(void);
extern void _init(void);
extern void _fini(void);
extern int __libc_start_main
(
int (*)(int, char**, char**),
int,
char **,
void (*_init)(void),
void (*_fini)(void),
void (*rtld_fini)(void),
void *
);

#endif
