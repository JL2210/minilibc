#ifndef _LOCALE_H
#define _LOCALE_H 1

#include <features.h>

#define __need_NULL
#define __need_lconv

#if defined(_GNU_SOURCE) || \
    defined(_BSD_SOURCE) || \
    defined(_XOPEN_SOURCE) || \
    defined(_POSIX_SOURCE) || \
    defined(_POSIX_C_SOURCE)
# define __need_locale_t
#endif

#include <bits/defs.h>

__BEGIN_DECLS

__END_DECLS

#endif
