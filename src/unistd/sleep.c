#include <unistd.h>
#include <time.h>

unsigned sleep(unsigned seconds)
{
    struct timespec tv;
    unsigned ret = 0;

    tv.tv_sec = seconds;
    tv.tv_nsec = 0;

    if(nanosleep(&tv, &tv))
        ret = tv.tv_sec;

    return ret;
}
