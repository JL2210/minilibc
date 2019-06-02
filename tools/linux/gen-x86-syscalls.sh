#!/bin/bash
#
#  Copyright (C) 2019 James Larrowe
#
#  This file is part of Minilibc.
#
#  Minilibc is free software: you can redistribute it and/or modify
#  it under the terms of the GNU Lesser General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  Minilibc is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU Lesser General Public License for more details.
#
#  You should have received a copy of the GNU Lesser General Public License
#  along with Minilibc.  If not, see <https://www.gnu.org/licenses/>.
#

bits=32

wget https://raw.githubusercontent.com/torvalds/linux/master/arch/x86/entry/syscalls/syscall_${bits}.tbl
mv syscall_${bits}.tbl syscall_${bits}.tbl.orig
sed -e '/^#/d' -e '/^$/d' syscall_${bits}.tbl.orig > syscall_${bits}.tbl
cat syscall_${bits}.tbl | cut -f3 | sed 's,^,SYS_,g' | sed 's,^,#define ,g' | sed 's,$, _SYS_NUM_,g' > syscall_${bits}.h
for syscall_num in $(cat syscall_${bits}.tbl | cut -f1); do
  syscall=$(cat syscall_${bits}.tbl | sed -n "/^$syscall_num	/p" | cut -f3 | sed 's,^,SYS_,g')
  sed -i "/ $syscall /s,_SYS_NUM_,$syscall_num,g" syscall_${bits}.h
done
sed 's,SYS_,__NR_,g' syscall_${bits}.h > syscall_${bits}.h.tmp
cat syscall_${bits}.h.tmp >> syscall_${bits}.h
cat << "_EOF_" >> syscall_${bits}.h
#undef SYS_mmap
#define SYS_mmap SYS_mmap2
_EOF_
$(echo $0 | sed 's,86,&_64,')
rm -f syscall_${bits}.tbl{,.orig} syscall_${bits}.h.tmp
