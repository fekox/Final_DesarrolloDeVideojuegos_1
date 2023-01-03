#include "raylib.h"

#include "Window/PlayGame.h"

#include "Objects/Player.h"

void PlayerMovement(Player& player);
void PlayerJump(Player& player);

Player player;

void StartGame()
{
    int screenWidth = 1024;
    int screenHeight = 768;

    InitGame(screenWidth, screenHeight);

    GameLoop();

    QuitGame();
}

void InitGame(int screenWidth, int screenHeight)
{
    InitWindow(screenWidth, screenHeight, "Pingu Climber V0.1");

    //Player

    player = CreatePlayer(screenWidth, screenHeight);
}

void GameLoop()
{
    SetExitKey(NULL);

    while (!WindowShouldClose())
    {
        Update();

        Draw();
    }
}

void Update()
{
    PlayerMovement(player);
    Collisions();
}

void Collisions()
{
    PlayerCollisionLimit(player, GetScreenWidth(), GetScreenHeight());
}

void Draw()
{
    BeginDrawing();

    ClearBackground(BLACK);

    DrawPlayer(player);

    EndDrawing();
}

void QuitGame()
{
    CloseWindow();
}

void PlayerMovement(Player& players)
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
            PlayerJump(players);
        }

        if (players.isJumping == true)
        {
            players.gravity = players.gravity + players.jumpForce * GetFrameTime();
            players.pos.y = players.pos.y + players.gravity * GetFrameTime();
        }
    }
}

void PlayerJump(Player& players)
{
    players.gravity = -250;
    players.pos.y = players.pos.y + players.gravity * GetFrameTime();

    if (players.pos.y < 650)
    {
        players.isJumping = true;
    }
}