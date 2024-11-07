#!/bin/bash
set -e  # Exit on error

echo "Initializing and updating submodule..."
git submodule update --init --recursive
git submodule update --remote --merge

echo "Entering raylib directory..."
cd lib/raylib

# Clean any previous CMake configurations
echo "Cleaning up previous CMake build artifacts..."
rm -rf build_wasm
mkdir -p build_wasm
cd build_wasm

# Make sure the Emscripten environment is loaded
if ! command -v emcmake &> /dev/null; then
    echo "Error: emcmake not found. Ensure Emscripten SDK is set up."
    exit 1
fi

# Configure CMake explicitly in build_wasm directory
echo "Configuring CMake for WebAssembly..."
emcmake cmake -S .. -B . -DPLATFORM=Web -DBUILD_SHARED_LIBS=OFF -DBUILD_EXAMPLES=OFF -DCMAKE_INSTALL_PREFIX=$(pwd)
if [ $? -ne 0 ]; then
    echo "Error: CMake configuration failed."
    exit 1
fi

# Build with emmake in build_wasm directory
echo "Building raylib for WebAssembly..."
emmake make
if [ $? -ne 0 ]; then
    echo "Error: make failed."
    exit 1
fi

echo "WebAssembly build completed successfully in build_wasm directory."

# Return to the project root directory
cd ../../..
