#
# ----------------------------------------------------------------------------------------------------
#
# Copyright (c) 2016, Oracle and/or its affiliates. All rights reserved.
# DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
#
# This code is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License version 2 only, as
# published by the Free Software Foundation.
#
# This code is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
# version 2 for more details (a copy is included in the LICENSE file that
# accompanied this code).
#
# You should have received a copy of the GNU General Public License version
# 2 along with this work; if not, write to the Free Software Foundation,
# Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
#
# Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
# or visit www.oracle.com if you need additional information or have any
# questions.
#
# ----------------------------------------------------------------------------------------------------

#pylint: disable=missing-docstring
#pylint: disable=line-too-long
#pylint: disable=invalid-name

import sys
import os
import os.path
import glob
import sys

conf = sys.argv[1]

# Check for the existence of static libs
static_libs = glob.glob(os.path.join('build', '*' + conf, 'images', 'static-libs', 'lib', '*'))

if not len(static_libs):
    sys.exit('Building static jdk-libs did not succeed.')

print('Successfully built static jdk-libs:')
print('\n'.join(os.path.basename(lib) for lib in static_libs))
