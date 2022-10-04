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
cp ./libSweInterface.a ./lib/sim/
make clean
make ARGUMENTS="-target arm64-apple-ios"
cp ./libSweInterface.a ./lib/ios/
make clean
lipo -create ./lib/ios/libSweInterface.a ./lib/sim/libSweInterface.a -output ./lib/generic/libSweInterface.a
#lipo -info ./lib/generic/libSweInterface.a
rm *.o

# Compilation pour iOs - Debug
make clean
make ARGUMENTS="-target x86_64-apple-ios-simulator -g"
cp ./libSweInterface.a ./lib/sim_debug/
make clean
make ARGUMENTS="-target arm64-apple-ios -g"
cp ./libSweInterface.a ./lib/ios_debug/
make clean
lipo -create ./lib/ios_debug/libSweInterface.a ./lib/sim_debug/libSweInterface.a -output ./lib/generic_debug/libSweInterface.a
#lipo -info ./lib/generic_debug/libSweInterface.a
rm *.o

# Compilation pour Mac Os
make clean
make
rm *.o