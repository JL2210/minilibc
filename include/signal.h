#ifndef _SIGNAL_H
#define _SIGNAL_H 1

#include <features.h>

#define __need_pid_t
#define __need_uid_t
#define __need_size_t
#define __need_time_t
#define __need_sigval
#define __need_SIG_DFL
#define __need_SIG_IGN
#define __need_SIG_ERR
#define __need_timespec
#define __need_pthread_t
#define __need_sig_atomic_t
#define __need___sighandler_t

#include <bits/alldefs.h>

__BEGIN_DECLS

extern int raise(int);
extern int kill(pid_t, int);

#define SIG_DFL ((__sighandler_t)0)
#define SIG_IGN ((__sighandler_t)1)
#define SIG_ERR ((__sighandler_t)-1)

#define SIGHUP  1
#define SIGINT  2
#define SIGQUIT 3
#define SIGILL  4
#define SIGTRAP 5
#define SIGABRT 6

__END_DECLS

#endif
