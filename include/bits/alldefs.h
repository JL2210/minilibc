#if defined(__need_int8_t) && !defined(__defined_int8_t)
# define __defined_int8_t
typedef signed char int8_t;
#endif

#if defined(__need_int16_t) && !defined(__defined_int16_t)
# define __defined_int16_t
typedef signed short int16_t;
#endif

#if defined(__need_int32_t) && !defined(__defined_int32_t)
# define __defined_int32_t
typedef signed int int32_t;
#endif

#if defined(__need_int64_t) && !defined(__defined_int64_t)
# define __defined_int64_t
# ifdef __LP64__
typedef signed long int64_t;
# else
__extension__ typedef signed long long int64_t;
# endif
#endif

#if defined(__need_intptr_t) && !defined(__defined_intptr_t)
# define __defined_intptr_t
typedef signed long intptr_t;
#endif

#if defined(__need_intmax_t) && !defined(__defined_intmax_t)
# define __defined_intmax_t
__extension__ typedef signed long long intmax_t;
#endif

#if defined(__need_uint8_t) && !defined(__defined_uint8_t)
# define __defined_uint8_t
typedef unsigned char uint8_t;
#endif

#if defined(__need_uint16_t) && !defined(__defined_uint16_t)
#define __defined_uint16_t
typedef unsigned short uint16_t;
#endif

#if defined(__need_uint32_t) && !defined(__defined_uint32_t)
# define __defined_uint32_t
typedef unsigned int uint32_t;
#endif

#if defined(__need_uint64_t) && !defined(__defined_uint64_t)
# define __defined_uint64_t
# ifdef __LP64__
typedef unsigned long uint64_t;
# else
__extension__ typedef unsigned long long uint64_t;
# endif
#endif

#if defined(__need_uintptr_t) && !defined(__defined_uintptr_t)
# define __defined_uintptr_t
typedef unsigned long uintptr_t;
#endif

#if defined(__need_uintmax_t) && !defined(__defined_uintmax_t)
# define __defined_uintmax_t
__extension__ typedef unsigned long long uintmax_t;
#endif

#if defined(__need_ptrdiff_t) && !defined(__defined_ptrdiff_t)
# define __defined_ptrdiff_t
typedef signed long ptrdiff_t;
#endif

#if defined(__need_locale_t) && !defined(__defined_locale_t)
# define __defined_locale_t
typedef int locale_t;
#endif

#if defined(__need_useconds_t) && !defined(__defined_useconds_t)
# define __defined_useconds_t
typedef unsigned long useconds_t;
#endif

#if defined(__need_suseconds_t) && !defined(__defined_suseconds_t)
# define __defined_suseconds_t
typedef signed long suseconds_t;
#endif

#if defined(__need_mode_t) && !defined(__defined_mode_t)
# define __defined_mode_t
typedef signed int mode_t;
#endif

#if defined(__need_off_t) && !defined(__defined_off_t)
# define __defined_off_t
__extension__ typedef signed long long off_t;
#endif

#if defined(__need_blkcnt_t) && !defined(__defined_blkcnt_t)
# define __defined_blkcnt_t
typedef signed long blkcnt_t;
#endif

#if defined(__need_blksize_t) && !defined(__defined_blksize_t)
# define __defined_blksize_t
typedef signed long blksize_t;
#endif

#if defined(__need_size_t) && !defined(__defined_size_t)
# define __defined_size_t
# ifdef __LP64__
typedef unsigned long size_t;
# else
typedef unsigned int size_t;
# endif
#endif

#if defined(__need_ssize_t) && !defined(__defined_ssize_t)
# define __defined_ssize_t
# ifdef __LP64__
typedef signed long ssize_t;
# else
typedef signed int ssize_t;
# endif
#endif

#if defined(__need_time_t) && !defined(__defined_time_t)
# define __defined_time_t
typedef signed long time_t;
#endif

#if defined(__need_dev_t) && !defined(__defined_dev_t)
# define __defined_dev_t
typedef int dev_t;
#endif

#if defined(__need_pid_t) && !defined(__defined_pid_t)
# define __defined_pid_t
typedef signed int pid_t;
#endif

#if defined(__need_socklen_t) && !defined(__defined_socklen_t)
# define __defined_socklen_t
typedef unsigned long socklen_t;
#endif

#if defined(__need_sig_atomic_t) && !defined(__defined_sig_atomic_t)
# define __defined_sig_atomic_t
typedef int sig_atomic_t;
#endif

#if defined(__need_float_t) && !defined(__defined_float_t)
# define __defined_float_t
typedef float float_t;
#endif

#if defined(__need_double_t) && !defined(__defined_double_t)
# define __defined_double_t
typedef double double_t;
#endif

#if defined(__need_va_list) && !defined(__defined_va_list)
# define __defined_va_list
# if defined(__GNUC__)
typedef __builtin_va_list va_list;
# else
#  if defined(__i386__) || defined(__i386)
typedef char *va_list;
#  else
#   error "va_list has not been implemented for your platform."
#  endif
# endif
#endif

