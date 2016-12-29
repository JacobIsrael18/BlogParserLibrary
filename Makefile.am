#===========================
# Makefile.am
# for BlogParserConsumer
# Jacob Israel
#===========================

# programs
# installed
# in the /bin
# directory                List of Targets
bin_PROGRAMS = BlogParserConsumer BlogParserConsumerStatic

#____________________________________
include_HEADERS=BlogParser.h BlogParserProgrammingInterface.h BlogPost.h SimpleHTTP.h SimpleHTTPInterface.h

# Build BlogParserConsumer from BlogParserConsumer.cpp
BlogParserConsumer_SOURCES = BlogParserConsumer.cpp

# dynamic (Shared) library (.so file)
# static library (.a archive)

#___Link BlogParserConsumer against the BlogParser library___
BlogParserConsumer_LDADD = libBlogParser.la

#___Make a statically-linked version of BlogParserConsumer___
BlogParserConsumerStatic_SOURCES = BlogParserConsumer.cpp
BlogParserConsumerStatic_LDADD = libBlogParser.la
BlogParserConsumerStatic_LDFLAGS = -static

#___Building the libtool library___
lib_LTLIBRARIES=libBlogParser.la
libBlogParser_la_SOURCES=BlogParser.cpp BlogPost.cpp SimpleHTTP.cpp

#___Build a plug-in to get symbols with dlopen()___
pkglib_LTLIBRARIES = BlogParserPlugin.la
BlogParserPlugin_la_SOURCES = BlogParser.cpp
BlogParserPlugin_la_LDFLAGS = -avoid-version -module -shared -export-dynamic

#___Set the version for the BlogParser library___
# REVISION   change in the source code of the library that doesn't affect the interface
# CURRENT   change the public interface (header files)
#                                              CURRENT:REVISION:AGE
libBlogParser_la_LDFLAGS=-version-info 0:0:0

# Usually, m4 is chosen as the location for additional Autoconf macros
ACLOCAL_AMFLAGS = -I m4
