/*
 * Copyright (c) 2000, 2019, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#ifndef SHARE_JVMCI_JVMCI_GLOBALS_HPP
#define SHARE_JVMCI_JVMCI_GLOBALS_HPP

#include "runtime/globals.hpp"
class fileStream;

//
// Defines all global flags used by the JVMCI compiler. Only flags that need
// to be accessible to the JVMCI C++ code should be defined here.
//
#define JVMCI_FLAGS(develop, \
                    develop_pd, \
                    product, \
                    product_pd, \
                    diagnostic, \
                    diagnostic_pd, \
                    experimental, \
                    notproduct, \
                    range, \
                    constraint, \
                    writeable) \
                                                                            \
  product(bool, EnableJVMCI, true,                                          \
          "Enable JVMCI")                                                   \
                                                                            \
  product(bool, UseJVMCICompiler, false,                                    \
          "Use JVMCI as the default compiler. Will be true by default "     \
          "if jvmci.Compiler property is set (either on command line or "   \
          "from contents of <java.home>/lib/jvmci/compiler-name")           \
                                                                            \
  product(bool, JVMCIPrintProperties, false,                                \
          "Prints properties used by the JVMCI compiler and exits")         \
                                                                            \
  product(bool, BootstrapJVMCI, false,                                      \
          "Bootstrap JVMCI before running Java main method. This "          \
          "initializes the compile queue with a small set of methods "      \
          "and processes the queue until it is empty. Combining this with " \
          "-XX:-TieredCompilation makes JVMCI compile more of itself.")     \
                                                                            \
  product(bool, EagerJVMCI, false,                                          \
          "Force eager JVMCI initialization")                               \
                                                                            \
  product(bool, PrintBootstrap, true,                                       \
          "Print JVMCI bootstrap progress and summary")                     \
                                                                            \
  product(intx, JVMCIThreads, 1,                                            \
          "Force number of JVMCI compiler threads to use. Ignored if "      \
          "UseJVMCICompiler is false.")                                     \
          range(1, max_jint)                                                \
                                                                            \
  product(intx, JVMCIHostThreads, 1,                                        \
          "Force number of C1 compiler threads. Ignored if "                \
          "UseJVMCICompiler is false.")                                     \
          range(1, max_jint)                                                \
                                                                            \
  NOT_COMPILER2(product(intx, MaxVectorSize, 64,                            \
          "Max vector size in bytes, "                                      \
          "actual size could be less depending on elements type"))          \
                                                                            \
  NOT_COMPILER2(product(bool, ReduceInitialCardMarks, true,                 \
          "Defer write barriers of young objects"))                         \
                                                                            \
  product(intx, JVMCITraceLevel, 0,                                         \
          "Trace level for JVMCI: "                                         \
          "1 means emit a message for each CompilerToVM call,"              \
          "levels greater than 1 provide progressively greater detail")     \
                                                                            \
  product(intx, JVMCICounterSize, 0,                                        \
          "Reserved size for benchmark counters")                           \
          range(0, max_jint)                                                \
                                                                            \
  product(bool, JVMCICountersExcludeCompiler, true,                         \
          "Exclude JVMCI compiler threads from benchmark counters")         \
                                                                            \
  develop(bool, JVMCIUseFastLocking, true,                                  \
          "Use fast inlined locking code")                                  \
                                                                            \
  product(intx, JVMCINMethodSizeLimit, (80*K)*wordSize,                     \
          "Maximum size of a compiled method.")                             \
                                                                            \
  product(intx, MethodProfileWidth, 0,                                      \
          "Number of methods to record in call profile")                    \
                                                                            \
  product(ccstr, JVMCILibPath, NULL,                                        \
          "LD path for loading the JVMCI shared library")                   \
                                                                            \
  product(ccstr, JVMCILibDumpJNIConfig, NULL,                               \
          "Dumps to the given file a description of the classes, fields "   \
          "and methods the JVMCI shared library must provide")              \
                                                                            \
  product(bool, UseJVMCINativeLibrary, false,                               \
          "Execute JVMCI Java code from a shared library "                  \
          "instead of loading it from class files and executing it "        \
          "on the HotSpot heap")                                            \
                                                                            \
  NOT_COMPILER2(diagnostic(bool, UseMultiplyToLenIntrinsic, false,          \
          "Enables intrinsification of BigInteger.multiplyToLen()"))        \
                                                                            \
  NOT_COMPILER2(diagnostic(bool, UseSquareToLenIntrinsic, false,            \
          "Enables intrinsification of BigInteger.squareToLen()"))          \
                                                                            \
  NOT_COMPILER2(diagnostic(bool, UseMulAddIntrinsic, false,                 \
          "Enables intrinsification of BigInteger.mulAdd()"))               \
                                                                            \
  NOT_COMPILER2(diagnostic(bool, UseMontgomeryMultiplyIntrinsic, false,     \
          "Enables intrinsification of BigInteger.montgomeryMultiply()"))   \
                                                                            \
  NOT_COMPILER2(diagnostic(bool, UseMontgomerySquareIntrinsic, false,       \
          "Enables intrinsification of BigInteger.montgomerySquare()"))

JVMCI_FLAGS(DECLARE_DEVELOPER_FLAG, \
            DECLARE_PD_DEVELOPER_FLAG, \
            DECLARE_PRODUCT_FLAG, \
            DECLARE_PD_PRODUCT_FLAG, \
            DECLARE_DIAGNOSTIC_FLAG, \
            DECLARE_PD_DIAGNOSTIC_FLAG, \
            DECLARE_EXPERIMENTAL_FLAG, \
            DECLARE_NOTPRODUCT_FLAG, \
            IGNORE_RANGE, \
            IGNORE_CONSTRAINT, \
            IGNORE_WRITEABLE)

// The base name for the shared library containing the JVMCI based compiler
#define JVMCI_SHARED_LIBRARY_NAME "jvmcicompiler"

class JVMCIGlobals {
 private:
  static fileStream* _jni_config_file;
 public:

  // Returns true if jvmci flags are consistent. If not consistent,
  // an error message describing the inconsistency is printed before
  // returning false.
  static bool check_jvmci_flags_are_consistent();

  // Check and exit VM with error if selected GC is not supported by JVMCI.
  static void check_jvmci_supported_gc();

  static fileStream* get_jni_config_file() { return _jni_config_file; }
};
#endif // SHARE_JVMCI_JVMCI_GLOBALS_HPP
