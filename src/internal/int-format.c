#define BASE_BIN 2
#define BASE_OCT 8
#define BASE_DEC 10
#define BASE_HEX 16
#define BASE_02Z 36

#define FLAG_CAPS (0x1)

static size_t ulltoa(unsigned long long val, FILE *fp, unsigned base, int flags)
{
    unsigned long long divisor = 1;
    size_t size = 0;
    int remainder;
    char c;

    if(base < BASE_BIN || base > BASE_02Z)
    {
        errno = EINVAL;
        return -1;
    }

    while(val/divisor > base) divisor *= base;

    do {
        remainder = (val/divisor) % base;
        if(remainder >= BASE_DEC) c = (flags & FLAG_CAPS ? 'A' : 'a') - BASE_DEC;
        else c = '0';
        fputc(c + remainder, fp);
        divisor /= base;
        size++;
    } while(divisor);

    return size;
}

static size_t lltoa(long long val, FILE *fp, unsigned base, int flags)
{
    size_t size = 0;

    if(val < 0 && base == BASE_DEC)
    {
         val = -val;
         fputc('-', fp);
         size++;
    }

    size += ulltoa(val, fp, base, flags);
    return size;
}
