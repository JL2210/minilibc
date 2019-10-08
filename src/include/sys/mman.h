#ifndef SYS_MMAN_H
#define SYS_MMAN_H 1

#include "../../../include/sys/mman.h"

void *__mmap(void *, size_t, int, int, int, off_t);
int __mprotect(void *, size_t, int);
int __munmap(void *, size_t);

#endif
