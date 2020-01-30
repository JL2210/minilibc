#ifndef _FCNTL_H
#define _FCNTL_H 1

#include <features.h>
#include <bits/fcntl.h>

#define __need_off_t
#define __need_pid_t
#define __need_mode_t

#include <bits/defs.h>

__BEGIN_DECLS

extern int open(const char *, int, ...);
extern int openat(int, const char *, int, ...);

__END_DECLS

#endif
