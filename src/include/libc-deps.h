#ifdef __GNUC__
# define umull_overflow(a, b, z) __builtin_umull_overflow(a, b, z)
# define likely(x) __builtin_expect(!!(x), 1)
# define unlikely(x) __builtin_expect(!!(x), 0)
#else
# define umull_overflow(a, b, z) \
( \
    *(z) = (a) * (b), \
    ((a) && (*(z) / (a) != (b))) \
)
# define likely(x) (x)
# define unlikely(x) (x)
#endif

/* TODO: Write a version of this macro what doesn't depend
 *       on compiler extensions.
 */
#if defined(__GNUC__) || defined(__TINYC__)
# define weak_alias(name, alias) \
    extern __typeof__(name) alias __attribute__((__weak__, __alias__(#name)))
#endif
