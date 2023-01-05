#include <iostream>

#include "raylib.h"

#include "Window/PlayGame.h"

#include "Objects/Player.h"
#include "Objects/Ground.h"
#include "Objects/Platform.h"
#include "Objects/Wall.h"

using namespace std;

//Collisions
bool CheckCollisionRecRec(Vector2 r1, float r1w, float r1h, Vector2 r2, float r2w, float r2h);
void PlayerCollision();

//Movement
void PlayerMovement(Player& player);
void PlayerJump(Player& player);

Player player;
float cont = 0.6f;

int const maxPlatforms = 5;
Platform platform[maxPlatforms];

int const maxWalls = 2;
Wall wall[maxWalls];


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

    //Platforms level 1
    for (int i = 0; i < maxPlatforms; i++)
    {
        platform[i] = CreatePlatform();
    }
    platform[0].pos.x = static_cast<float>(screenWidth / screenWidth);
    platform[0].pos.y = static_cast<float>(screenHeight / 1.1f);
    platform[0].width = static_cast<float>(screenWidth);
    platform[0].height = 70;

    platform[1].pos.x = static_cast<float>(screenWidth / 5);
    platform[1].pos.y = static_cast<float>(screenHeight / 1.5);

    platform[2].pos.x = static_cast<float>(screenWidth / 2);
    platform[2].pos.y = static_cast<float>(screenHeight / 2);

    platform[3].pos.x = static_cast<float>(screenWidth / 3.8);
    platform[3].pos.y = static_cast<float>(screenHeight / 4);

    platform[4].pos.x = static_cast<float>(screenWidth / 1.7);
    platform[4].pos.y = static_cast<float>(screenHeight / 10);

    //Wall
    for (int i = 0; i < maxWalls; i++)
    {
        wall[i] = CreateWall();
    }
    //Right Wall
    wall[0].pos.x = static_cast<float>(screenWidth / 1.25f);
    wall[0].pos.y = -2;

    wall[0].width = 40;
    wall[0].height = 770;

    //Left Wall
    wall[1].pos.x = static_cast<float>(screenWidth / 6);
    wall[1].pos.y = -2;

    wall[1].width = 40;
    wall[1].height = 770;
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
    PlayerCollisionLimitLeft(player, wall[0]);
    PlayerCollisionLimitRight(player, wall[1]);
    PlayerCollisionLimitUpAndDown(player, GetScreenHeight());
    
    PlayerCollision();
}

void Draw()
{
    BeginDrawing();

    ClearBackground(BLACK);

    for (int i = 0; i < maxPlatforms; i++)
    {
        if (platform[i].isActive == true)
        {
            DrawPlatform(platform[i]);
        }
    }

    DrawPlayer(player);

    for (int i = 0; i < maxWalls; i++)
    {
        DrawWall(wall[i]);
    }

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
    for (int i = 0; i < maxPlatforms; i++)
    {
        if (platform[i].isActive == true)
        {
            if (CheckCollisionRecRec(player.pos, player.width, player.height, platform[i].pos, platform[i].width, platform[i].height))
            {
                player.gravity = 0;
                player.canJump = true;
                cont = 0.6f;
            }
        }
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

        if (IsKeyDown(KEY_W))
        {
            players.canJump = false;

            if (players.canJump == false && cont > 0)
            {
                PlayerJump(player);
            }
        }

        if (cont > 0)
        {
            cont = cont - GetFrameTime();
        }

        if (cont <= 0)
        {
            players.canJump = false;

            if (players.canJump == false)
            {
                players.gravity = 350;
                players.gravity = players.gravity + players.jumpForce * GetFrameTime();
                players.pos.y = players.pos.y + players.gravity * GetFrameTime();
            }
        }
    }
}

void PlayerJump(Player& players)
{
    players.gravity = -350;
    players.pos.y = players.pos.y + players.gravity * GetFrameTime();
}