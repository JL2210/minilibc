#ifndef _BITS_SIGNAL_H
#define _BITS_SIGNAL_H 1

#define SIG_DFL ((__sighandler_t)0)
#define SIG_IGN ((__sighandler_t)1)
#define SIG_HOLD ((__sighandler_t)5)
#define SIG_ERR ((__sighandler_t)-1)

#define SIGHUP  1
#define SIGINT  2
#define SIGQUIT 3
#define SIGILL  4
#define SIGTRAP 5
#define SIGABRT 6

#endif
