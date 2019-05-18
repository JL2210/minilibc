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
            if(ctr >= len || fmt[ctr] == '\0')
                return num;
        } while(fmt[ctr] != '%');
	if(++ctr >= len) return ++num;
        switch(fmt[ctr])
        {
            case 'c':
                fputc(va_arg(ap, int), fp);
                num++;
                break;
            case 's':
                str = va_arg(ap, char *);
                num += fputs(str, fp);
                break;
            case '%':
            default:
                fputc(fmt[ctr], fp);
                num++;
                break;
        }
    }
    return num;
}
