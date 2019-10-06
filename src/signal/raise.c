#include <signal.h>
#include <unistd.h>

int raise(int sig)
{
    return __kill(__getpid(), sig);
}
