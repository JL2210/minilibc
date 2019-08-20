#ifdef __need_int8_t
#undef __need_int8_t
typedef signed char int8_t;
#endif

#ifdef __need_int16_t
#undef __need_int16_t
typedef signed short int16_t;
#endif

#ifdef __need_int32_t
#undef __need_int32_t
typedef signed int int32_t;
#endif

#ifdef __need_int64_t
#undef __need_int64_t
# ifdef __LP64__
typedef signed long int64_t;
# else
__extension__ typedef signed long long int64_t;
# endif
#endif

#ifdef __need_intptr_t
#undef __need_intptr_t
typedef signed long intptr_t;
#endif

#ifdef __need_intmax_t
#undef __need_intmax_t
typedef signed long long intmax_t;
#endif

#ifdef __need_uint8_t
#undef __need_uint8_t
typedef unsigned char uint8_t;
#endif

#ifdef __need_uint16_t
#undef __need_uint16_t
typedef unsigned short uint16_t;
#endif

#ifdef __need_uint32_t
#undef __need_uint32_t
typedef unsigned int uint32_t;
#endif

#ifdef __need_uint64_t
#undef __need_uint64_t
# ifdef __LP64__
typedef unsigned long uint64_t;
# else
__extension__ typedef unsigned long long uint64_t;
# endif
#endif

#ifdef __need_uintptr_t
#undef __need_uintptr_t
typedef unsigned long uintptr_t;
#endif

#ifdef __need_uintmax_t
#undef __need_uintmax_t
typedef unsigned long long uintmax_t;
#endif

#ifdef __need_ptrdiff_t
#undef __need_ptrdiff_t
typedef signed long ptrdiff_t;
#endif

#ifdef __need_off_t
#undef __need_off_t
typedef signed long long off_t;
#endif

#ifdef __need_locale_t
#undef __need_locale_t
typedef int locale_t;
#endif

#ifdef __need_useconds_t
#undef __need_useconds_t
typedef unsigned long useconds_t;
#endif

#ifdef __need_suseconds_t
#undef __need_suseconds_t
typedef signed long suseconds_t;
#endif

#ifdef __need_mode_t
#undef __need_mode_t
typedef unsigned int mode_t;
#endif

#ifdef __need_off_t
#undef __need_off_t
typedef signed long long off_t;
#endif

#ifdef __need_blkcnt_t
#undef __need_blkcnt_t
typedef signed long blkcnt_t;
#endif

#ifdef __need_blksize_t
#undef __need_blksize_t
typedef signed long blksize_t;
#endif

#ifdef __need_size_t
#undef __need_size_t
# ifdef __LP64__
typedef unsigned long size_t;
# else
typedef unsigned int size_t;
# endif
#endif

#ifdef __need_ssize_t
#undef __need_ssize_t
# ifdef __LP64__
typedef signed long ssize_t;
# else
typedef signed int ssize_t;
# endif
#endif

#ifdef __need_time_t
#undef __need_time_t
typedef signed long time_t;
#endif

#ifdef __need_dev_t
#undef __need_dev_t
typedef int dev_t;
#endif

#ifdef __need_pid_t
#undef __need_pid_t
typedef signed int pid_t;
#endif

#ifdef __need_socklen_t
#undef __need_socklen_t
typedef unsigned long socklen_t;
#endif

#ifdef __need___compar_fn_t
#undef __need___compar_fn_t
typedef int (*__compar_fn_t)(const void *, const void *);
#endif

#ifdef __need_jmp_buf
#undef __need_jmp_buf
typedef void *jmp_buf[_JMP_BUF_SIZE];
#endif

#ifdef __need_fpos_t
#undef __need_fpos_t
typedef struct
{
    off_t offset;
} fpos_t;
#endif

#ifdef __need_FILE
#undef __need_FILE
typedef struct _IO_FILE
{
    int __fd;
    int __flags;
    int __unget;
    char *__buffer;
    struct {
        size_t __orig;
        size_t __size;
        size_t __written;
    } __bufsiz;
    fpos_t __fpos;
} FILE;
#endif

#ifdef __need_timespec
#undef __need_timespec
struct timespec
{
    time_t tv_sec;
    long tv_nsec;
};
#endif

#ifdef __need_timeval
#undef __need_timeval
struct timeval
{
    time_t tv_sec;
    suseconds_t tv_usec;
};
#endif

#ifdef __need_itimerspec
#undef __need_itimerspec
struct itimerspec
{
    struct timespec it_interval;
    struct timespec it_value;
};
#endif

#ifdef __need_rusage
#undef __need_rusage
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

#ifdef __need_Elf32_auxv_t
#undef __need_Elf32_auxv_t
typedef struct Elf32_auxv_t
{
    uint32_t a_type;
    union
    {
        uint32_t a_val;
    } a_un;
} Elf32_auxv_t;
#endif

#ifdef __need_Elf64_auxv_t
#undef __need_Elf64_auxv_t
typedef struct Elf64_auxv_t
{
    uint64_t a_type;
    union
    {
        uint64_t a_val;
    } a_un;
} Elf64_auxv_t;
#endif

#ifdef __need_Elf_auxv_t
#undef __need_Elf_auxv_t
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

#ifdef __need_NULL
#undef __need_NULL
# ifndef __cplusplus
#  define NULL ((void *)0)
# else
#  define NULL 0L
# endif
#endif

#ifdef __need_SEEK_SET
#undef __need_SEEK_SET
# define SEEK_SET (0)
#endif

#ifdef __need_SEEK_CUR
#undef __need_SEEK_CUR
# define SEEK_CUR (1)
#endif

#ifdef __need_SEEK_END
#undef __need_SEEK_END
# define SEEK_END (2)
#endif
