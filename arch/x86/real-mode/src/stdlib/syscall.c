#include <newboot.h>

intptr_t syscall(
intptr_t syscall,
intptr_t a,
intptr_t b,
intptr_t c,
intptr_t d,
intptr_t e,
intptr_t f)
{
    return bios_syscall(syscall, a, b, c, d, e, f);
}
