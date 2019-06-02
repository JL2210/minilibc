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

#include <elf.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdnoreturn.h>

extern void _init(void);
extern void _fini(void);

#define AUX_NUM 38

_Noreturn int __libc_start_main
(
int (*main)(int, char**, char**, size_t*),
int argc,
char **argv
)
{
    int ret;
    Elf_auxv_t *auxv;

    environ = argv + argc + 1;
    for( ret = 0; environ[ret]; ret++ );
    auxv = (Elf_auxv_t *)(environ + ret + 1);
    size_t aux[AUX_NUM];
    for( ret = 0; ret < AUX_NUM; ret++ )
        aux[ret] = auxv[ret].a_un.a_val;

    _init();
    ret = main(argc, argv, environ, aux);
    _fini();

    exit(ret);
}
