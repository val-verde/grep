#! /bin/sh
# Regression test for GNU grep.
#
# Copyright (C) 2001, 2006, 2009-2010 Free Software Foundation, Inc.
#
# Copying and distribution of this file, with or without modification,
# are permitted in any medium without royalty provided the copyright
# notice and this notice are preserved.

. "${srcdir=.}/init.sh"; path_prepend_ ../src

fail=0

# . . . and the following by Henry Spencer.

${AWK-awk} -f $abs_top_srcdir/tests/bre.awk $abs_top_srcdir/tests/bre.tests \
    > bre.script || fail=1

. ./bre.script || fail=1

Exit $fail
