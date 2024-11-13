#ifndef TEXUREATLAS_H
#define TEXUREATLAS_H

#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"

typedef struct {
    Texture2D *textures;
    int count;
} TextureAtlas;

TextureAtlas LoadTextureAtlas(const char *filePath, int rows, int cols);
void UnloadTextureAtlas(TextureAtlas atlas);

#endif // TEXUREATLAS_H
