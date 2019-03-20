#ifndef _STDLIB_H
#define _STDLIB_H

/* Needed header files */
#include <stdnoreturn.h>
#include <stddef.h>
#include <elf.h>

/* Global variables */
extern char **__environ;
extern size_t __hwcap;
extern size_t __sysinfo;
#define _environ __environ
#define environ __environ

/* Exit functions */
#if 1
extern void (*atexit_arr[])(void);
extern uint8_t atexit_ctr;
#endif
extern int atexit(void (*)(void));
extern _Noreturn void exit(int);
extern _Noreturn void _exit(int);
#define _Exit(ret) _exit(ret)

/* Memory allocation */
extern void *calloc(size_t, size_t);
extern void *malloc(size_t);

/* Syscall functions/wrappers */
extern intptr_t syscall(intptr_t, ...);

/* Program startup */
extern void _start(void);
extern void _start_c(intptr_t *);
extern void _init(void);
extern void _fini(void);
extern int __libc_start_main
(
int (*)(int, char**, char**),
int,
char **
);

#endif
