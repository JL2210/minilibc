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
extern int fputs(const char *, FILE *);
extern int printf(const char *, ...);
extern int vprintf(const char *, va_list);
extern int vfprintf(FILE *, const char *, va_list);
extern char *fgets(char *, int, FILE *);
#if __STDC_VERSION__ < 201112L
extern char *gets(char *);
#endif
extern int fgetc(FILE *);
extern int getchar(void);
#define getc fgetc
extern int fputc(int, FILE *);
extern int putchar(int);
extern int fileno(FILE *);

#ifdef __cplusplus
}
#endif

#endif
