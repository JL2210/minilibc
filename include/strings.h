#ifndef _STRINGS_H
#define _STRINGS_H 1

#include <features.h>

#define __need_size_t
#define __need_locale_t

#include <bits/alldefs.h>

__BEGIN_DECLS

extern int strncasecmp(const char *, const char *, size_t);
extern int strcasecmp(const char *, const char *);
extern int ffs(int);

__END_DECLS

#endif
