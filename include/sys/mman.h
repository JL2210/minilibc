#ifndef _SYS_MMAN_H
#define _SYS_MMAN_H 1

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);

#ifdef __cplusplus
}
#endif

#endif
