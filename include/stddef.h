#ifndef _STDDEF_H
#define _STDDEF_H 1

#include <features.h>

#define __need_NULL
#define __need_size_t
#define __need_wchar_t
#define __need_ptrdiff_t
#define __need_max_align_t

#include <bits/alldefs.h>

#if defined(__GNUC__)
# define offsetof(type, member) __builtin_offsetof(type, member)
#else
# define offsetof(type, member) ((size_t)((char *)&((type *)0)->member - (char *)(type *)0))
/* Possibly less portable alternative:
# define offsetof(type, member) ((size_t)&((type *)0)->member)
 */
#endif

#endif
