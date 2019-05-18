#include <stdio.h>
#include <string.h>

int vfprintf(FILE *fp, const char *fmt, va_list ap)
{
    char *str;
    size_t ctr = 0,
           num = 0,
           len = strlen(fmt);
    while(ctr < len)
    {
        do {
            putchar(fmt[ctr++]);
            num++;
        } while(fmt[ctr] != '%' && fmt[ctr] != 0);
        switch(fmt[++ctr])
        {
            case '%':
                fputc(fmt[ctr], fp);
                num++;
                break;
            case 'c':
                fputc(va_arg(ap, int), fp);
                num++;
                break;
            case 's':
                str = va_arg(ap, char *);
                num += fputs(str, fp);
                break;
            default:
                break;
        }
    }
    return num;
}
