#ifndef ERRNO_H
#define ERRNO_H 1

#include_next <errno.h>

extern const char *__program_invocation_name, *__program_invocation_short_name;

extern const int __sys_nerr;
extern const char *const __sys_errlist[];

#endif
