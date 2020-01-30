#ifndef _STDLIB_H
#define _STDLIB_H 1

#include <features.h>

#if defined(_GNU_SOURCE) || \
    defined(_DEFAULT_SOURCE)
# include <alloca.h>
#endif

#define __need_NULL
#define __need_div_t
#define __need_ldiv_t
#define __need_size_t
#define __need_wchar_t
#define __need___compar_fn_t

#if __STDC_VERSION__ >= 199901L
# define __need_lldiv_t
#endif

#include <bits/defs.h>

#define atoi(x) ((int)atol((x)))

#define EXIT_SUCCESS (0)
#define EXIT_FAILURE (!EXIT_SUCCESS)

#define RAND_MAX INT_MAX

__BEGIN_DECLS

extern int atexit(void (*func)(void));
extern _Noreturn void exit(int);
extern _Noreturn void _Exit(int);
extern _Noreturn void abort(void);

extern void *realloc(void *, size_t);
extern void *calloc(size_t, size_t);
extern void *malloc(size_t);
extern void free(void *);

extern div_t div(int, int);
extern ldiv_t ldiv(long, long);
#if __STDC_VERSION__ >= 199901L
extern lldiv_t lldiv(long long, long long);
#endif

extern int abs(int);
extern long labs(long);
#if __STDC_VERSION__ >= 199901L
extern long long llabs(long long);
#endif

extern int (atoi)(const char *);
extern long (atol)(const char *);
#if __STDC_VERSION__ >= 199901L
extern long long atoll(const char *);
#endif

extern long (strtol)(const char *, char **, int);
extern unsigned long (strtoul)(const char *, char **, int);
#if __STDC_VERSION__ >= 199901L
extern long long strtoll(const char *, char **, int);
extern unsigned long long strtoull(const char *, char **, int);
#endif

#if _POSIX_C_SOURCE
extern int rand_r(unsigned *);
#endif
extern int rand(void);
extern void srand(unsigned);

extern void qsort(void *, size_t, size_t, __compar_fn_t);
extern void *bsearch(const void *, const void *, size_t, size_t, __compar_fn_t);

extern char *getenv(const char *);

__END_DECLS

#endif
