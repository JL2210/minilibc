#ifndef _STDLIB_H
#define _STDLIB_H

#include <features.h>
#include <stddef.h>
#include <limits.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Defined symbols */
#define ulltoa __ulltoa
#define nulltoa __nulltoa
#define lltoa __lltoa
#define nlltoa __nlltoa

/* Macros */
#define ultoa ulltoa
#define nultoa nulltoa
#define ltoa lltoa
#define nltoa nlltoa
#define utoa ulltoa
#define nutoa nulltoa
#define itoa lltoa
#define nitoa nlltoa
#define atoi(x) ((int)atoll(x))
#define atol(x) ((long)atoll(x))
#define strtoull(x,y,z) strtoll(x,y,z)
#define strtoul(x,y,z) strtoll(x,y,z)
#define strtol(x,y,z) strtoll(x,y,z)

#define RAND_MAX INT_MAX
#define EXIT_FAILURE (1)
#define EXIT_SUCCESS (0)

extern int atexit(void (*)(void));
extern _Noreturn void exit(int);
extern _Noreturn void _Exit(int);
extern _Noreturn void abort(void);

extern void *realloc(void *, size_t);
extern void *calloc(size_t, size_t);
extern void *malloc(size_t);
extern void free(void *);

__extension__ extern long long strtoll(const char *, char **, int);
__extension__ extern unsigned long long (strtoull)(const char *, char **, int);
extern long (strtol)(const char *, char **, int);
extern unsigned long (strtoul)(const char *, char **, int);

extern double strtod(const char *, char **);

__extension__ extern long long atoll(const char *);
extern long (atol)(const char *str);
extern int (atoi)(const char *str);

__extension__ extern char *ulltoa(unsigned long long, char *, int);
__extension__ extern size_t nulltoa(unsigned long long, int);
__extension__ extern char *lltoa(long long, char *, int);
__extension__ extern size_t nlltoa(long long, int);

extern int rand_r(unsigned *);
extern int rand(void);
extern void srand(unsigned);

#ifdef __cplusplus
}
#endif

#endif
