#include <time.h>
#include <unistd.h>

int usleep(useconds_t us)
{
    struct timespec tv;

    tv.tv_sec = us / 1000000;
    tv.tv_nsec = (us % 1000000) * 1000;

    return nanosleep(&tv, &tv);
}
