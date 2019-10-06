#include <features.h>

#undef assert
#undef __assert_func_name__

#ifdef __GNUG__
# define __assert_func_name__ __PRETTY_FUNCTION__
#else
# if __STDC_VERSION__ >= 199901L
#  define __assert_func_name__ __func__
# else
#  define __assert_func_name__ 0
# endif
#endif

#if __STDC_VERSION__ >= 201112L
# define static_assert _Static_assert
#endif

#ifdef NDEBUG
# define assert(ignore) ((void)0)
#else
# define assert(x) (!(x) ? __assert_fail(#x, __FILE__, __LINE__, __assert_func_name__) : (void)0)
#endif

__BEGIN_DECLS

extern _Noreturn void __assert_fail
(const char *,
 const char *,
 unsigned int,
 const char *);

__END_DECLS
