#ifndef _SYS_MMAN_H
#define _SYS_MMAN_H 1

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PROT_NONE	0x0
#define PROT_READ	0x1
#define PROT_WRITE	(1<<1)
#define PROT_EXEC	(1<<2)

#ifdef __cplusplus
# define MAP_FAILED	-1
#else
# define MAP_FAILED	(void *)-1
#endif

#define MAP_FILE	0x0
#define MAP_SHARED	0x1
#define MAP_PRIVATE	0x2
#define MAP_FIXED	0x10
#define MAP_ANONYMOUS	0x20
#define MAP_ANON	MAP_ANONYMOUS

extern void *mmap(void *, size_t, int, int, int, off_t);
extern int munmap(void *, size_t);

#ifdef __cplusplus
}
#endif

#endif
