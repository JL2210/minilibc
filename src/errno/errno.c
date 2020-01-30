#include <errno.h>
#undef errno

__attribute__((const))
int *__errno_location(void)
{
    static int errno = 0;
    return &errno;
}
