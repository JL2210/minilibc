#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static inline int open_flags(const char *_mode)
{
    int mode = O_LARGEFILE;

    if(!strchr("rwa", *_mode))
    {
        errno = EINVAL;
        return -1;
    }

    if(strchr(_mode, '+')) mode |= O_RDWR;
    else if(*_mode == 'r') mode |= O_RDONLY;
    else mode |= O_WRONLY;

    if(strchr(_mode, 'x')) mode |= O_EXCL;

    if(*_mode != 'r')
    {
        mode |= O_CREAT;
        if(*_mode == 'w')
        {
            if(strchr(_mode, 'x')) mode |= O_EXCL;
            mode |= O_TRUNC;
        }
        else if(*_mode == 'a') mode |= O_APPEND;
    }

    return mode;
}

FILE *fopen(const char *path, const char *_mode)
{
    int mode;
    FILE *fp;

    mode = open_flags(_mode);
    fp = (FILE *)malloc(sizeof(*fp));

    memset(fp, 0, sizeof(*fp));
    fp->flags |= _IONBF;

    fp->fd = open(path, mode);

    if(fp->fd == -1) return NULL;

    return fp;
}
