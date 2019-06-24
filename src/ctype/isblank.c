#include <stdio.h>
#undef isblank

int isblank(int c)
{
        return (c == ' ') || (c == '\t');
}
