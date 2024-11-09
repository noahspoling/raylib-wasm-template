cd lib/json-c
mkdir -p build_wasm
cd build_wasm
emcmake cmake .. -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=OFF
emmake make
cd ../../..