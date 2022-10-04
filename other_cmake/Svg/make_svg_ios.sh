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
cp ./libSvg.a ./lib/sim/
make clean
make ARGUMENTS="-target arm64-apple-ios"
cp ./libSvg.a ./lib/ios/
make clean
lipo -create ./lib/ios/libSvg.a ./lib/sim/libSvg.a -output ./lib/generic/libSvg.a
#lipo -info ./lib/generic/libSvg.a
rm *.o

# Compilation pour iOs - Debug
make clean
make ARGUMENTS="-target x86_64-apple-ios-simulator -g"
cp ./libSvg.a ./lib/sim_debug/
make clean
make ARGUMENTS="-target arm64-apple-ios -g"
cp ./libSvg.a ./lib/ios_debug/
make clean
lipo -create ./lib/ios_debug/libSvg.a ./lib/sim_debug/libSvg.a -output ./lib/generic_debug/libSvg.a
#lipo -info ./lib/generic_debug/libSvg.a
rm *.o

# Compilation pour Mac Os
make clean
make
rm *.o