#ifndef _ELF_H
#define _ELF_H 1

#include <stdint.h>

typedef struct
{
	uint32_t a_type;
	union
	{
		uint32_t a_val;
  	} a_un;
} Elf32_auxv_t;

typedef struct
{
	uint64_t a_type;
	union
	{
		uint64_t a_val;
	} a_un;
} Elf64_auxv_t;

#ifdef __LP64__
# define Elf_auxv_t Elf64_auxv_t
#else
# define Elf_auxv_t Elf32_auxv_t
#endif

#endif