#if defined(__need___compar_fn_t) && !defined(__defined___compar_fn_t)
# define __defined___compar_fn_t
typedef int (*__compar_fn_t)(const void *, const void *);
#endif

#if defined(__need___sighandler_t) && !defined(__defined___sighandler_t)
# define __defined___sighandler_t
typedef void (*__sighandler_t)(int);
#endif

#if defined(__need_div_t) && !defined(__defined_div_t)
# define __defined_div_t
typedef struct
{
    int quot;
    int rem;
} div_t;
#endif

#if defined(__need_ldiv_t) && !defined(__defined_ldiv_t)
# define __defined_ldiv_t
typedef struct
{
    long quot;
    long rem;
} ldiv_t;
#endif

#if defined(__need_lldiv_t) && !defined(__defined_lldiv_t)
# define __defined_lldiv_t
typedef struct
{
    __extension__ long long quot;
    __extension__ long long rem;
} lldiv_t;
#endif

#if defined(__need_fpos_t) && !defined(__defined_fpos_t)
# define __defined_fpos_t
typedef union _G_fpos64_t
{
    __extension__ signed long long __ll;
    double __dbl;
} fpos_t;
#endif

#if defined(__need_max_align_t) && !defined(__defined_max_align_t)
# define __defined_max_align_t
typedef union
{
    long double __ld;
    __extension__ long long __ll;
} max_align_t;
#endif

#if defined(__need_jmp_buf) && !defined(__defined_jmp_buf)
# define __defined_jmp_buf
typedef struct __jmp_buf_tag
{
    _JMP_BUF_TYPE __jmpbuf[_JMP_BUF_SIZE];
} jmp_buf[1];
#endif

#if defined(__need_FILE) && !defined(__defined_FILE)
# define __defined_FILE
typedef struct _IO_FILE FILE;
#endif

#if defined(__need_timespec) && !defined(__defined_timespec)
# define __defined_timespec
struct timespec
{
    time_t tv_sec;
    long tv_nsec;
};
#endif

#if defined(__need_timeval) && !defined(__defined_timeval)
# define __defined_timeval
struct timeval
{
    time_t tv_sec;
    suseconds_t tv_usec;
};
#endif

#if defined(__need_itimerspec) && !defined(__defined_itimerspec)
# define __defined_itimerspec
struct itimerspec
{
    struct timespec it_interval;
    struct timespec it_value;
};
#endif

#if defined(__need_rusage) && !defined(__defined_rusage)
# define __defined_rusage
struct rusage
{
    struct timeval ru_utime; /* user time used */
    struct timeval ru_stime; /* system time used */
    long ru_maxrss;          /* maximum resident set size */
    long ru_ixrss;           /* integral shared memory size */
    long ru_idrss;           /* integral unshared data size */
    long ru_isrss;           /* integral unshared stack size */
    long ru_minflt;          /* page reclaims */
    long ru_majflt;          /* page faults */
    long ru_nswap;           /* swaps */
    long ru_inblock;         /* block input operations */
    long ru_oublock;         /* block output operations */
    long ru_msgsnd;          /* messages sent */
    long ru_msgrcv;          /* messages received */
    long ru_nsignals;        /* signals received */
    long ru_nvcsw;           /* voluntary context switches */
    long ru_nivcsw;          /* involuntary context switches */
};
#endif

#if defined(__need_sigval) && !defined(__defined_sigval)
# define __defined_sigval
union sigval
{
    int sival_int;
    void *sival_ptr;
};
#endif

#if defined(__need_Elf32_auxv_t) && !defined(__defined_Elf32_auxv_t)
# define __defined_Elf32_auxv_t
typedef struct Elf32_auxv_t
{
    uint32_t a_type;
    union
    {
        uint32_t a_val;
    } a_un;
} Elf32_auxv_t;
#endif

#if defined(__need_Elf64_auxv_t) && !defined(__defined_Elf64_auxv_t)
# define __defined_Elf64_auxv_t
typedef struct Elf64_auxv_t
{
    uint64_t a_type;
    union
    {
        uint64_t a_val;
    } a_un;
} Elf64_auxv_t;
#endif

#if defined(__need_Elf_auxv_t) && !defined(__defined_Elf_auxv_t)
# define __defined_Elf_auxv_t
typedef struct Elf_auxv_t
{
    uintptr_t a_type;
    union
    {
        uintptr_t a_val;
        void *a_ptr;
	void (*a_fcn)(void);
    } a_un;
} Elf_auxv_t;
#endif

#if defined(__need_NULL) && !defined(__defined_NULL)
# define __defined_NULL
# ifndef __cplusplus
#  define NULL ((void *)0)
# else
#  define NULL 0L
# endif
#endif

#if defined(__need_EOF) && !defined(__defined_EOF)
# define __defined_EOF
# define EOF (-1)
#endif
