#ifndef _STDIO_H
#define _STDIO_H 1

#include <features.h>
#include <bits/whence.h>

#define __need_EOF
#define __need_NULL
#define __need_FILE
#define __need_fpos_t
#define __need_size_t
#define __need___va_list

#if defined(_GNU_SOURCE) || \
    defined(_BSD_SOURCE) || \
    defined(_XOPEN_SOURCE) || \
    defined(_POSIX_SOURCE) || \
    defined(_POSIX_C_SOURCE)
# define __need_off_t
# define __need_ssize_t
# define __need_va_list
#endif

#include <bits/defs.h>

#define BUFSIZ 0x400

#define _IONBF 0x1
#define _IOFBF 0x2
#define _IOLBF 0x4

__BEGIN_DECLS

#if defined(_GNU_SOURCE)
extern int _sys_nerr;
extern const char *const _sys_errlist[];
#elif defined(_DEFAULT_SOURCE)
extern int sys_nerr;
extern const char *const sys_errlist[];
#endif

extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;

extern int printf(const char *, ...);
extern int fprintf(FILE *, const char *, ...);
extern int vprintf(const char *, __va_list);
extern int vfprintf(FILE *, const char *, __va_list);
extern int sprintf(char *, const char *, ...);
extern int snprintf(char *, size_t, const char *, ...);
extern int vsprintf(char *, const char *, __va_list);
extern int vsnprintf(char *, size_t, const char *, __va_list);

extern char *fgets(char *, int, FILE *);
#if __STDC_VERSION__ < 201112L
__attribute__((__deprecated__))
extern char *gets(char *);
#endif
extern int fgetc(FILE *);
extern int getc(FILE *);
extern int ungetc(int, FILE *);
extern int getchar(void);
#define getc(fp) fgetc(fp)

extern int fputs(const char *, FILE *);
extern int puts(const char *);
extern int fputc(int, FILE *);
extern int putchar(int);
extern int putc(int, FILE *);
#define putc(c, fp) fputc(c, fp)

extern FILE *fopen(const char *, const char *);
extern int fclose(FILE *);
extern int ferror(FILE *);
extern int feof(FILE *);
extern void clearerr(FILE *);

extern int setvbuf(FILE *, char *, int, size_t);

extern size_t fread(void *restrict, size_t, size_t, FILE *);
extern size_t fwrite(const void *restrict, size_t, size_t, FILE *);
extern int fseek(FILE *, long, int);
extern long ftell(FILE *);
extern int fflush(FILE *);
extern void rewind(FILE *);

extern void perror(const char *);

#if defined(_GNU_SOURCE) || \
    defined(_BSD_SOURCE) || \
    defined(_XOPEN_SOURCE) || \
    defined(_POSIX_SOURCE) || \
    defined(_POSIX_C_SOURCE)
extern int fileno(FILE *);
#endif

__END_DECLS

#endif
