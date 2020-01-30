#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

ssize_t __stdio_read(FILE *fp, void *buf, size_t sz)
{
    return __read(fp->fileno, buf, sz);
}

ssize_t __stdio_write(FILE *fp, const void *buf, size_t sz)
{
    return __write(fp->fileno, buf, sz);
}

int __stdio_seek(FILE *fp, long offset, int whence)
{
    off_t result = __lseek(fp->fileno, offset, whence);

    if(result >= 0)
        fp->offset.__ll = result;

    return result >= 0 ? 0 : -1;
}

int __stdio_close(FILE *fp)
{
    return __close(fp->fileno);
}

static unsigned char stdin_buf[UNGET + BUFSIZ];
static unsigned char stdout_buf[BUFSIZ];

static FILE __stdin =
{
    _F_FBF, /* flags */
    O_RDONLY, /* open_flags */
    stdin_buf, /* ungetp */
    stdin_buf + UNGET, /* base */
    stdin_buf + UNGET, /* ptr */
    stdin_buf + sizeof(stdin_buf), /* end */
    __stdio_read, /* read */
    __stdio_write, /* write */
    __stdio_seek, /* seek */
    __stdio_close, /* close */
    { 0 }, /* offset */
    STDIN_FILENO, /* fileno */
    0, /* unget */
    UNGET /* unget_max */
};
static FILE __stdout =
{
    _F_LBF, /* flags */
    O_WRONLY, /* open_flags */
    stdout_buf, /* ungetp */
    stdout_buf, /* base */
    stdout_buf, /* ptr */
    stdout_buf + sizeof(stdout_buf), /* end */
    __stdio_read, /* read */
    __stdio_write, /* write */
    __stdio_seek, /* seek */
    __stdio_close, /* close */
    { 0 }, /* offset */
    STDOUT_FILENO, /* fileno */
    0, /* unget */
    0 /* unget_max */
};
static FILE __stderr =
{
    _F_NBF, /* flags */
    O_WRONLY, /* open_flags */
    NULL, /* ungetp */
    NULL, /* base */
    NULL, /* ptr */
    NULL, /* end */
    __stdio_read, /* read */
    __stdio_write, /* write */
    __stdio_seek, /* seek */
    __stdio_close, /* close */
    { 0 }, /* offset */
    STDERR_FILENO, /* fileno */
    0, /* unget */
    0 /* unget_max */
};

FILE *const stdin = &__stdin;
FILE *const stdout = &__stdout;
FILE *const stderr = &__stderr;
