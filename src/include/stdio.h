#ifndef STDIO_H
#define STDIO_H 1

#define __need_ssize_t
#define __need_mode_t

#include "../../include/stdio.h"

#define _F_NBF _IONBF
#define _F_FBF _IOFBF
#define _F_LBF _IOLBF
#define _F_EOF 0x8
#define _F_ERR 0x10
#define _F_MASK 0x1f

#define UNGET 4096

struct _IO_FILE {
    int flags, open_flags;
    unsigned char *ungetp;
    unsigned char *base;
    unsigned char *ptr;
    unsigned char *end;
    ssize_t (*read)(FILE *, void *, size_t);
    ssize_t (*write)(FILE *, const void *, size_t);
    int (*seek)(FILE *, long, int);
    int (*close)(FILE *);
    fpos_t offset;
    int fileno;
    unsigned short unget;
    unsigned short unget_max;
};

extern ssize_t __stdio_read(FILE *, void *, size_t);
extern ssize_t __stdio_write(FILE *, const void *, size_t);
extern int __stdio_seek(FILE *, long, int);
extern int __stdio_close(FILE *);

extern int __fileno(FILE *);

extern int __sys_nerr;
extern const char *const __sys_errlist[];

#endif
