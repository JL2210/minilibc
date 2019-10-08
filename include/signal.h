#ifndef _SIGNAL_H
#define _SIGNAL_H 1

#include <features.h>
#include <bits/signal.h>

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

__END_DECLS

#endif
