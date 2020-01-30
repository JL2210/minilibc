#include <stdio.h>
#include <errno.h>
#include <string.h>

void perror(const char *str)
{
    if( str && *str )
        printf("%s: %s\n", str, strerror(errno));
    else
        puts(strerror(errno));
}
