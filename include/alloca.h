#ifndef _ALLOCA_H
#define _ALLOCA_H 1

#include <features.h>

#define __need_size_t

#include <bits/alldefs.h>

#ifdef __GNUC__
# define alloca(size) __builtin_alloca(size)
#endif

__BEGIN_DECLS

void *alloca(size_t size);

__END_DECLS

#endif
