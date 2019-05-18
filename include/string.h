#ifndef _STRING_H
#define _STRING_H 1

#include <features.h>

#ifdef __cplusplus
extern "C" {
#endif

extern size_t strlen(const char *);
extern char *strcpy(char *, const char *);
extern char *strchr(const char *s, int c);
extern char *strncpy(char *, const char *, size_t);
extern void *memset(void *, int, size_t);
extern void *memchr(const void *ptr, int c, size_t len);
extern void *memcpy(void *, const void *, size_t);
extern long long strtoll(char *str, char **endptr, int base);
extern unsigned long long strtoull(char *str, char **endptr, int base);
extern long strtol(char *str, char **endptr, int base);
extern unsigned long strtoul(char *str, char **endptr, int base);

#ifdef __cplusplus
}
#endif

#endif
