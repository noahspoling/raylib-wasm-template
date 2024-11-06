#include "raylib.h"

int main(void) {
    InitWindow(512, 512, "Raylib WASM Example");
    Texture2D texture = LoadTexture("src/resources/smile.png");
    Vector2 position = {0.0f, 0.0f};

    while (!WindowShouldClose()) {

        if(IsKeyDown(KEY_RIGHT)) position.x += 2.0f;
        if(IsKeyDown(KEY_LEFT)) position.x -= 2.0f;
        if(IsKeyDown(KEY_DOWN)) position.y += 2.0f;
        if(IsKeyDown(KEY_UP)) position.y -= 2.0f;
        BeginDrawing();
        ClearBackground(BLUE);
        DrawTexture(texture, 0, 0, WHITE);
        DrawText("Move the image with arrow keys", 10, 10, 20, DARKGRAY);
        DrawText("Press [ESC] to close the window", 10, 30, 20, DARKGRAY);
        DrawCircleV(position, 10, RED);
        EndDrawing();
    }

    UnloadTexture(texture);
    CloseWindow();
    return 0;
}
