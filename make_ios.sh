#!/bin/sh

# Build rust

cd rust
cd rantools
cargo update
cargo build --target aarch64-apple-ios
cargo build --target x86_64-apple-ios
cargo build --target aarch64-apple-ios --release
cargo build --target x86_64-apple-ios --release
cp ./target/aarch64-apple-ios/release/librantools.a ../lib/ios/librantools.a
cp ./target/x86_64-apple-ios/release/librantools.a ../lib/sim/librantools.a
lipo -create ../lib/ios/librantools.a ../lib/sim/librantools.a -output ../lib/generic/librantools.a
#lipo -info ../lib/generic/librantools.a
cp ./target/aarch64-apple-ios/debug/librantools.a ../lib/ios_debug/librantools.a
cp ./target/x86_64-apple-ios/debug/librantools.a ../lib/sim_debug/librantools.a
lipo -create ../lib/ios_debug/librantools.a ../lib/sim_debug/librantools.a -output ../lib/generic_debug/librantools.a
#lipo -info ../lib/generic_debug/librantools.a
cd ..
cd ..

# Build .a - Release

rm -r ./build.sim
cmake -DWITH_IOS=ON -DWITH_MACOS=OFF -DCMAKE_TOOLCHAIN_FILE=${CMAKE_SOURCE_DIR}toolchains/ios2.cmake -DIOS_PLATFORM=SIMULATOR -H. -Bbuild.sim -GXcode
cmake --build build.sim/ --config Release

rm -r ./build.ios
cmake -DWITH_IOS=ON -DWITH_MACOS=OFF -DCMAKE_TOOLCHAIN_FILE=${CMAKE_SOURCE_DIR}toolchains/ios2.cmake -DIOS_PLATFORM=OS -H. -Bbuild.ios -GXcode
cmake --build build.ios/ --config Release

rm -r ./lib
mkdir -p lib/ios
cp build.ios/Release-iphoneos/libantools.a lib/ios/libantools.a
mkdir -p lib/sim
cp build.sim/Release-iphonesimulator/libantools.a lib/sim/libantools.a
mkdir -p lib/generic
lipo -create "lib/ios/libantools.a" "lib/sim/libantools.a" -output "lib/generic/libantools.a"

# Build .a - Debug

rm -r ./build.sim
cmake -DWITH_DEBUG_SYMBOLS=ON -DWITH_IOS=ON -DWITH_MACOS=OFF -DCMAKE_TOOLCHAIN_FILE=${CMAKE_SOURCE_DIR}toolchains/ios2.cmake -DIOS_PLATFORM=SIMULATOR -H. -Bbuild.sim -GXcode
cmake --build build.sim/ --config Release

rm -r ./build.ios
cmake -DWITH_DEBUG_SYMBOLS=ON -DWITH_IOS=ON -DWITH_MACOS=OFF -DCMAKE_TOOLCHAIN_FILE=${CMAKE_SOURCE_DIR}toolchains/ios2.cmake -DIOS_PLATFORM=OS -H. -Bbuild.ios -GXcode
cmake --build build.ios/ --config Release

mkdir -p lib/ios_debug
cp build.ios/Release-iphoneos/libantools.a lib/ios_debug/libantools.a
mkdir -p lib/sim_debug
cp build.sim/Release-iphonesimulator/libantools.a lib/sim_debug/libantools.a
mkdir -p lib/generic_debug
lipo -create "lib/ios_debug/libantools.a" "lib/sim_debug/libantools.a" -output "lib/generic_debug/libantools.a"

# Clean

rm -r ./build.ios
rm -r ./build.sim

cd ./other_cmake/SweInterface
./make_sweinterface_ios.sh
cd ..
cd ./Swe
./make_swe_ios.sh
cd ..
cd ..