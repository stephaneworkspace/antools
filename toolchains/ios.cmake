# This file is part of the ios-cmake project. It was retrieved from
# https://github.com/leetal/ios-cmake.git, which is a fork of
# https://github.com/gerstrong/ios-cmake.git, which is a fork of
# https://github.com/cristeab/ios-cmake.git, which is a fork of
# https://code.google.com/p/ios-cmake/. Which in turn is based off of
# the Platform/Darwin.cmake and Platform/UnixPaths.cmake files which
# are included with CMake 2.8.4
#
# The ios-cmake project is licensed under the new BSD license.
#
# Copyright (c) 2014, Bogdan Cristea and LTE Engineering Software,
# Kitware, Inc., Insight Software Consortium.  All rights reserved.
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright
# notice, this list of conditions and the following disclaimer in the
# documentation and/or other materials provided with the distribution.
#
# 3. Neither the name of the copyright holder nor the names of its
# contributors may be used to endorse or promote products derived from
# this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
# This file is based off of the Platform/Darwin.cmake and
# Platform/UnixPaths.cmake files which are included with CMake 2.8.4
# It has been altered for iOS development.
#
# Updated by Alex Stewart (alexs.mac@gmail.com)
#
# *****************************************************************************
#      Now maintained by Alexander Widerberg (widerbergaren [at] gmail.com)
#                      under the BSD-3-Clause license
#                   https://github.com/leetal/ios-cmake
# *****************************************************************************
#
#                           INFORMATION / HELP
#
###############################################################################
#                                  OPTIONS                                    #
###############################################################################
#
# PLATFORM: (default "OS64")
#    OS = Build for iPhoneOS.
#    OS64 = Build for arm64 iphoneOS.
#    OS64COMBINED = Build for arm64 x86_64 iphoneOS + iphoneOS Simulator. Combined into FAT STATIC lib (only supported on 3.14+ of CMake with "-G Xcode" argument in combination with the "cmake --install" CMake build step)
#    SIMULATOR = Build for x86 i386 iphoneOS Simulator.
#    SIMULATOR64 = Build for x86_64 iphoneOS Simulator.
#    SIMULATORARM64 = Build for arm64 iphoneOS Simulator.
#    TVOS = Build for arm64 tvOS.
#    TVOSCOMBINED = Build for arm64 x86_64 tvOS + tvOS Simulator. Combined into FAT STATIC lib (only supported on 3.14+ of CMake with "-G Xcode" argument in combination with the "cmake --install" CMake build step)
#    SIMULATOR_TVOS = Build for x86_64 tvOS Simulator.
#    WATCHOS = Build for armv7k arm64_32 for watchOS.
#    WATCHOSCOMBINED = Build for armv7k arm64_32 x86_64 watchOS + watchOS Simulator. Combined into FAT STATIC lib (only supported on 3.14+ of CMake with "-G Xcode" argument in combination with the "cmake --install" CMake build step)
#    SIMULATOR_WATCHOS = Build for x86_64 for watchOS Simulator.
#    MAC = Build for x86_64 macOS.
#    MAC_ARM64 = Build for Apple Silicon macOS.
#    MAC_CATALYST = Build for x86_64 macOS with Catalyst support (iOS toolchain on macOS).
#                   Note: The build argument "MACOSX_DEPLOYMENT_TARGET" can be used to control min-version of macOS
#    MAC_CATALYST_ARM64 = Build for Apple Silicon macOS with Catalyst support (iOS toolchain on macOS).
#                         Note: The build argument "MACOSX_DEPLOYMENT_TARGET" can be used to control min-version of macOS
#
# CMAKE_OSX_SYSROOT: Path to the SDK to use.  By default this is
#    automatically determined from PLATFORM and xcodebuild, but
#    can also be manually specified (although this should not be required).
#
# CMAKE_DEVELOPER_ROOT: Path to the Developer directory for the platform
#    being compiled for.  By default this is automatically determined from
#    CMAKE_OSX_SYSROOT, but can also be manually specified (although this should
#    not be required).
#
# DEPLOYMENT_TARGET: Minimum SDK version to target. Default 2.0 on watchOS and 9.0 on tvOS+iOS
#
# NAMED_LANGUAGE_SUPPORT:
#    ON (default) = Will require "enable_language(OBJC) and/or enable_language(OBJCXX)" for full OBJC|OBJCXX support
#    OFF = Will embed the OBJC and OBJCXX flags into the CMAKE_C_FLAGS and CMAKE_CXX_FLAGS (legacy behaviour, CMake version < 3.16)
#
# ENABLE_BITCODE: (ON|OFF) Enables or disables bitcode support. Default ON
#
# ENABLE_ARC: (ON|OFF) Enables or disables ARC support. Default ON (ARC enabled by default)
#
# ENABLE_VISIBILITY: (ON|OFF) Enables or disables symbol visibility support. Default OFF (visibility hidden by default)
#
# ENABLE_STRICT_TRY_COMPILE: (ON|OFF) Enables or disables strict try_compile() on all Check* directives (will run linker
#    to actually check if linking is possible). Default OFF (will set CMAKE_TRY_COMPILE_TARGET_TYPE to STATIC_LIBRARY)
#
# ARCHS: (armv7 armv7s armv7k arm64 arm64_32 i386 x86_64) If specified, will override the default architectures for the given PLATFORM
#    OS = armv7 armv7s arm64 (if applicable)
#    OS64 = arm64 (if applicable)
#    SIMULATOR = i386
#    SIMULATOR64 = x86_64
#    SIMULATORARM64 = arm64
#    TVOS = arm64
#    SIMULATOR_TVOS = x86_64 (i386 has since long been deprecated)
#    WATCHOS = armv7k arm64_32 (if applicable)
#    SIMULATOR_WATCHOS = x86_64 (i386 has since long been deprecated)
#    MAC = x86_64
#    MAC_ARM64 = arm64
#    MAC_CATALYST = x86_64
#    MAC_CATALYST_ARM64 = arm64
#
# NOTE: When manually specifying ARCHS, put a semi-colon between the entries. E.g., -DARCHS="armv7;arm64"
#
###############################################################################
#                                END OPTIONS                                  #
###############################################################################
#
# This toolchain defines the following properties (available via get_property()) for use externally:
#
# PLATFORM: The currently targeted platform.
# XCODE_VERSION: Version number (not including Build version) of Xcode detected.
# SDK_VERSION: Version of SDK being used.
# OSX_ARCHITECTURES: Architectures being compiled for (generated from PLATFORM).
# APPLE_TARGET_TRIPLE: Used by autoconf build systems. NOTE: If "ARCHS" are overridden, this will *NOT* be set!
#
# This toolchain defines the following macros for use externally:
#
# set_xcode_property (TARGET XCODE_PROPERTY XCODE_VALUE XCODE_VARIANT)
#   A convenience macro for setting xcode specific properties on targets.
#   Available variants are: All, Release, RelWithDebInfo, Debug, MinSizeRel
#   example: set_xcode_property (myioslib IPHONEOS_DEPLOYMENT_TARGET "3.1" "all").
#
# find_host_package (PROGRAM ARGS)
#   A macro used to find executable programs on the host system, not within the
#   environment. Thanks to the android-cmake project for providing the
#   command.
#

