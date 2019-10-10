#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "int-format.c"
#include "printf-helpers.c"

int vfprintf(FILE *fp, const char *fmt, va_list _ap)
{
    int flags, isiz;
    va_list ap;
    size_t ctr = 0,
           num = 0,
           len = strlen(fmt);
    va_copy(ap, _ap);

    /* TODO: Add proper float formatting */

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
