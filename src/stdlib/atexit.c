#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

void (**__atexit_arr)(void) = NULL;
uint8_t __atexit_ctr = 0;

int atexit(void (*func)(void))
{
    __atexit_arr = realloc(__atexit_arr, __atexit_ctr*sizeof(*__atexit_arr));
    __atexit_arr[__atexit_ctr++] = func;
    return 0;
}
