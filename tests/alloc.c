#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    size_t *len = NULL;
    int ctr = 0;
    char **buf = NULL;
    len = calloc(argc, sizeof(*len));
    buf = calloc(argc, sizeof(*buf));
    while( ctr < argc )
    {
        len[ctr] = strlen(argv[ctr]) + 1;
        buf[ctr] = malloc(len[ctr]);
        if( buf[ctr] == NULL )
        {
            puts("Error: Unable to allocate memory");
            exit(1);
        }
        memset(buf[ctr], 0, len[ctr]);
        strcpy(buf[ctr], argv[ctr]);
        puts(buf[ctr]);
        ctr++;
    }
    return 0;
}