cmake_minimum_required(VERSION 3.8.0)

# CMake invokes the toolchain file twice during the first build, but only once during subsequent rebuilds.
if(DEFINED ENV{_IOS_TOOLCHAIN_HAS_RUN})
    return()
endif()
set(ENV{_IOS_TOOLCHAIN_HAS_RUN} true)

# List of supported platform values
list(APPEND _supported_platforms
        "OS" "OS64" "OS64COMBINED" "SIMULATOR" "SIMULATOR64" "SIMULATORARM64"
        "TVOS" "TVOSCOMBINED" "SIMULATOR_TVOS"
        "WATCHOS" "WATCHOSCOMBINED" "SIMULATOR_WATCHOS"
        "MAC" "MAC_ARM64"
        "MAC_CATALYST" "MAC_CATALYST_ARM64")

# Cache what generator is used
set(USED_CMAKE_GENERATOR "${CMAKE_GENERATOR}")

# Check if using a CMake version capable of building combined FAT builds (simulator and target slices combined in one static lib)
if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.14")
    set(MODERN_CMAKE YES)
endif()

# Get the Xcode version being used.
# Problem: CMake runs toolchain files multiple times, but can't read cache variables on some runs.
# Workaround: On first run (in which cache variables are always accessible), set an intermediary environment variable.
#
# NOTE: This pattern is used i many places in this toolchain to speed up checks of all sorts
if(DEFINED XCODE_VERSION_INT)
    # Environment variables are always preserved.
    set(ENV{_XCODE_VERSION_INT} "${XCODE_VERSION_INT}")
elseif(DEFINED ENV{_XCODE_VERSION_INT})
    set(XCODE_VERSION_INT "$ENV{_XCODE_VERSION_INT}")
elseif(NOT DEFINED XCODE_VERSION_INT)
    find_program(XCODEBUILD_EXECUTABLE xcodebuild)
    if(NOT XCODEBUILD_EXECUTABLE)
        message(FATAL_ERROR "xcodebuild not found. Please install either the standalone commandline tools or Xcode.")
    endif()
    execute_process(COMMAND ${XCODEBUILD_EXECUTABLE} -version
            OUTPUT_VARIABLE XCODE_VERSION_INT
            ERROR_QUIET
            OUTPUT_STRIP_TRAILING_WHITESPACE)
    string(REGEX MATCH "Xcode [0-9\\.]+" XCODE_VERSION_INT "${XCODE_VERSION_INT}")
    string(REGEX REPLACE "Xcode ([0-9\\.]+)" "\\1" XCODE_VERSION_INT "${XCODE_VERSION_INT}")
    set(XCODE_VERSION_INT "${XCODE_VERSION_INT}" CACHE INTERNAL "")
endif()

# Assuming that xcode 12.0 is installed you most probably have ios sdk 14.0 or later installed (tested on Big Sur)
# if you don't set a deployment target it will be set the way you only get 64-bit builds
if(NOT DEFINED DEPLOYMENT_TARGET AND XCODE_VERSION_INT VERSION_GREATER 12.0)
    # Temporarily fix the arm64 issues in CMake install-combined by excluding arm64 for simulator builds (needed for Apple Silicon...)
    set(CMAKE_XCODE_ATTRIBUTE_EXCLUDED_ARCHS[sdk=iphonesimulator*] "arm64")
endif()

# Check if the platform variable is set
if(DEFINED PLATFORM)
    # Environment variables are always preserved.
    set(ENV{_PLATFORM} "${PLATFORM}")
elseif(DEFINED ENV{_PLATFORM})
    set(PLATFORM "$ENV{_PLATFORM}")
elseif(NOT DEFINED PLATFORM)
    message(FATAL_ERROR "PLATFORM argument not set. Bailing configure since I don't know what target you want to build for!")
endif ()