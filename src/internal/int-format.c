#define BASE_BIN 2
#define BASE_OCT 8
#define BASE_DEC 10
#define BASE_HEX 16
#define BASE_02Z 36

#define FLAG_CAPS 1

/* character to decimal table */
static unsigned int dec_to_char_tab[0x16] =
{
    [10] = 'a',
    [11] = 'b',
    [12] = 'c',
    [13] = 'd',
    [14] = 'e',
    [15] = 'f',
    [16] = 'g',
    [17] = 'h',
    [18] = 'i',
    [19] = 'j',
    [20] = 'k',
    [21] = 'l',
    [22] = 'm',
    [23] = 'n',
    [24] = 'o',
    [25] = 'p',
    [26] = 'q',
    [27] = 'r',
    [28] = 's',
    [29] = 't',
    [30] = 'u',
    [31] = 'v',
    [32] = 'w',
    [33] = 'x',
    [34] = 'y',
    [35] = 'z',
};


// base 10 conversion
static void lltoa(long long val, FILE *fp)
{
    static char buf[21];

    int digit;
    char *p = buf + sizeof(buf);

    *--p = '\0';

    do {
        digit = val % 10;
        val /= 10;

        if(digit < 0)
        {
            digit = -digit;
            /* The result can fit so now negate it. */
            val = -val;
            /* Write negative sign. */
            *--p = '-';
        }

        *--p = '0' + digit;
    } while(val);
}

static size_t lltoa(long long val, FILE *fp, int base, int flags)
{
    static unsigned char buf[65];

    int digit;
    size_t size = 0;
    unsigned char c, a;
    unsigned char *p = buf + sizeof(buf);

    if( base < BASE_BIN || base > BASE_02Z )
    {
        errno = EINVAL;
        return -1;
    }

    /* Calculate letter based on flags */
    *--p = '\0';

    do {
        digit = val % base;
        val /= base;

        if(digit < BASE_DEC)
        {
            *--p = '0' + digit;
        }
        else
        {
            if(flags & FLAG_CAPS)
                *--p = toupper(dec_to_char_tab[digit]);
            else
                *--p = dec_to_char_tab[digit];
        }
    } while(val);

    return size;
}
