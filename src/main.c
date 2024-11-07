#include <raylib.h>
#include "game.h"
#include "config.h"

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "2.5D Wolfenstein Raycasting");

    GameInit();

    while (!WindowShouldClose()) {
        GameUpdate();
        GameRender();
    }

    GameClose();
    CloseWindow();
    return 0;
}