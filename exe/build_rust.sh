#!/bin/sh

# Build rust
cd ..
cd rust
cd rantools
cargo update
cargo build --release
cp target/release/librantools.a ../lib/
cd ..
cd ..