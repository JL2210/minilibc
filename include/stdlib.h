#ifndef _STDLIB_H
#define _STDLIB_H

/* Needed header files */
#include <features.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Exit functions */
extern int atexit(void (*)(void));
extern _Noreturn void exit(int);
extern _Noreturn void _exit(int);
#define _Exit(ret) _exit(ret)

/* Memory allocation */
extern void *calloc(size_t, size_t);
extern void *malloc(size_t);
extern void free(void *ptr);

#ifdef __cplusplus
}
#endif

#endif
