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

#include <bits/alldefs.h>

#define atoi(x) ((int)atol((x)))

#define EXIT_SUCCESS (0)
#define EXIT_FAILURE (!EXIT_SUCCESS)

#ifdef __INT_MAX__
# define RAND_MAX __INT_MAX__
#else
# define RAND_MAX (((unsigned)-1)/2)
#endif

__BEGIN_DECLS

extern int atexit(void (*)(void));
extern _Noreturn void exit(int);
extern _Noreturn void _Exit(int);
extern _Noreturn void abort(void);

extern void *realloc(void *, size_t);
extern void *calloc(size_t, size_t);
extern void *malloc(size_t);
extern void free(void *);

extern int (atoi)(const char *str);
extern long (atol)(const char *str);
#if __STDC_VERSION__ >= 199901L
extern long long atoll(const char *);

extern long long strtoll(const char *, char **, int);
extern unsigned long long strtoull(const char *, char **, int);
#endif
extern long (strtol)(const char *, char **, int);
extern unsigned long (strtoul)(const char *, char **, int);

#if _POSIX_C_SOURCE >= 1 || _XOPEN_SOURCE || _POSIX_SOURCE
extern int rand_r(unsigned *);
#endif
extern int rand(void);
extern void srand(unsigned);

extern void qsort(void *, size_t, size_t, __compar_fn_t);
extern void *bsearch(const void *, const void *, size_t, size_t, __compar_fn_t);

extern char *getenv(const char *);

__END_DECLS

#endif
