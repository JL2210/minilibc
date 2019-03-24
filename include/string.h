#ifndef _STRING_H
#define _STRING_H 1

#include <stddef.h>

extern size_t strlen(char *);
extern char *strcpy(char *, char *);
extern char *strncpy(char *, char *, size_t);
extern void *memset(void *, int, size_t);
extern void *memcpy(void *, void *, size_t);

#endif
