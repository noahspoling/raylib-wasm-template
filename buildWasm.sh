#!/bin/bash

set -euo pipefail

mkdir -p out_wasm

# Set up Emscripten environment
# source ~/emsdk/emsdk_env.sh  # Update this line if needed

# Compile to WebAssembly
emcc src/main.c -o out/index.html -s USE_GLFW=3 -s ASYNCIFY \
    --shell-file shell.html --preload-file src/resources@src/resources \
    -s TOTAL_STACK=64MB -s INITIAL_MEMORY=128MB -s ASSERTIONS=1 \
    -DPLATFORM_WEB -Ilib/raylib/src lib/raylib/build_wasm/raylib/libraylib.a
