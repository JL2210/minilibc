#ifndef _STRINGS_H
#define _STRINGS_H 1

#include <features.h>

#define __need_size_t

#if defined(_GNU_SOURCE) || \
    defined(_BSD_SOURCE) || \
    defined(_XOPEN_SOURCE) || \
    defined(_POSIX_SOURCE) || \
    defined(_POSIX_C_SOURCE)
# define __need_locale_t
#endif

#include <bits/defs.h>

#ifdef __GNUC__
# define ffs(i) __builtin_ffs(i)
#endif

__BEGIN_DECLS

extern int strncasecmp(const char *, const char *, size_t);
extern int strcasecmp(const char *, const char *);
#if defined(_GNU_SOURCE) || \
    defined(_BSD_SOURCE) || \
    defined(_XOPEN_SOURCE) || \
    defined(_POSIX_SOURCE) || \
    defined(_POSIX_C_SOURCE)
extern int ffs(int);
#endif

__END_DECLS

#endif
