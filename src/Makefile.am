AM_CPPFLAGS = -I$(top_srcdir)/src/include \
	      -I$(top_srcdir)/include \
	      -I$(top_srcdir)/arch/$(ARCH) \
	      -I$(top_srcdir)/arch/$(ARCH)/include \
	      -I$(top_srcdir)/src/internal

lib_LIBRARIES = libc.a

crtdir = $(libdir)
crt_DATA = crt1.o Scrt1.o crti.o crtn.o

crt1.o: $(top_srcdir)/src/crt/crt1.c
	$(CC) -c -fno-PIC $(AM_CPPFLAGS) $(CFLAGS) -o $@ $^

Scrt1.o: $(top_srcdir)/src/crt/crt1.c
	$(CC) -c -fPIC $(AM_CPPFLAGS) $(CFLAGS) -o $@ $^

crti.o: $(top_srcdir)/arch/$(ARCH)/src/crt/crti.s
	$(CCAS) -c $(CFLAGS) -o $@ $^

crtn.o: $(top_srcdir)/arch/$(ARCH)/src/crt/crtn.s
	$(CCAS) -c $(CFLAGS) -o $@ $^

noinst_HEADERS = \
	include/errno.h \
	include/fcntl.h \
	include/libc-deps.h \
	include/signal.h \
	include/stdio.h \
	include/string.h \
	include/sys/mman.h \
	include/sys/stat.h \
	include/sys/wait.h \
	include/time.h \
	include/unistd.h \
	internal/atexit.h

EXTRA_libc_a_SOURCES = \
	crt/crt1.c \
	../arch/$(ARCH)/src/crt/crti.s \
	../arch/$(ARCH)/src/crt/crtn.s \
	internal/int-format.c \
	internal/printf-helpers.c

libc_a_SOURCES = \
	../arch/$(ARCH)/src/setjmp/setjmp.S \
	../arch/$(ARCH)/src/setjmp/longjmp.S \
	../arch/$(ARCH)/src/unistd/syscall.s \
	assert/assert.c \
	ctype/isalnum.c \
	ctype/isalpha.c \
	ctype/isascii.c \
	ctype/isblank.c \
	ctype/iscntrl.c \
	ctype/isdigit.c \
	ctype/isgraph.c \
	ctype/islower.c \
	ctype/isprint.c \
	ctype/ispunct.c \
	ctype/isspace.c \
	ctype/isupper.c \
	ctype/isxdigit.c \
	ctype/toascii.c \
	ctype/tolower.c \
	ctype/toupper.c \
	errno/errno.c \
	errno/progname.c \
	errno/sys_errlist.c \
	errno/sys_nerr.c \
	fcntl/openat.c \
	fcntl/open.c \
	libtcc/libtcc1.c \
	malloc/malloc.c \
	mman/mmap.c \
	mman/mprotect.c \
	mman/munmap.c \
	signal/kill.c \
	signal/raise.c \
	stat/getumask.c \
	stat/umask.c \
	stdio/clearerr.c \
	stdio/fclose.c \
	stdio/feof.c \
	stdio/ferror.c \
	stdio/fflush.c \
	stdio/fgetc.c \
	stdio/fgets.c \
	stdio/fileno.c \
	stdio/fopen.c \
	stdio/fprintf.c \
	stdio/fputc.c \
	stdio/fputs.c \
	stdio/fread.c \
	stdio/fseek.c \
	stdio/ftell.c \
	stdio/fwrite.c \
	stdio/getc.c \
	stdio/getchar.c \
	stdio/gets.c \
	stdio/perror.c \
	stdio/printf.c \
	stdio/putchar.c \
	stdio/puts.c \
	stdio/rewind.c \
	stdio/setbuf.c \
	stdio/setbuffer.c \
	stdio/setlinebuf.c \
	stdio/setvbuf.c \
	stdio/snprintf.c \
	stdio/sprintf.c \
	stdio/stdio.c \
	stdio/ungetc.c \
	stdio/vfprintf.c \
	stdio/vprintf.c \
	stdio/vsnprintf.c \
	stdio/vsprintf.c \
	stdlib/abort.c \
	stdlib/abs.c \
	stdlib/atexit.c \
	stdlib/ato.c \
	stdlib/bsearch.c \
	stdlib/div.c \
	stdlib/exit.c \
	stdlib/getenv.c \
	stdlib/labs.c \
	stdlib/ldiv.c \
	stdlib/lldiv.c \
	stdlib/qsort.c \
	stdlib/quick_exit.c \
	stdlib/rand.c \
	stdlib/strtoll.c \
	string/ffs.c \
	string/ffsl.c \
	string/ffsll.c \
	string/memchr.c \
	string/memcmp.c \
	string/memcpy.c \
	string/memmem.c \
	string/memmove.c \
	string/memrchr.c \
	string/memset.c \
	string/stpcpy.c \
	string/strcasecmp.c \
	string/strcat.c \
	string/strchr.c \
	string/strchrnul.c \
	string/strcmp.c \
	string/strcoll.c \
	string/strcpy.c \
	string/strcspn.c \
	string/strdup.c \
	string/strerror.c \
	string/strlen.c \
	string/strncasecmp.c \
	string/strncat.c \
	string/strncmp.c \
	string/strncpy.c \
	string/strndup.c \
	string/strnlen.c \
	string/strrchr.c \
	string/strspn.c \
	string/strstr.c \
	string/strtok.c \
	string/strtok_r.c \
	string/strxfrm.c \
	time/nanosleep.c \
	time/time.c \
	unistd/brk.c \
	unistd/close.c \
	unistd/environ.c \
	unistd/_exit.c \
	unistd/fork.c \
	unistd/fsync.c \
	unistd/getpid.c \
	unistd/lseek.c \
	unistd/read.c \
	unistd/sbrk.c \
	unistd/sleep.c \
	unistd/unlinkat.c \
	unistd/unlink.c \
	unistd/usleep.c \
	unistd/write.c \
	wait/wait.c \
	wait/wait3.c \
	wait/wait4.c \
	wait/waitpid.c

