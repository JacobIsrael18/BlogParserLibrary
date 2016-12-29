#===========================
# confugure.ac
# for BlogParserConsumer
# Jacob Israel

#__Install Steps:_____
# autoreconf -i
# autoconf
# automake
# ./configure
# make
# sudo make install
# make dist ???

# First Test:
# ./BlogParserConsumer

# Second Test:
# ./BlogParserConsumerStatic

# Third Test:
# cd .libs/
# ./BlogParserConsumer
#===========================
# autoreconf runs:
# autoconf, autoheader, aclocal, automake, libtoolize and autopoint

AC_INIT([BlogParserConsumer], [0.01])

AC_CONFIG_MACRO_DIRS([m4])

# Used to set a C header file ( .h) containing ‘#define’ directives
# Usually the input file is named header.in
# AC_CONFIG_HEADERS([defines.h])

# build a shared library
# AC_DISABLE_STATIC

m4_ifdef([AM_PROG_AR], [AM_PROG_AR])

# The LT_INIT macro adds many new tests to the configure script so that
# the generated libtool script will understand the characteristics of the host.
# AC_PROG_LIBTOOL and AM_PROG_LIBTOOL are deprecated names for older versions of this macro
# AC_LIBTOOL_DLOPEN  and AC_LIBTOOL_WIN32_DLL are also deprecated
LT_INIT

#  Used to turn off shared libraries
#  LT_INIT([disable-shared])

# Search for a C++ compiler / Add C++ language support to Libtool
# Same as using LT_LANG([C++])
AC_PROG_CXX

# Require headers
AC_CHECK_HEADERS(string.h)
AC_CHECK_HEADERS(strings.h)

AC_CONFIG_SRCDIR([BlogParserConsumer.cpp])
#       AC_CONFIG_AUXDIR([buildFolder])

# Required version of autoconf
AM_INIT_AUTOMAKE([1.15 -Wall -Werror])
AC_CONFIG_FILES([makefile])

# SUBDIRS = src

# build-aux is usually the location for auxiliary build tools

AC_OUTPUT
