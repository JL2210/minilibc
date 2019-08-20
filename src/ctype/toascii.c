#include <ctype.h>

int (toascii)(int c)
{
    return c & ~(1 << 7);
}
