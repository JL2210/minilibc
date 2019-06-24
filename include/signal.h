#ifndef _SIGNAL_H
#define _SIGNAL_H 1

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int raise(int);
extern int kill(pid_t, int);

#define SIGHUP 1
#define SIGINT 2
#define SIGQUIT 3
#define SIGILL 4
#define SIGTRAP 5
#define SIGABRT 6

#ifdef __cplusplus
}
#endif

#endif
