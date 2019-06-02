/*
 *  Copyright (C) 2019 James Larrowe
 *
 *  This file is part of Minilibc.
 *
 *  Minilibc is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Minilibc is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with Minilibc.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdnoreturn.h>
#include <stdlib.h>
#include <elf.h>

#include "_start.h"

extern _Noreturn int __libc_start_main
(
int (*)(int, char**, char**),
int,
char **
);

extern int main(int, char**, char**);

_Noreturn void _c_start(intptr_t *ptr)
{
    int argc = *ptr;
    char **argv = (char **)ptr+1;

    __libc_start_main(main, argc, argv);
}
