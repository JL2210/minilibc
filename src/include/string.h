#ifndef STRING_H
#define STRING_H 1

#include "../../include/string.h"

extern void *memmem(const void *, size_t,
                    const void *, size_t);
extern char *stpcpy(char *, const char *);
extern char *__stpcpy(char *, const char *);

#endif
