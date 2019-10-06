AC_INIT(minilibc, 0.0)

AC_CONFIG_MACRO_DIRS([m4])
AC_CONFIG_AUX_DIR([build-aux])

AM_INIT_AUTOMAKE([-Wall foreign])
AM_PROG_AR
AM_PROG_AS

LT_INIT

AC_DISABLE_SHARED

case "$host" in
  x86_64* | amd64*)
    ARCH=x86_64;;
  i[3456]86 | x86)
    ARCH=x86;;
  armv7*)
    ARCH=arm;;
  *)
    ARCH=generic;;
esac

AC_SUBST([ARCH])

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
