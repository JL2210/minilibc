#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static inline int open_flags(const char *_mode)
{
    int mode = 0;

    if(!strchr("rwa", *_mode))
    {
        errno = EINVAL;
        return 0;
    }

    if(strchr(_mode, '+'))
        mode |= O_RDWR;
    else if(*_mode == 'r')
        mode |= O_RDONLY;
    else
        mode |= O_WRONLY;

    if(*_mode != 'r')
    {
        mode |= O_CREAT;

        if(strchr(_mode, 'x'))
            mode |= O_EXCL;

        if(*_mode == 'w')
            mode |= O_TRUNC;
        else if(*_mode == 'a')
            mode |= O_APPEND;
    }

    return mode;
}

FILE *fopen(const char *path, const char *_mode)
{
    int mode = open_flags(_mode);
    FILE *fp;

    if(mode == 0)
        return NULL;

    fp = calloc(1, sizeof(*fp));

    if(!fp)
        return NULL;

    fp->flags = _F_NBF;
    fp->open_flags = mode;
    fp->read = __stdio_read;
    fp->write = __stdio_write;
    fp->seek = __stdio_seek;
    fp->close = __stdio_close;
    fp->fileno = __open(path, mode, 0666);

    if(fp->fileno == -1)
    {
        free(fp);
        return NULL;
    }

    return fp;
}
