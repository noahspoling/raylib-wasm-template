#include <raylib.h>
#include "ecs.h"
#include "game.h"
#include "config.h"

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game Instance");

    GameInit();

    while (!WindowShouldClose()) {
        GameUpdate();
        GameRender();
    }

    GameClose();
    CloseWindow();
    return 0;
}