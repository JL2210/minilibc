static void printf_int_helper(FILE *fp,
                              va_list *ap,
                              int base,
                              int flags,
                              size_t varsiz,
                              size_t *nchars)
{
    long long var;
    if(sizeof(int) == sizeof(long))
    {
        if(varsiz <= sizeof(int))
            var = va_arg(*ap, int);
        else
            var = va_arg(*ap, long long);
    }
    else if(sizeof(long) == sizeof(long long))
    {
        if(varsiz <= sizeof(int))
            var = va_arg(*ap, int);
        else
            var = va_arg(*ap, long long);
    }
    else
    {
        if(varsiz <= sizeof(int))
            var = va_arg(*ap, int);
        else if(varsiz <= sizeof(long))
            var = va_arg(*ap, long);
        else
            var = va_arg(*ap, long long);
    }

    *nchars += lltoa(var, fp, base, flags);
}

static void printf_uint_helper(FILE *fp,
                               va_list *ap,
                               int base,
                               int flags,
                               size_t varsiz,
                               size_t *nchars)
{
    unsigned long long var;
    if(sizeof(unsigned) == sizeof(unsigned long))
    {
        if(varsiz <= sizeof(unsigned))
            var = va_arg(*ap, unsigned);
        else
            var = va_arg(*ap, unsigned long long);
    }
    else if(sizeof(unsigned long) == sizeof(unsigned long long))
    {
        if(varsiz <= sizeof(unsigned))
            var = va_arg(*ap, unsigned);
        else
            var = va_arg(*ap, unsigned long long);
    }
    else
    {
        if(varsiz <= sizeof(unsigned))
            var = va_arg(*ap, unsigned);
        else if(varsiz <= sizeof(unsigned long))
            var = va_arg(*ap, unsigned long);
        else
            var = va_arg(*ap, unsigned long long);
    }

    *nchars += ulltoa(var, fp, base, flags);
}

static inline int add_l(int isiz)
{
    if(sizeof(long) == sizeof(long long))
    {
        if(isiz == sizeof(int))
            isiz = sizeof(long);
    }
    else if(sizeof(int) == sizeof(long))
    {
        if(isiz == sizeof(long))
            isiz = sizeof(long long);
    }
    else /* Sigh. What kind of platform is this? */
    {
        if(isiz == sizeof(int))
            isiz = sizeof(long);
        else if(isiz == sizeof(long))
            isiz = sizeof(long long);
    }

    return isiz;
}
