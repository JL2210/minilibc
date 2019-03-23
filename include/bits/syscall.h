#ifndef _BITS_SYSCALL_H
#define _BITS_SYSCALL_H 1

#ifndef _SYS_SYSCALL_H
# error Do not include <bits/syscall.h> directly; use <sys/syscall.h> instead.
#endif

#if defined(__LP64__)
# include <bits/syscall_64.h>
#elif defined(__ILP32__)
# include <bits/syscall_x32.h>
#else
# include <bits/syscall_32.h>
#endif

#endif
