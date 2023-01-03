#include "raylib.h"

#include "Window/PlayGame.h"

#include "Objects/Player.h"

Player player;

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

    //Player

    player = createPlayer(screenWidth, screenHeight);
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

    drawPlayer(player);

    EndDrawing();
}

void quitGame()
{
    CloseWindow();
}