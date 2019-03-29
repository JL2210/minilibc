#ifndef _SYS_MMAN_H
#define _SYS_MMAN_H 1

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PROT_NONE	0
#define PROT_READ	1
#define PROT_WRITE	(1<<1)
#define PROT_EXEC	(1<<2)

extern void *mmap(void *, size_t, int, int, int, off_t);
extern int munmap(void *, size_t);

#ifdef __cplusplus
}
#endif

#endif
