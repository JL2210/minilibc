#ifndef _ERRNO_H
#define _ERRNO_H 1

#include <features.h>
#include <bits/errno.h>

#define errno (*__errno_location())

__BEGIN_DECLS

extern int *__errno_location(void);

#ifdef _GNU_SOURCE
extern const char *program_invocation_name, *program_invocation_short_name;
#endif

#ifdef _DEFAULT_SOURCE
extern const int sys_nerr;
extern const char *const sys_errlist[];
#endif

__END_DECLS

#endif
