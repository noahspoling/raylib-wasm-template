#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct Player {
    Vector2 position;
    Vector2 speed;
    float radius;
    Color color;
} Player;

void PlayerInit(void);
void PlayerUpdate(void);
void PlayerRender(void);
void PlayerClose(void);

#endif // PLAYER_H