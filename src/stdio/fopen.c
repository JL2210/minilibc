#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

static inline int open_flags(const char *_mode)
{
    int mode = 0;

    if(!strchr("rwa", *_mode))
    {
        errno = EINVAL;
        return -1;
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
    FILE *fp = malloc(sizeof(*fp));

    if( mode == -1 || !fp )
        return NULL;

    fp->open_flags = mode;

    if( (mode & O_RDWR) || (mode & O_RDONLY) )
    {
        fp->ungetp = malloc(UNGET + BUFSIZ);
        fp->unget_max = UNGET;
        fp->flags = _F_FBF;
    }
    else
    {
        fp->ungetp = malloc(BUFSIZ);
        fp->unget_max = 0;
        fp->flags = _F_LBF;
    }

    if(!fp->ungetp)
        goto cleanup;

    fp->base = fp->ptr = fp->ungetp + fp->unget_max;
    fp->end = fp->base + BUFSIZ;
    fp->read = __stdio_read;
    fp->write = __stdio_write;
    fp->seek = __stdio_seek;
    fp->close = __stdio_close;
    memset(&fp->offset, 0, sizeof(fp->offset));
    fp->unget = 0;

    fp->fileno = __open(path, mode, 0666);
    if(fp->fileno == -1)
    {
        free(fp->ungetp);
        goto cleanup;
    }

    return fp;
cleanup:
    free(fp);
    return NULL;
}
