#ifndef _STRING_H
#define _STRING_H 1

#include <features.h>

#define __need_NULL
#define __need_size_t
#define __need_locale_t

#include <bits/alldefs.h>

#ifdef __GNUC__
# define strlen(str) __builtin_strlen(str)
# define memset(dest, c, len) __builtin_memset(dest, c, len)
# define memcpy(dest, src, len) __builtin_memcpy(dest, src, len)
# define memchr(dest, c, len) __builtin_memchr(dest, c, len)
# define ffsl(l) __builtin_ffsl(l)
# define ffsll(l) __builtin_ffsll(l)
#endif

__BEGIN_DECLS

extern size_t (strlen)(const char *);
extern size_t strnlen(const char *, size_t);

extern char *strdup(const char *);
extern char *strndup(const char *, size_t);

extern char *strcpy(char *, const char *);
extern char *strncpy(char *, const char *, size_t);
extern void *(memcpy)(void *, const void *, size_t);
extern void *memmove(void *, const void *, size_t);

#if _POSIX_C_SOURCE >= 200809L
extern char *stpcpy(char *, const char *);
#endif

extern int strcmp(const char *, const char *);
extern int strcoll(const char *, const char *);
extern int strncmp(const char *, const char *, size_t);
extern int memcmp(const void *, const void *, size_t);

extern char *strchr(const char *, int);
extern void *(memchr)(const void *, int, size_t);
extern char *strrchr(const char *, int);
#ifdef _GNU_SOURCE
extern char *strchrnul(const char *, int);
extern void *memrchr(const void *, int, size_t);
extern void *rawmemchr(const void *, int);

extern void *memmem(const void *, size_t, const void *, size_t);
#endif
extern char *strstr(const char *, const char *);

extern char *strtok_r(char *, const char *, char **);
extern char *strtok(char *, const char *);

extern char *strncat(char *, const char *, size_t);
extern char *strcat(char *, const char *);

extern void *(memset)(void *, int, size_t);

extern size_t strspn(const char *, const char *);
extern size_t strcspn(const char *, const char *);

extern char *strerror(int);

#ifdef _DEFAULT_SOURCE
extern int ffsl(long);
# if __STDC_VERSION__ >= 199901L
extern int ffsll(long long);
# endif
#endif

__END_DECLS

#endif
