#ifndef _BITS_SYSCALL_H
#define _BITS_SYSCALL_H 1

#ifndef _SYSCALL_H
# error "Never include <bits/syscall.h> directly; use <sys/syscall.h> instead."
#endif

#ifdef __x86_64__
# if defined(_ILP32) || defined(__ILP32__)
#  include <bits/syscall_x32.h>
# else
#  include <bits/syscall_64.h>
# endif
#elif defined(__i386) || defined(__i386__)
# include <bits/syscall_32.h>
#endif

#endif
