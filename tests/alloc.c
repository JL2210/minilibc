#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    size_t *len = NULL;
    int ctr = 0;
    char **buf = NULL;
    len = (size_t *)calloc(argc, sizeof(size_t));
    buf = (char **)calloc(argc, sizeof(char *));
    while( ctr < argc )
    {
        len[ctr] = strlen(argv[ctr]) + 1;
        buf[ctr] = (char *)malloc(len[ctr]);
        if( buf[ctr] == NULL )
        {
            puts("Error: Unable to allocate memory");
            exit(1);
        }
        memset(buf[ctr], 0, len[ctr]);
        strncpy(buf[ctr], argv[ctr], len[ctr]);
        puts(buf[ctr]);
        sbrk(-len[ctr]);
        ctr++;
    }
    return 0;
}
