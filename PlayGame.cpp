#include "raylib.h"

#include "Window/PlayGame.h"

void startGame()
{
    int screenWidth = 1024;
    int screenHeight = 768;

    initGame(screenWidth, screenHeight);

    gameLoop();

    quitGame();
}

void initGame(int screenWidth, int screenHeight)
{
    InitWindow(screenWidth, screenHeight, "Pingu Climber V0.1");
}

void gameLoop()
{
    SetExitKey(NULL);

    while (!WindowShouldClose())
    {
        update();

        draw();
    }
}

void update()
{

}

void draw()
{
    BeginDrawing();

    ClearBackground(RAYWHITE);

    EndDrawing();
}

void quitGame()
{
    CloseWindow();
}