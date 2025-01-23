check_PROGRAMS = loggerTest

TESTS = $(check_PROGRAMS)

EXTRA_DIST = autogen.sh

ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}
AM_MAKEFLAGS = --no-print-directory

AM_CXXFLAGS =\
						 -include $(top_builddir)/config.h \
						 -I${top_srcdir}/src \
						 $(WARN_CXXFLAGS)

AM_LDFLAGS = $(WARN_LDFLAGS)


loggerTest_SOURCES =\
										./src/nlogger.hpp \
										./test/loggerTest.cpp
loggerTest_LDADD = $(CRITERION_LIBS) $(Modtorio_LDADD)
