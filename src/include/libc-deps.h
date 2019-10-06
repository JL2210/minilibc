#ifdef __GNUC__
# define mul_overflow(a, b, z) __builtin_mul_overflow(a, b, &z)
# define likely(x) __builtin_expect(!!(x), 1)
# define unlikely(x) __builtin_expect(!!(x), 0)
#else
# define mul_overflow(a, b, z) \
( \
    (z) = (a) * (b), \
    ((a) && ((z) / (a) != (b))) \
)
# define likely(x) (x)
# define unlikely(x) (x)
#endif

#ifdef _WIN32
# define UP(name) "_" name
#else
# define UP(name) name
#endif

/* TODO: Write a version of this macro what doesn't depend
 *       on compiler extensions.
 */
#if defined(__GNUC__) || defined(__TINYC__)
# define weak_alias(name, alias) \
    extern __typeof__(name) alias __attribute__((__weak__, __alias__(UP(#name))))
#endif
