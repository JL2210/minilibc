#ifndef _STDIO_H
#define _STDIO_H 1

#include <features.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

struct _FILE
{
    int fd;
};

typedef struct _FILE FILE;

#ifndef EOF
# define EOF -1
#endif

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

extern int puts(const char *);
extern int fputs(const char *str, FILE *stream);
extern int putchar(int);
extern int printf(const char *, ...);
extern int vprintf(const char *, va_list);
extern int vfprintf(FILE *, const char *, va_list);
extern char *fgets(char *, int, FILE *);
#if __STDC_VERSION__ < 201112L
extern char *gets(char *str);
#endif
extern int fgetc(FILE *);
extern int getchar(void);
#define getc fgetc
extern int fileno(FILE *fp);

#ifdef __cplusplus
}
#endif

#endif
