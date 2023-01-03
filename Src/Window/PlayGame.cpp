#include "raylib.h"

#include "Window/PlayGame.h"

#include "Objects/Player.h"
#include "Objects/Platform.h"

//Collisions
bool CheckCollisionRecRec(Vector2 r1, float r1w, float r1h, Vector2 r2, float r2w, float r2h);
void PlayerCollision();

//Movement
void PlayerMovement(Player& player);
void PlayerJump(Player& player);

Player player;

Platform platform;

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

    //Platform
    platform = CreatePlatform(screenWidth, screenHeight);
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
    PlayerCollision();
}

void Draw()
{
    BeginDrawing();

    ClearBackground(BLACK);

    DrawPlatform(platform);

    DrawPlayer(player);

    EndDrawing();
}

void QuitGame()
{
    CloseWindow();
}

bool CheckCollisionRecRec(Vector2 r1, float r1w, float r1h, Vector2 r2, float r2w, float r2h)
{
    if (r1.x + r1w >= r2.x &&
        r1.x <= r2.x + r2w &&
        r1.y + r1h >= r2.y &&
        r1.y <= r2.y + r2h)
    {
        return true;
    }
    return false;
}

void PlayerCollision()
{
    if (CheckCollisionRecRec(player.pos, player.width, player.height, platform.pos, platform.width, platform.height))
    {
        player.isJumping = false;
        player.gravity = 0;
    }
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

        if (players.isJumping == true && player.pos.y < platform.pos.y)
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