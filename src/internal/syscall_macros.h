#ifndef SYSCALL_MACROS_H
#define SYSCALL_MACROS_H 1

extern long (__syscall)(long, long, long, long, long, long, long);
extern long __syscall_ret(unsigned long);

/* Syscall parameter cast to long */
#define __scl(a) (long)(a)

/* Get __VA_ARGS__-like functionality from macro */
#define __EVA(...) __VA_ARGS__

/* Get only 7 arguments from list */
#define __SC7(a, b, c, d, e, f, g, ...) \
	__EVA(__scl(a), \
	      __scl(b), \
	      __scl(c), \
	      __scl(d), \
	      __scl(e), \
	      __scl(f), \
	      __scl(g))

/* Fill in the rest of the arguments with zeroes */
#define __PSZ(...) \
	__SC7(__VA_ARGS__, 0, 0, 0, 0, 0, 0, 0)

/* Wrap __syscall with __syscall_ret, so it
 * matches the behavior we've been depending
 * on. */
#define __syscall(...) \
	__syscall_ret(__syscall(__PSZ(__VA_ARGS__)))

#endif
