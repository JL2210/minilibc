#ifndef _STRING_H
#define _STRING_H 1

#include <features.h>

#define __need_NULL
#define __need_size_t
#define __need_locale_t

#include <bits/alldefs.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Microsoft extensions */
#define strupr __strupr
#define strlwr __strlwr
#define strrev __strrev

/* GNU extensions */
#ifdef _GNU_SOURCE
# define memmem __memmem
# define memrchr __memrchr
# define strchrnul __strchrnul
#endif

/* Inlining macros */
#define strcoll(x, y) strcmp((x), (y))
#ifdef __GNUC__
# define memset(dest, c, len) __builtin_memset(dest, c, len)
# define memcpy(dest, src, len) __builtin_memcpy(dest, src, len)
# define memchr(dest, c, len) __builtin_memchr(dest, c, len)
#endif

extern size_t strlen(const char *);
extern size_t strnlen(const char *, size_t);

extern char *strdup(const char *);
extern char *strndup(const char *, size_t);

extern char *strcpy(char *, const char *);
extern char *strncpy(char *, const char *, size_t);
extern void *(memcpy)(void *, const void *, size_t);
extern void *memmove(void *, const void *, size_t);

extern char *stpcpy(char *, const char *);

extern int strcmp(const char *, const char *);
extern int (strcoll)(const char *, const char *);
extern int strncmp(const char *, const char *, size_t);
extern int memcmp(const void *, const void *, size_t);

extern char *strchr(const char *, int);
extern void *(memchr)(const void *, int, size_t);
extern char *strrchr(const char *, int);
#ifdef _GNU_SOURCE
extern char *strchrnul(const char *, int);
extern void *memrchr(const void *, int, size_t);

extern void *memmem(const void *, size_t, const void *, size_t);
#endif
extern char *strstr(const char *, const char *);

extern char *strtok_r(char *, const char *, char **);
extern char *strtok(char *, const char *);

extern char *strncat(char *, const char *, size_t);
extern char *strcat(char *, const char *);

extern void *(memset)(void *, int, size_t);

extern char *strupr(char *);
extern char *strlwr(char *);
extern char *strrev(char *);

extern size_t strspn(const char *, const char *);
extern size_t strcspn(const char *, const char *);

extern char *strerror(int);

#ifdef __cplusplus
}
#endif

#endif
