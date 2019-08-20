#ifndef _STRINGS_H
#define _STRINGS_H 1

#include <features.h>

#define __need_size_t
#define __need_locale_t

#include <bits/alldefs.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int strncasecmp(const char *, const char *, size_t);
extern int strcasecmp(const char *, const char *);

#ifdef __cplusplus
}
#endif

#endif
