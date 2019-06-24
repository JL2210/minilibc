#include <stdio.h>
#undef isascii

int isascii(int c)
{
        return !(c & (1 << 7));
}
