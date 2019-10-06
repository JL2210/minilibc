#include <time.h>
#include <unistd.h>

unsigned sleep(unsigned seconds)
{
    struct timespec tv;
    unsigned ret = 0;

    tv.tv_sec = seconds;
    tv.tv_nsec = 0;

    if(__nanosleep(&tv, &tv))
        ret = tv.tv_sec;

    return ret;
}
