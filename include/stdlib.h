#ifndef _STDLIB_H
#define _STDLIB_H

/* Needed header files */
#include <stdnoreturn.h>
#include <stddef.h>
#include <elf.h>

/* Global variables */
extern char **__environ;
extern Elf_auxv_t *__auxv;

/* Exit functions */
extern void (*atexit_arr[])(void);
extern uint8_t atexit_ctr;
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
extern void _init(void);
extern void _fini(void);
extern int __libc_start_main
(
int (*)(int, char**, char**),
int,
char **
);

#endif
