#!/bin/sh
# Create dir
mkdir lib
mkdir lib/generic
mkdir lib/generic_debug
mkdir lib/ios
mkdir lib/ios_debug
mkdir lib/sim
mkdir lib/sim_debug

# Compilation pour iOs - Release
make clean
make ARGUMENTS="-target x86_64-apple-ios-simulator"
cp ./libswe.a ./lib/sim/
make clean
make ARGUMENTS="-target arm64-apple-ios"
cp ./libswe.a ./lib/ios/
lipo -create ./lib/ios/libswe.a ./lib/sim/libswe.a -output ./lib/generic/libswe.a
#lipo -info ./lib/generic/libswe.a

# Compilation pour iOs - Debug
make clean
make ARGUMENTS="-target x86_64-apple-ios-simulator -g"
cp ./libswe.a ./lib/sim_debug/
make clean
make ARGUMENTS="-target arm64-apple-ios -g"
cp ./libswe.a ./lib/ios_debug/
lipo -create ./lib/ios_debug/libswe.a ./lib/sim_debug/libswe.a -output ./lib/generic_debug/libswe.a
#lipo -info ./lib/generic_debug/libswe.a

# Compilation pour Mac Os
make clean
make
rm *.o