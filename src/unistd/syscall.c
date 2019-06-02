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

#include <unistd.h>
#include <stdarg.h>
#include <errno.h>

extern intptr_t __syscall(intptr_t, ...);

intptr_t syscall(intptr_t a, ...)
{
	int ctr;
	va_list ap;
	intptr_t ret, args[6];

	va_start(ap, a);

	for( ctr = 0; ctr < 6; ctr++ )
	{
		args[ctr] = va_arg(ap, intptr_t);
	}

	va_end(ap);

	ret = __syscall(a, args[0], args[1], args[2], args[3], args[4], args[5], args[6]);
	if(ret > -4096UL)
	{
		errno = -ret;
		ret = -1;
	}

	return ret;
}
