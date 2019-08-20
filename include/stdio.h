#ifndef _STDIO_H
#define _STDIO_H 1

#include <features.h>

#define __need_NULL
#define __need_FILE
#define __need_off_t
#define __need_fpos_t
#define __need_size_t
#define __need_ssize_t
#define __need_SEEK_SET
#define __need_SEEK_CUR
#define __need_SEEK_END

#include <bits/alldefs.h>

#ifndef __GNUC__
# include <stdarg.h>
#else
typedef __builtin_va_list va_list;
#endif

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
#define __STDIO_EOF (1<<3)

#if !defined(va_copy) && defined(__va_copy)
# define va_copy __va_copy
#endif

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

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

extern int fputs(const char *, FILE *);
extern int puts(const char *);
extern int fputc(int, FILE *);
#define putc fputc
extern int putchar(int);


extern FILE *fopen(const char *, const char *);
extern int ferror(FILE *);
extern int feof(FILE *);
extern void clearerr(FILE *);

extern int fileno(FILE *);
extern int setvbuf(FILE *, char *, int, size_t);
extern size_t fwrite(const void *, size_t, size_t, FILE *);
extern void perror(const char *);
/* Parameter name intentionally included here */
extern int fflush(FILE *ostream);

#ifdef __cplusplus
}
#endif

#endif
