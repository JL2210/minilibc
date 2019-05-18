#include <errno.h>
#undef errno

errno_t errno = 0;
errno_t *__get_errno(void)
{
        return &errno;
}
