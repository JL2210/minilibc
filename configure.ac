AC_INIT(minilibc, 0.0)

AC_CONFIG_MACRO_DIRS([m4])
AC_CONFIG_AUX_DIR([build-aux])

AC_CANONICAL_BUILD
AC_CANONICAL_HOST

AC_PROG_RANLIB

AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AM_PROG_AR
AM_PROG_AS

dnl Function to check cflags
AC_DEFUN([AM_CHECK_CFLAG], [
AC_MSG_CHECKING(whether the C compiler understands $1)
old_AM_CFLAGS="$AM_CFLAGS"
AM_CFLAGS="$AM_CFLAGS $1"
old_CFLAGS="$CFLAGS"
CFLAGS="$CFLAGS $AM_CFLAGS"
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([],[])],
  AC_MSG_RESULT(yes)
  CFLAGS="$old_CFLAGS",
  AC_MSG_RESULT(no)
  CFLAGS="$old_CFLAGS"
  AM_CFLAGS="$old_AM_CFLAGS")])

dnl Relatively generic flags
AM_CHECK_CFLAG([-Wall])
AM_CHECK_CFLAG([-Wextra])
AM_CHECK_CFLAG([-Werror])
AM_CHECK_CFLAG([-std=c99])
AM_CHECK_CFLAG([-pedantic])
AM_CHECK_CFLAG([-nostdinc])

case "$host_cpu" in
  x86_64|amd64)
    ARCH=x86_64;;
  x86|i[3456]86)
    ARCH=x86;;
  arm*)
    ARCH=arm;;
  *)
    ARCH=generic;;
esac

AC_SUBST([ARCH])
AC_SUBST([AM_CFLAGS])

AC_CONFIG_FILES([
  Makefile
  src/Makefile
  arch/Makefile
  include/Makefile
  arch/arm/Makefile
  arch/i386/Makefile
  arch/x86_64/Makefile
  arch/generic/Makefile
  arch/arm/include/Makefile
  arch/i386/include/Makefile
  arch/x86_64/include/Makefile
  arch/generic/include/Makefile
])

AC_OUTPUT
