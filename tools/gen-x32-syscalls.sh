#!/bin/bash

bits=x32

tbl=${1/\.orig/}

sed -e '/^#/d' -e '/^$/d' -e "/	64	/d" ${tbl}.orig > ${tbl}
cat ${tbl} | cut -f3 | sed 's,^,SYS_,g' | sed 's,^,#define ,g' | sed 's,$, _SYS_NUM_,g' > syscall_${bits}.h
for syscall_num in $(cat ${tbl} | cut -f1); do
  syscall=$(cat ${tbl} | sed -n "/^$syscall_num	/p" | cut -f3 | sed 's,^,SYS_,g')
  sed -i "/ $syscall /s,_SYS_NUM_,$syscall_num,g" syscall_${bits}.h
done
sed 's,SYS_,__NR_,g' syscall_${bits}.h > syscall_${bits}.h.tmp
cat syscall_${bits}.h.tmp >> syscall_${bits}.h
rm -f syscall_${bits}.tbl syscall_${bits}.h.tmp
echo Done generating syscall tables. >&2
echo Find them in 'syscall_*.h'. >&2
