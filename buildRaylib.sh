#!/bin/bash

cd lib/raylib
emcmake cmake .. -DBUILD_EXAMPLES=OFF -DBUILD_SHARED_LIBS=OFF -DPLATFORM=Web
emmake make
cd ../../..
