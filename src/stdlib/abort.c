#include <stdlib.h>
#include <signal.h>

_Noreturn void abort(void)
{
    for(;;)
        raise(SIGABRT);
}
