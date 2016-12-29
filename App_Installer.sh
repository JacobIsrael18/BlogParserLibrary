#!/bin/sh
#===========================
#  App_Installer.sh
#
# Usage:
# Open a Terminal and move to the directory (cd) with these files
#  chmod a+x App_Installer.sh   <press enter>
#  ./App_Installer.sh                  <press enter>
#
# After several seconds, you will be asked to enter your password
#
#  Created by Jacob Israel on 12/28/16.
#===========================
touch AUTHORS README NEWS COPYING INSTALL ChangeLog
autoreconf -i
autoconf
automake
./configure
make
sudo make install
# make dist

# First Test:
echo
echo ____Testing Dynamic Library____
./BlogParserConsumer

# Second Test:
echo
echo ____Testing Static Library____
./BlogParserConsumerStatic

