#include <unistd.h>
#include <stdarg.h>

long syscall(long num, ...)
{
    long a,b,c,d,e,f;
    va_list ap;

    va_start(ap, num);
    a = va_arg(ap, long);
    b = va_arg(ap, long);
    c = va_arg(ap, long);
    d = va_arg(ap, long);
    e = va_arg(ap, long);
    f = va_arg(ap, long);
    va_end(ap);

    return __syscall(num, a, b, c, d, e, f);
}
