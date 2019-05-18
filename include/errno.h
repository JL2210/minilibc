#ifndef _ERRNO_H
#define _ERRNO_H 1

#ifdef __cplusplus
extern "C" {
#endif

typedef int errno_t;

#define errno (*__get_errno())

#ifdef __cplusplus
}
#endif

#endif
