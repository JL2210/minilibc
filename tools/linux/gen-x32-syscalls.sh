#!/bin/bash

bits=x32

tbl=syscall_64.tbl

wget https://raw.githubusercontent.com/torvalds/linux/master/arch/x86/entry/syscalls/${tbl}
mv ${tbl} ${tbl}.orig
sed -e '/^#/d' -e '/^$/d' -e '/	64	/d' ${tbl}.orig > ${tbl}
cat ${tbl} | cut -f3 | sed 's,^,SYS_,g' | sed 's,^,#define ,g' | sed 's,$, _SYS_NUM_,g' > syscall_${bits}.h
for syscall_num in $(cat ${tbl} | cut -f1); do
  syscall=$(cat ${tbl} | sed -n "/^$syscall_num	/p" | cut -f3 | sed 's,^,SYS_,g')
  sed -i "/ $syscall /s,_SYS_NUM_,$syscall_num,g" syscall_${bits}.h
done
sed 's,SYS_,__NR_,g' syscall_${bits}.h > syscall_${bits}.h.tmp
cat syscall_${bits}.h.tmp >> syscall_${bits}.h
rm -f ${tbl}{,.orig} syscall_${bits}.h.tmp

echo Done generating x32 syscall table. >&2
echo Find it in syscall_x32.h. >&2
