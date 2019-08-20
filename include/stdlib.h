#ifndef _STDLIB_H
#define _STDLIB_H 1

#include <features.h>

#define __need_NULL
#define __need_size_t
#define __need_wchar_t
#define __need___compar_fn_t

#include <bits/alldefs.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Macros */
#define atoi(x) ((int)atoll((x)))
#define atol(x) ((long)atoll((x)))
#define strtoull(x, y, z) strtoll((x), (y), (z))
#define strtoul(x, y, z) strtoll((x), (y), (z))
#define strtol(x, y, z) strtoll((x), (y), (z))

#define EXIT_SUCCESS (0)
#define EXIT_FAILURE (!EXIT_SUCCESS)

#ifdef __INT_MAX__
# define RAND_MAX __INT_MAX__
#else
# define RAND_MAX (((unsigned)-1)/2)
#endif

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

extern int rand_r(unsigned *);
extern int rand(void);
extern void srand(unsigned);

extern void qsort(void *, size_t, size_t, __compar_fn_t);

extern char *getenv(const char *);

#ifdef __cplusplus
}
#endif

#endif
