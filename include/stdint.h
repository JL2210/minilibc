#ifndef _STDINT_H
#define _STDINT_H 1

#include <features.h>

#define __need_int8_t
#define __need_int16_t
#define __need_int32_t
#define __need_int64_t
#define __need_uint8_t
#define __need_intptr_t
#define __need_intmax_t
#define __need_uint16_t
#define __need_uint32_t
#define __need_uint64_t
#define __need_uintptr_t
#define __need_uintmax_t

#include <bits/alldefs.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef UINT8_MAX
# ifdef __UINT8_MAX__
#  define UINT8_MAX __UINT8_MAX__
# else
#  define UINT8_MAX ((uint8_t)-1)
# endif
#endif

#ifndef UINTPTR_MAX
# ifdef __UINTPTR_MAX__
#  define UINTPTR_MAX __UINTPTR_MAX__
# else
#  define UINTPTR_MAX ((uintptr_t)-1)
# endif
#endif

#ifndef INTPTR_MAX
# ifdef __INTPTR_MAX__
#  define INTPTR_MAX __INTPTR_MAX__
# else
#  define INTPTR_MAX (((uintptr_t)-1)/2)
# endif
#endif

#ifndef SIZE_MAX
# ifdef __SIZE_MAX__
#  define SIZE_MAX __SIZE_MAX__
# else
#  define SIZE_MAX ((size_t)-1)
# endif
#endif

#ifdef __cplusplus
}
#endif

#endif
