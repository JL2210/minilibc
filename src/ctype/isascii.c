#include <ctype.h>

int (isascii)(int c)
{
    return !((unsigned)c & ~(unsigned)0x7f);
}
