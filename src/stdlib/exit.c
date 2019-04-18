#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

extern void (**__atexit_arr)(void);
extern uint8_t __atexit_ctr;

_Noreturn void exit(int ret)
{
    int ctr = 0;

    for( ctr = 0; ctr < __atexit_ctr; ctr++ )
        (__atexit_arr[ctr])();
    _exit(ret);
}
