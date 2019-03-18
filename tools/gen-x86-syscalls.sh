#!/bin/bash

for bits in 32 64; do
  wget https://raw.githubusercontent.com/torvalds/linux/master/arch/x86/entry/syscalls/syscall_${bits}.tbl
  sed -i -e '/^#/d' -e '/^$/d' syscall_${bits}.tbl
  cat syscall_${bits}.tbl | cut -f3 | sed 's,^,SYS_,g' | sed 's,^,#define ,g' | sed 's,$, _SYS_NUM_,g' > syscall_${bits}.h
  for syscall_num in $(cat syscall_${bits}.tbl | cut -f1); do
    syscall=$(cat syscall_${bits}.tbl | sed -n "/^$syscall_num	/p" | cut -f3 | sed 's,^,SYS_,g')
    sed -i "/ $syscall /s,_SYS_NUM_,$syscall_num,g" syscall_${bits}.h
  done
  rm syscall_${bits}.tbl
done
