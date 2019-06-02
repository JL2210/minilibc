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

#include <stdio.h>
#include <string.h>

int vfprintf(FILE *fp, const char *fmt, va_list ap)
{
    size_t ctr = 0,
           num = 0,
           len = strlen(fmt);
    while(ctr < len)
    {
        do {
            putchar(fmt[ctr++]);
            num++;
            if(ctr >= len)
                return num;
        } while(fmt[ctr] != '%');
        if(++ctr >= len)
        {
            putchar(fmt[--ctr]);
            return ++num;
        }
        switch(fmt[ctr])
        {
            case 'c':
                fputc(va_arg(ap, int), fp);
                num++;
                break;
            case 's':
                num += fputs(va_arg(ap, char *), fp);
                break;
            case '%':
            default:
                fputc(fmt[ctr], fp);
                num++;
                break;
        }
        ctr++;
    }
    return num;
}
