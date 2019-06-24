#include <stdio.h>
#undef toascii

int toascii(int c)
{
        return c & ~(1 << 7);
}
