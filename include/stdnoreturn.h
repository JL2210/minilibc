#ifndef _STDNORETURN_H
#define _STDNORETURN_H 1

#include <features.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __cplusplus
# define noreturn _Noreturn
#endif

#ifdef __cplusplus
}
#endif

#endif
