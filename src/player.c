#include "player.h"
#include "raylib.h"
#include "config.h"

static Vector2 playerPosition;

void PlayerInit(void) {
    playerPosition = (Vector2){ SCREEN_WIDTH/2, SCREEN_HEIGHT/2 };
    
}

void PlayerUpdate(void) {
    // Update player position and state
}

void PlayerRender(void) {
    DrawCircleV(playerPosition, PLAYER_SIZE, RED);
}

void PlayerClose(void) {
    // Clean up player resources if any
}