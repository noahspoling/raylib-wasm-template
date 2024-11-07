#include "raylib.h"
#include "game.h"
#include "player.h"
#include "map.h"
#include "renderer.h"
#include "config.h"

void GameInit(void) {
    // Initialize game components
    PlayerInit();
    MapInit();
    RendererInit();
}

void GameUpdate(void) {
    // Update game components
    PlayerUpdate();
    // Add more update logic here
}

void GameRender(void) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Render game components
    MapRender();
    PlayerRender();

    EndDrawing();
}

void GameClose(void) {
    // Clean up game components
    PlayerClose();
    MapClose();
    RendererClose();
}