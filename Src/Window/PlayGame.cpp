#include <iostream>

#include "raylib.h"

#include "Window/PlayGame.h"
#include "Window/LevelManager.h"

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

//Player
Player player;
float cont = 0.6f;

//Level
int lvCounter = 1;

//Level 1
Level lv1;
int const maxPlatformsLv1 = 5;
Platform platformLv1[maxPlatformsLv1];

//Level 2
Level lv2;
int const maxPlatformsLv2 = 3;
Platform platformLv2[maxPlatformsLv2];

//Level 3
Level lv3;
int const maxPlatformsLv3 = 3;
Platform platformLv3[maxPlatformsLv3];

//Walls
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
    lv1 = CreateLevel();
    lv1.isLvActive = true;
    for (int i = 0; i < maxPlatformsLv1; i++)
    {
        platformLv1[i] = CreatePlatform();
    }
    platformLv1[0].pos.x = static_cast<float>(screenWidth / screenWidth);
    platformLv1[0].pos.y = static_cast<float>(screenHeight / 1.1f);
    platformLv1[0].width = static_cast<float>(screenWidth);
    platformLv1[0].height = 70;

    platformLv1[1].pos.x = static_cast<float>(screenWidth / 5);
    platformLv1[1].pos.y = static_cast<float>(screenHeight / 1.5f);

    platformLv1[2].pos.x = static_cast<float>(screenWidth / 2);
    platformLv1[2].pos.y = static_cast<float>(screenHeight / 2);

    platformLv1[3].pos.x = static_cast<float>(screenWidth / 3.8f);
    platformLv1[3].pos.y = static_cast<float>(screenHeight / 4);

    platformLv1[4].pos.x = static_cast<float>(screenWidth / 1.7f);
    platformLv1[4].pos.y = static_cast<float>(screenHeight / 10);

    //Platforms level 2
    lv2 = CreateLevel();
    lv2.isLvActive = false;

    for (int i = 0; i < maxPlatformsLv2; i++)
    {
        platformLv2[i] = CreatePlatform();
    }
    platformLv2[0].pos.x = static_cast<float>(screenWidth / 6);
    platformLv2[0].pos.y = static_cast<float>(screenHeight / 1.2f);
    platformLv2[0].width = 650;

    platformLv2[1].pos.x = static_cast<float>(screenWidth / 6);
    platformLv2[1].pos.y = static_cast<float>(screenHeight / 2.1);
    platformLv2[1].width = 650;

    platformLv2[2].pos.x = static_cast<float>(screenWidth / 6);
    platformLv2[2].pos.y = static_cast<float>(screenHeight / 6);

    //Platforms level 3
    lv3 = CreateLevel();
    lv3.isLvActive = false;

    for (int i = 0; i < maxPlatformsLv3; i++)
    {
        platformLv3[i] = CreatePlatform();
    }
    platformLv3[0].pos.x = static_cast<float>(screenWidth / 2.6f);
    platformLv3[0].pos.y = static_cast<float>(screenHeight / 1.2f);
    platformLv3[0].width = 450;

    platformLv3[1].pos.x = static_cast<float>(screenWidth / 1.5);
    platformLv3[1].pos.y = static_cast<float>(screenHeight / 2);

    platformLv3[2].pos.x = static_cast<float>(screenWidth / 3);
    platformLv3[2].pos.y = static_cast<float>(screenHeight / 4);

    //Walls 
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

    PlayerCollisionLimitUpAndDown(player, GetScreenHeight(), lv1, lv2, lv3, lvCounter);
    
    PlayerCollision();
}

void Draw()
{
    BeginDrawing();

    ClearBackground(BLACK);
    
    //Level 1
    if (lv1.isLvActive == true)
    {
        for (int i = 0; i < maxPlatformsLv1; i++)
        {
            DrawPlatform(platformLv1[i]);
        }
    }

    //Level 2
    if (lv2.isLvActive == true)
    {
        for (int i = 0; i < maxPlatformsLv2; i++)
        {
            DrawPlatform(platformLv2[i]);
        }
    }

    //Level 3 
    if (lv3.isLvActive == true)
    {
        for (int i = 0; i < maxPlatformsLv3; i++)
        {
            DrawPlatform(platformLv3[i]);
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
    if (lv1.isLvActive == true)
    {
        for (int i = 0; i < maxPlatformsLv1; i++)
        {
            if (CheckCollisionRecRec(player.pos, player.width, player.height, platformLv1[i].pos, platformLv1[i].width, platformLv1[i].height))
            {
                player.gravity = 0;
                player.canJump = true;
                cont = 0.6f;
            }
        }
    }

    if (lv2.isLvActive == true)
    {
        for (int i = 0; i < maxPlatformsLv2; i++)
        {
            if (CheckCollisionRecRec(player.pos, player.width, player.height, platformLv2[i].pos, platformLv2[i].width, platformLv2[i].height))
            {
                player.gravity = 0;
                player.canJump = true;
                cont = 0.6f;
            }
        }
    }

    if (lv3.isLvActive == true)
    {
        for (int i = 0; i < maxPlatformsLv3; i++)
        {
            if (CheckCollisionRecRec(player.pos, player.width, player.height, platformLv3[i].pos, platformLv3[i].width, platformLv3[i].height))
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