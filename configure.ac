AC_INIT(minilibc, 0.0)

AC_CONFIG_MACRO_DIRS([m4])
AC_CONFIG_AUX_DIR([build-aux])

AC_NO_EXECUTABLES

AC_CANONICAL_BUILD
AC_CANONICAL_HOST

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

AC_MSG_CHECKING([for valid prefix])
dnl Not a bash extension, just m4 quoting
if [[ x"$prefix" = "x/usr/local" ]]; then
  AC_MSG_RESULT([no])
  AC_MSG_ERROR([prefix is /usr/local])
else
  AC_MSG_RESULT([ok])
fi

AC_PROG_RANLIB
AC_PROG_LN_S

AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])

AM_PROG_AS
AM_PROG_AR

AC_PROG_RANLIB
AC_PROG_LN_S

m4_include([m4/check_cflag.m4])

CHECK_CFLAG([-Wall])
CHECK_CFLAG([-Wextra])
CHECK_CFLAG([-Werror])
CHECK_CFLAG([-Wshadow])
CHECK_CFLAG([-Wrestrict])
CHECK_CFLAG([-Wformat=2])
CHECK_CFLAG([-Wlogical-op])
CHECK_CFLAG([-Wduplicated-cond])
CHECK_CFLAG([-Wdouble-promotion])
CHECK_CFLAG([-Wjump-misses-init])
CHECK_CFLAG([-Wnull-dereference])
CHECK_CFLAG([-Wduplicated-branches])
CHECK_CFLAG([-std=c99])
CHECK_CFLAG([-pedantic])

AC_SUBST([AM_CFLAGS])

AC_SUBST([ARCH])

AC_CONFIG_FILES([
  Makefile
  src/Makefile
  arch/Makefile
  tools/Makefile
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
