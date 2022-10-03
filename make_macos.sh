#!/bin/sh

# Build rust

cd rust
cd rantools
cargo update
cargo build --release
cp target/release/librantools.a ../lib/
cd ..
cd ..

# Build exe

rm -rf build
mkdir build
cmake -DWITH_IOS=OFF -DWITH_MACOS=ON
cmake . -B build
cd build
make
cp antools ../
cd ..
rm -rf build
chmod +x antools
./antools