AC_INIT
AC_CONFIG_SRCDIR([echo.cc])

# Where are all the config files
AC_CONFIG_AUX_DIR(config)

# What kind of distribution are we supposed to create
AM_INIT_AUTOMAKE(test, 0.1)

dnl Checks for programs.
AC_PROG_CC
AC_PROG_CXX

CFLAGS="-g -Wall -Werror"
CXXFLAGS="-g -Wall -Werror"

AC_PROG_INSTALL
AC_PROG_LN_S
# Declaring that will use libtool
LT_INIT

AC_CONFIG_HEADERS([config.h])

dnl Checks for libraries.

dnl Checks for header files.
AC_HEADER_STDC
AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS(fcntl.h unistd.h)

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

dnl Checks for library functions.
AC_CHECK_FUNCS(strstr)

                      
dnl ***************************
dnl     Looking for NMSTL
dnl ***************************
AC_DEFUN([AC_NMSTL],
[AC_ARG_WITH(nmstl,    [  --with-nmstl], , )
AC_MSG_CHECKING([for NMSTL])

if test "x$with_nmstl" = x; then
    with_nmstl=/usr/local
fi

if test -f "$with_nmstl/include/NMSTL/ptr"; then
    NMSTLDIR=$with_nmstl
    NMSTLINCLUDE="-I$with_nmstl/include"
    NMSTLLIB="-L$with_nmstl/lib -lNMSTL -lexpat -lpthread -lreadline -lncurses"
    AC_MSG_RESULT($with_nmstl)
else
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR(Unable to locate NMSTL in $with_nmstl/include and $with_nmstl/lib.)
fi

AC_MSG_CHECKING([whether $NMSTLINCLUDE causes a compiler warning and should be cleared])
AC_LANG([C++])
cppflags_save="$CPPFLAGS"
CPPFLAGS="$CPPFLAGS $NMSTLINCLUDE -Wall -Werror"
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[]], [[]])],[],[NMSTLINCLUDE=""])
if test -z "$NMSTLINCLUDE"; then
    AC_MSG_RESULT([yes])
else
    AC_MSG_RESULT([no])
fi
CPPFLAGS="$cppflags_save"
AC_LANG([C])

AC_MSG_CHECKING([so nmstlinclude is now:])
AC_MSG_RESULT([$NMSTLINCLUDE])

AC_SUBST(NMSTLDIR)
AC_SUBST(NMSTLINCLUDE)
AC_SUBST(NMSTLLIB)
AC_SUBST(NMSTLSUBDIR)
])


AC_NMSTL

AC_MSG_CHECKING([whether to use -DNMSTL_PTR_TRACE])
AC_ARG_ENABLE(ptr-trace,    [  --enable-ptr-trace], [
if test "x$enableval" = "xyes"; then
    AC_MSG_RESULT([yes])
    CXXFLAGS="-DNMSTL_PTR_TRACE $CXXFLAGS"
else
    AC_MSG_RESULT([no])
fi
], [AC_MSG_RESULT([no])])



dnl # --------------------------------------------------
dnl # Usage --disable-messages
AC_MSG_CHECKING([whether to use -DNMSTL_NO_MESSAGES])
AC_ARG_ENABLE(messages,    [  --disable-messages], 
[
    AC_MSG_RESULT([yes])
    CXXFLAGS="-DNMSTL_NO_MESSAGES $CXXFLAGS"
], [AC_MSG_RESULT([no])])


dnl **************************************************
dnl Establish composite libraries and includes.
dnl **************************************************


BOREALISLIB="$NMSTLLIB"
AC_SUBST(BOREALISLIB)

BOREALISINCLUDE="$NMSTLINCLUDE"
AC_SUBST(BOREALISINCLUDE)


AC_CONFIG_FILES([Makefile])
AC_OUTPUT
