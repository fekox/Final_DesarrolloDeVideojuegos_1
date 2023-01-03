#include "raylib.h"

#include "Window/PlayGame.h"

void startGame()
{
    int screenWidth = 1024;
    int screenHeight = 768;

    InitWindow(screenWidth, screenHeight, "Pingu Climber V0.1");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Update

        // Draw
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
}