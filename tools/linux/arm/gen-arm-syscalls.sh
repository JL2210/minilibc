#!/bin/bash

bits=32

tbl=syscall.tbl

wget https://raw.githubusercontent.com/torvalds/linux/master/arch/arm/tools/${tbl}
mv ${tbl} ${tbl}.orig
sed -e '/^#/d' -e '/^$/d' ${tbl}.orig > ${tbl}
cat ${tbl} | cut -f3 | sed 's,^,SYS_,g' | sed 's,^,#define ,g' | sed 's,$, _SYS_NUM_,g' > syscall.h
for syscall_num in $(cat ${tbl} | cut -f1); do
  syscall=$(cat ${tbl} | sed -n "/^$syscall_num	/p" | cut -f3 | sed 's,^,SYS_,g')
  sed -i "/ $syscall /s,_SYS_NUM_,$syscall_num,g" syscall.h
done
sed 's,SYS_,__NR_,g' syscall.h > syscall.h.tmp
cat syscall.h.tmp >> syscall.h
rm -f ${tbl}{,.orig} syscall.h.tmp

echo Done generating arm syscall table. >&2
echo Find it in syscall.h. >&2
