#include <varargs.h>

int ll_log (va_alist)
va_dcl
{
    int event, result;
    LLog   *lp;
    va_list ap;

    va_start (ap);

    lp = va_arg (ap, LLog *);
    event = va_arg (ap, int);

    result = _ll_log (lp, event, ap);

    va_end (ap);

    return result;
}
