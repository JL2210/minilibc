#ifndef ATEXIT_H
#define ATEXIT_H 1

#include <stdint.h>

#define MIN_ATEXIT_MAX 32

typedef void (*atexit_func)(void);

struct atexit {
        struct atexit *prev;
        atexit_func func[MIN_ATEXIT_MAX];
        uint8_t ctr;
        struct atexit *next;
};

int __register_atexit_func(struct atexit **, atexit_func);
int __call_atexit_funcs(struct atexit *);

#endif
