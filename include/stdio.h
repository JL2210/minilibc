#ifndef _STDIO_H
#define _STDIO_H 1

#include <features.h>
#include <sys/types.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BUFSIZ (512)
#ifndef EOF
# define EOF (-1)
#endif
#define _IONBF (0)
#define _IOFBF (1|__STDIO_BUFFERED)
#define _IOLBF ((1<<1)|__STDIO_BUFFERED)
#define __STDIO_BUFFERED (1<<2)
#define __IO_BF_MASK (~(__STDIO_BUFFERED-1))
#define SEEK_SET (-1)
#define SEEK_CUR (0)
#define SEEK_END (1)

#if !defined(va_copy) && defined(__va_copy)
# define va_copy __va_copy
#endif

typedef struct
{
    off_t offset;
} fpos_t;

struct _IO_FILE
{
    int fd;
    int flags;
    char *buffer;
    struct {
        size_t orig;
        size_t size;
        size_t written;
    } bufsiz;
    fpos_t fpos;
};

typedef struct _IO_FILE FILE;

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

extern int puts(const char *);
extern int fputs(const char *, FILE *);
extern int printf(const char *, ...);
extern int fprintf(FILE *, const char *, ...);
extern int vprintf(const char *, va_list);
extern int vfprintf(FILE *, const char *, va_list);
extern int sprintf(char *, const char *, ...);
extern int snprintf(char *, size_t, const char *, ...);
extern int vsprintf(char *, const char *, va_list);
extern int vsnprintf(char *, size_t, const char *, va_list);
extern char *fgets(char *, int, FILE *);
#if __STDC_VERSION__ < 201112L
extern char *gets(char *);
#endif
extern int fgetc(FILE *);
extern int getchar(void);
#define getc fgetc
extern int fputc(int, FILE *);
#define putc fputc
extern int putchar(int);
extern int fileno(FILE *);
extern int setvbuf(FILE *, char *, int, size_t);
extern size_t fwrite(const void *, size_t, size_t, FILE *);
/* Parameter name intentionally included here */
extern int fflush(FILE *ostream);

#ifdef __cplusplus
}
#endif

#endif
