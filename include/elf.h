#ifndef _ELF_H
#define _ELF_H 1

#include <stdint.h>

/* Types */

struct Elf32_auxv_t
{
	uint32_t a_type;
	union
	{
		uint32_t a_val;
  	} a_un;
};
typedef struct Elf32_auxv_t Elf32_auxv_t;

struct Elf64_auxv_t
{
	uint64_t a_type;
	union
	{
		uint64_t a_val;
	} a_un;
};
typedef struct Elf64_auxv_t Elf64_auxv_t;

#ifdef __LP64__
# define Elf_auxv_t Elf64_auxv_t
#else
# define Elf_auxv_t Elf32_auxv_t
#endif

#define AT_NULL 0
#define AT_IGNORE 1
#define AT_EXECFD 2
#define AT_PHDR 3
#define AT_PHENT 4
#define AT_PHNUM 5
#define AT_PAGESZ 6
#define AT_BASE 7
#define AT_FLAGS 8
#define AT_ENTRY 9
#define AT_NOTELF 10
#define AT_UID 11
#define AT_EUID 12
#define AT_GID 13
#define AT_EGID 14
#define AT_PLATFORM 15
#define AT_HWCAP 16
#define AT_CLKTCK 17
#define AT_FPUCW 18
#define AT_DCACHEBSIZE 19
#define AT_ICACHEBSIZE 20
#define AT_UCACHEBSIZE 21
#define AT_IGNOREPPC 22
#define AT_SECURE 23
#define AT_BASE_PLATFORM 24
#define AT_RANDOM 25
#define AT_HWCAP2 26
/* 27-30 missing? */
#define AT_EXECFN 31
#define AT_SYSINFO 32
#define AT_SYSINFO_EHDR 33
#define AT_L1I_CACHESHAPE 34
#define AT_L1D_CACHESHAPE 35
#define AT_L2_CACHESHAPE 36
#define AT_L3_CACHESHAPE 37
/* 38,39? */
#define AT_L1I_CACHESIZE 40
#define AT_L1I_CACHEGEOMETRY 41
#define AT_L1D_CACHESIZE 42
#define AT_L1D_CACHEGEOMETRY 43
#define AT_L2_CACHESIZE 44
#define AT_L2_CACHEGEOMETRY 45
#define AT_L3_CACHESIZE 46
#define AT_L3_CACHEGEOMETRY 47

#endif
