#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "static/int-format.c"
#include "static/printf-helpers.c"

int vfprintf(FILE *fp, const char *fmt, va_list _ap)
{
    int flags, isiz, fsiz = 0;
    va_list ap;
    size_t ctr = 0,
           num = 0,
           len = strlen(fmt);
    va_copy(ap, _ap);

    (void)fsiz; /* TODO: Add proper float formatting */

    while(ctr < len)
    {
        while(fmt[ctr] != '%')
        {
            fputc(fmt[ctr], fp);
            ctr++;
            if(ctr >= len)
                goto terminate;
            num++;
        }
        if(++ctr >= len)
        {
            ctr--;
            fputc(fmt[ctr], fp);
            goto terminate;
        }
        fsiz = sizeof(double);
        isiz = sizeof(int);
        flags = 0;
check_type:
        switch(fmt[ctr])
        {
        case 'n':
            *va_arg(ap, int *) = num;
            break;
        case 'l':
            isiz = add_l(isiz);
            ctr++;
            goto check_type;
        case 'L':
            fsiz = sizeof(long double);
            ctr++;
            goto check_type;
        case 'Z':
        case 'z':
            isiz = sizeof(size_t);
            /* FALLTHRU */
        case 'h':
            ctr++;
            goto check_type;
        case 'c':
            fputc(va_arg(ap, int), fp);
            num++;
            break;
        case 'd':
        case 'i':
            printf_int_helper(fp, &ap, 10, flags, isiz, &num);
            break;
        case 'u':
            printf_uint_helper(fp, &ap, 10, flags, isiz, &num);
            break;
        case 'X':
            flags |= FLAG_CAPS;
            /* FALLTHRU */
        case 'x':
            printf_uint_helper(fp, &ap, 16, flags, isiz, &num);
            break;
/*
        case 'f':
            printf_flt_helper(fp, &ap, flags, fsiz, &num);
            break;
*/
        case 'p':
            num += fputs("0x", fp);
            printf_int_helper(fp, &ap, 16, flags, sizeof(void *), &num);
            break;
        case 's':
            num += fputs(va_arg(ap, char *), fp);
            break;
        case '%':
        default:
            fputc(fmt[ctr], fp);
            num++;
            break;
        }
        ctr++;
    }
terminate:
    return num;
}
