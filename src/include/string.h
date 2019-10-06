#ifndef STRING_H
#define STRING_H 1

#include_next <string.h>

void *memmem(const void *, size_t,
             const void *, size_t);

#endif
