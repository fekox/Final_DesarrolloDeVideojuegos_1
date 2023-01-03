#include "raylib.h"

#include "Window/PlayGame.h"

#include "Objects/Player.h"

void playerMovement(Player& player);
void playerJump(Player& player);

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
    playerMovement(player);
    collisions();
}

void collisions()
{
    playerCollisionLimit(player, GetScreenWidth(), GetScreenHeight());
}

void draw()
{
    BeginDrawing();

    ClearBackground(BLACK);

    drawPlayer(player);

    EndDrawing();
}

void quitGame()
{
    CloseWindow();
}

void playerMovement(Player& players)
{
    if (players.isActive == true)
    {
        if (IsKeyDown(KEY_A))
        {
            players.pos.x -= players.speed * GetFrameTime();
        }

        if (IsKeyDown(KEY_D))
        {
            players.pos.x += players.speed * GetFrameTime();
        }

        if (IsKeyDown(KEY_W) && players.isJumping == false)
        {
            playerJump(players);
        }

        if (players.isJumping == true)
        {
            players.gravity = players.gravity + players.jumpForce * GetFrameTime();
            players.pos.y = players.pos.y + players.gravity * GetFrameTime();
        }
    }
}

void playerJump(Player& players)
{
    players.gravity = -250;
    players.pos.y = players.pos.y + players.gravity * GetFrameTime();

    if (players.pos.y < 650)
    {
        players.isJumping = true;
    }
}