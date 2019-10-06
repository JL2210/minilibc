#ifndef _SYS_MMAN_H
#define _SYS_MMAN_H 1

#include <features.h>

#define __need_off_t
#define __need_size_t
#define __need_mode_t

#include <bits/alldefs.h>

__BEGIN_DECLS

#define PROT_NONE      (0x0)
#define PROT_READ      (0x1)
#define PROT_WRITE     (0x2)
#define PROT_EXEC      (0x4)

#define MAP_FAILED    ((void *)-1)

#define MAP_FILE       (0x0)
#define MAP_SHARED     (0x1)
#define MAP_PRIVATE    (0x2)
#define MAP_FIXED      (0x10)
#define MAP_ANONYMOUS  (0x20)
#define MAP_ANON       MAP_ANONYMOUS

extern void *mmap(void *, size_t, int, int, int, off_t);
extern int munmap(void *, size_t);
extern int mprotect(void *, size_t, int);

__END_DECLS

#endif
