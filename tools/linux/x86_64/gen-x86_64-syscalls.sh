#!/bin/bash

bits=64

wget https://raw.githubusercontent.com/torvalds/linux/master/arch/x86/entry/syscalls/syscall_${bits}.tbl
mv syscall_${bits}.tbl syscall_${bits}.tbl.orig
sed -e '/^#/d' -e '/^$/d' -e '/x32/d' syscall_${bits}.tbl.orig > syscall_${bits}.tbl
cat syscall_${bits}.tbl | cut -f3 | sed 's,^,SYS_,g' | sed 's,^,#define ,g' | sed 's,$, _SYS_NUM_,g' > syscall_${bits}.h
for syscall_num in $(cat syscall_${bits}.tbl | cut -f1); do
  syscall=$(cat syscall_${bits}.tbl | sed -n "/^$syscall_num	/p" | cut -f3 | sed 's,^,SYS_,g')
  sed -i "/ $syscall /s,_SYS_NUM_,$syscall_num,g" syscall_${bits}.h
done
sed 's,SYS_,__NR_,g' syscall_${bits}.h > syscall_${bits}.h.tmp
cat syscall_${bits}.h.tmp >> syscall_${bits}.h
rm -f syscall_${bits}.tbl{,.orig} syscall_${bits}.h.tmp
echo Done generating x86_64 syscall table. >&2
echo Find it in syscall_64.h. >&2
