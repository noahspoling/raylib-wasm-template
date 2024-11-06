#!/bin/bash
cd lib/raylib
mkdir -p build_wasm
cd build_wasm

emcmake cmake .. -DPLATFORM=Web -DBUILD_SHARED_LIBS=OFF -DBUILD_EXAMPLES=OFF
emmake make

cd ../..
