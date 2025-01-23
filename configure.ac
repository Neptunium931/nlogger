AC_PREREQ(2.60)
AC_INIT([nlogger],
	[0.0.1],
	[tymothe_billerey@fastmail.fr],
	[nlogger],
	[https://github.com/Neptunium931/nlogger])

AC_CONFIG_SRCDIR([src/nlogger.hpp])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([
		  foreign
		  -Wall
		  silent-rules
		  subdir-objects
      -Werror
])


AC_PROG_CXX
AX_CXX_COMPILE_STDCXX(23, ext, mandatory)
AC_USE_SYSTEM_EXTENSIONS

AX_COMPILER_FLAGS

AM_SILENT_RULES([yes])

AC_CONFIG_HEADERS(config.h)
AC_CONFIG_FILES([Makefile])

PKG_CHECK_MODULES([CRITERION], [criterion], [], [
                   AC_MSG_ERROR([unable to find Criterion])
                   ])
AC_SUBST([CRITERION_CFLAGS])
AC_SUBST([CRITERION_LIBS])


AC_OUTPUT
AC_MSG_RESULT([
	$PACKAGE $VERSION
	====================
	host:		${host}
	prefix:		${prefix}
	compiler:	${CXX}
	cxxflags:		${CXXFLAGS}
	ldflags:	${LDFLAGS}
])
