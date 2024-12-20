#!/bin/bash

set -euo pipefail
mkdir -p out_wasm

SRC_FILES=$(find src -name '*.c') # Recursively find all .c files in src directory
SRC_FILES+=" $(find src/game -name '*.c')" # Recursively find all .c files in src/game directory

OUT_DIR="out_wasm"


# Set up Emscripten environment
# source ~/emsdk/emsdk_env.sh  # Update this line if needed

# Check if resources folder exists
PRELOAD_OPTION=""
if [ -d "src/resources@/resources" ]; then
    PRELOAD_OPTION="--preload-file resources"
fi

cp app/styles.css $OUT_DIR
cp app/components/SidebarComponent.js $OUT_DIR
cp app/components/menus/InventoryMenu.js $OUT_DIR
cp app/components/modals/ModalComponent.js $OUT_DIR
cp app/components/panels/SidePanelComponent.js $OUT_DIR

# Compile to WebAssembly
emcc $SRC_FILES -o $OUT_DIR/index.html \
    -Ilib/raylib/src \
    lib/raylib/build_wasm/raylib/libraylib.a \
    lib/json-c/build_wasm/libjson-c.a \
    -s USE_GLFW=3 \
    -s FULL_ES2=1 \
    -s ALLOW_MEMORY_GROWTH=1 \
    -s ASYNCIFY \
    -s EXPORTED_FUNCTIONS='["_main", "_GameInit", "_GameUpdate", "_GameRender", "_GameClose"]' \
    -s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' \
    --shell-file app/shell.html \
    $PRELOAD_OPTION

echo "Build complete. Output in $OUT_DIR"
