#include <iostream>

#include "raylib.h"

#include "Window/PlayGame.h"
#include "Window/LevelManager.h"
#include "Window/Ui.h"

#include "Objects/Player.h"
#include "Objects/Ground.h"
#include "Objects/Platform.h"
#include "Objects/Wall.h"
#include "Objects/Enemy.h"
#include "Objects/Obstacle.h"

using namespace std;

//Collisions
bool CheckCollisionRecRec(Vector2 r1, float r1w, float r1h, Vector2 r2, float r2w, float r2h);
void PlayerCollision();
void EnemyCollision(Enemy& enemyLv);

//Movement
void PlayerMovement(Player& player);
void PlayerJump(Player& player);
void EnemyMovement(Enemy& enemy, Level& lv);
void ObstacleMovement(Obstacle& obstacles, Level& lv);

void RestartGame();

//UI
Ui ui;

//Player
Player player;
float cont = 0.3f;

//Enemy
int const maxEnemiesLv2 = 2;
Enemy enemyLv2[maxEnemiesLv2];

int const maxEnemiesLv4 = 1;
Enemy enemyLv4[maxEnemiesLv4];

int const maxEnemiesLv5 = 1;
Enemy enemyLv5[maxEnemiesLv5];

int const maxEnemiesLv7 = 6;
Enemy enemyLv7[maxEnemiesLv7];

//Obstacle
int const maxObstaclesLv3 = 2;
Obstacle obstacleLv3[maxObstaclesLv3];

int const maxObstaclesLv4 = 3;
Obstacle obstacleLv4[maxObstaclesLv4];

int const maxObstaclesLv5 = 2;
Obstacle obstacleLv5[maxObstaclesLv5];

int const maxObstaclesLv6 = 4;
Obstacle obstacleLv6[maxObstaclesLv6];

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
int const maxPlatformsLv3 = 4;
Platform platformLv3[maxPlatformsLv3];

//Level 4
Level lv4;
int const maxPlatformsLv4 = 5;
Platform platformLv4[maxPlatformsLv4];

//Level 5
Level lv5;
int const maxPlatformsLv5 = 5;
Platform platformLv5[maxPlatformsLv5];

//Level 6
Level lv6;
int const maxPlatformsLv6 = 6;
Platform platformLv6[maxPlatformsLv6];

//Level 7
Level lv7;
int const maxPlatformsLv7 = 4;
Platform platformLv7[maxPlatformsLv7];

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
    InitWindow(screenWidth, screenHeight, "Pingu Climber V0.2");

    //Ui
    ui = CreateUi();

    //Player
    player = CreatePlayer(screenWidth, screenHeight);

    //Enemy
    //Lv2
    for (int i = 0; i < maxEnemiesLv2; i++)
    {
        enemyLv2[i] = CreateEnemy();
    }

    enemyLv2[0].pos.x = static_cast<float>(screenWidth / 2.1f);
    enemyLv2[0].pos.y = static_cast<float>(screenHeight / 1.37f);
    enemyLv2[0].hitPos.x = enemyLv2[0].pos.x + enemyLv2[0].heightHit;
    enemyLv2[0].hitPos.y = enemyLv2[0].pos.y - enemyLv2[0].heightHit;

    enemyLv2[1].pos.x = static_cast<float>(screenWidth / 2.1f);
    enemyLv2[1].pos.y = static_cast<float>(screenHeight / 2.68f);
    enemyLv2[1].hitPos.x = enemyLv2[1].pos.x + enemyLv2[1].heightHit;
    enemyLv2[1].hitPos.y = enemyLv2[1].pos.y - enemyLv2[1].heightHit;
    enemyLv2[1].dir = MoveDir::Left;

    //Lv4
    for (int i = 0; i < maxEnemiesLv4; i++)
    {
        enemyLv4[i] = CreateEnemy();
    }

    enemyLv4[0].pos.x = static_cast<float>(screenWidth / 2.1f);
    enemyLv4[0].pos.y = static_cast<float>(screenHeight / 4.8f);
    enemyLv4[0].hitPos.x = enemyLv4[0].pos.x + enemyLv4[0].heightHit;
    enemyLv4[0].hitPos.y = enemyLv4[0].pos.y - enemyLv4[0].heightHit;
    enemyLv4[0].dir = MoveDir::Left;

    //Lv5
    for (int i = 0; i < maxEnemiesLv5; i++)
    {
        enemyLv5[i] = CreateEnemy();
    }

    enemyLv5[0].pos.x = static_cast<float>(screenWidth / 1.4f);
    enemyLv5[0].pos.y = static_cast<float>(screenHeight / 1.37f);
    enemyLv5[0].hitPos.x = enemyLv5[0].pos.x + enemyLv5[0].heightHit;
    enemyLv5[0].hitPos.y = enemyLv5[0].pos.y - enemyLv5[0].heightHit;

    //Lv7
    for (int i = 0; i < maxEnemiesLv7; i++)
    {
        enemyLv7[i] = CreateEnemy();
    }

    enemyLv7[0].pos.x = static_cast<float>(GetScreenWidth() / 1.4f);
    enemyLv7[0].pos.y = static_cast<float>(GetScreenHeight() / 1.37f);
    enemyLv7[0].hitPos.x = enemyLv7[0].pos.x + enemyLv7[0].heightHit;
    enemyLv7[0].hitPos.y = enemyLv7[0].pos.y - enemyLv7[0].heightHit;

    enemyLv7[1].pos.x = static_cast<float>(GetScreenWidth() / 6);
    enemyLv7[1].pos.y = static_cast<float>(GetScreenHeight() / 1.37f);
    enemyLv7[1].hitPos.x = enemyLv7[1].pos.x + enemyLv7[1].heightHit;
    enemyLv7[1].hitPos.y = enemyLv7[1].pos.y - enemyLv7[1].heightHit;

    enemyLv7[2].pos.x = static_cast<float>(GetScreenWidth() / 1.4f);
    enemyLv7[2].pos.y = static_cast<float>(GetScreenHeight() / 2.5f);
    enemyLv7[2].hitPos.x = enemyLv7[2].pos.x + enemyLv7[2].heightHit;
    enemyLv7[2].hitPos.y = enemyLv7[2].pos.y - enemyLv7[2].heightHit;

    enemyLv7[3].pos.x = static_cast<float>(GetScreenWidth() / 6);
    enemyLv7[3].pos.y = static_cast<float>(GetScreenHeight() / 2.5f);
    enemyLv7[3].hitPos.x = enemyLv7[3].pos.x + enemyLv7[3].heightHit;
    enemyLv7[3].hitPos.y = enemyLv7[3].pos.y - enemyLv7[3].heightHit;

    enemyLv7[4].pos.x = static_cast<float>(GetScreenWidth() / 1.4f);
    enemyLv7[4].pos.y = static_cast<float>(GetScreenHeight() / 14);
    enemyLv7[4].hitPos.x = enemyLv7[4].pos.x + enemyLv7[4].heightHit;
    enemyLv7[4].hitPos.y = enemyLv7[4].pos.y - enemyLv7[4].heightHit;

    enemyLv7[5].pos.x = static_cast<float>(GetScreenWidth() / 6);
    enemyLv7[5].pos.y = static_cast<float>(GetScreenHeight() / 14);
    enemyLv7[5].hitPos.x = enemyLv7[5].pos.x + enemyLv7[5].heightHit;
    enemyLv7[5].hitPos.y = enemyLv7[5].pos.y - enemyLv7[5].heightHit;

    //Obstacle
    //Lv3
    for (int i = 0; i < maxObstaclesLv3; i++)
    {
        obstacleLv3[i] = CreateObstacle();
    }

    obstacleLv3[0].pos.x = static_cast<float>(screenWidth / 1.7f);
    obstacleLv3[0].pos.y = static_cast<float>(screenWidth / screenWidth);

    obstacleLv3[1].pos.x = static_cast<float>(screenWidth / 3);
    obstacleLv3[1].pos.y = static_cast<float>(screenWidth / screenWidth);

    //Lv4
    for (int i = 0; i < maxObstaclesLv4; i++)
    {
        obstacleLv4[i] = CreateObstacle();
    }

    obstacleLv4[0].pos.x = static_cast<float>(screenWidth / 1.4f);
    obstacleLv4[0].pos.y = static_cast<float>(screenWidth / screenWidth);

    obstacleLv4[1].pos.x = static_cast<float>(screenWidth / 2.1f);
    obstacleLv4[1].pos.y = static_cast<float>(screenWidth / screenWidth);

    obstacleLv4[2].pos.x = static_cast<float>(screenWidth / 4.5f);
    obstacleLv4[2].pos.y = static_cast<float>(screenWidth / screenWidth);

    //Lv5
    for (int i = 0; i < maxObstaclesLv5; i++)
    {
        obstacleLv5[i] = CreateObstacle();
    }

    obstacleLv5[0].pos.x = static_cast<float>(screenWidth / 1.8f);
    obstacleLv5[0].pos.y = static_cast<float>(screenWidth / screenWidth);

    obstacleLv5[1].pos.x = static_cast<float>(screenWidth / 2.5f);
    obstacleLv5[1].pos.y = static_cast<float>(screenWidth / screenWidth);

    //Lv6
    for (int i = 0; i < maxObstaclesLv6; i++)
    {
        obstacleLv6[i] = CreateObstacle();
    }

    obstacleLv6[0].pos.x = static_cast<float>(screenWidth / 1.8f);
    obstacleLv6[0].pos.y = static_cast<float>(screenWidth / screenWidth);

    obstacleLv6[1].pos.x = static_cast<float>(screenWidth / 2.5f);
    obstacleLv6[1].pos.y = static_cast<float>(screenWidth / screenWidth);

    obstacleLv6[2].pos.x = static_cast<float>(screenWidth / 4.5f);
    obstacleLv6[2].pos.y = static_cast<float>(screenWidth / screenWidth);

    obstacleLv6[3].pos.x = static_cast<float>(screenWidth / 1.4f);
    obstacleLv6[3].pos.y = static_cast<float>(screenWidth / screenWidth);

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

    platformLv1[2].pos.x = static_cast<float>(screenWidth / 2.1);
    platformLv1[2].pos.y = static_cast<float>(screenHeight / 2);

    platformLv1[3].pos.x = static_cast<float>(screenWidth / 3.8f);
    platformLv1[3].pos.y = static_cast<float>(screenHeight / 4);

    platformLv1[4].pos.x = static_cast<float>(screenWidth / 1.9f);
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

    platformLv3[1].pos.x = static_cast<float>(screenWidth / 1.5f);
    platformLv3[1].pos.y = static_cast<float>(screenHeight / 2);

    platformLv3[2].pos.x = static_cast<float>(screenWidth / 2.5f);
    platformLv3[2].pos.y = static_cast<float>(screenHeight / 3.3f);

    platformLv3[3].pos.x = static_cast<float>(screenWidth / 5.5f);
    platformLv3[3].pos.y = static_cast<float>(screenHeight / 7);

    //Platforms level 4
    lv4 = CreateLevel();
    lv4.isLvActive = false;

    for (int i = 0; i < maxPlatformsLv4; i++)
    {
        platformLv4[i] = CreatePlatform();
    }

    platformLv4[0].pos.x = static_cast<float>(screenWidth / 5.5f);
    platformLv4[0].pos.y = static_cast<float>(screenHeight / 1.1f);

    platformLv4[1].pos.x = static_cast<float>(screenWidth / 2.3f);
    platformLv4[1].pos.y = static_cast<float>(screenHeight / 1.3f);

    platformLv4[2].pos.x = static_cast<float>(screenWidth / 1.5f);
    platformLv4[2].pos.y = static_cast<float>(screenHeight / 1.5f);

    platformLv4[3].pos.x = static_cast<float>(screenWidth / 6);
    platformLv4[3].pos.y = static_cast<float>(screenHeight / 3.2f);
    platformLv4[3].width = 650;

    platformLv4[4].pos.x = static_cast<float>(screenWidth / 6);
    platformLv4[4].pos.y = static_cast<float>(screenHeight / 7);

    //Platforms level 5
    lv5 = CreateLevel();
    lv5.isLvActive = false;

    for (int i = 0; i < maxPlatformsLv5; i++)
    {
        platformLv5[i] = CreatePlatform();
    }

    platformLv5[0].pos.x = static_cast<float>(screenWidth / 6);
    platformLv5[0].pos.y = static_cast<float>(screenHeight / 1.2f);
    platformLv5[0].width = 650;

    platformLv5[1].pos.x = static_cast<float>(screenWidth / 2.3f);
    platformLv5[1].pos.y = static_cast<float>(screenHeight / 1.8f);

    platformLv5[2].pos.x = static_cast<float>(screenWidth / 5.8f);
    platformLv5[2].pos.y = static_cast<float>(screenHeight / 3);

    platformLv5[3].pos.x = static_cast<float>(screenWidth / 1.45f);
    platformLv5[3].pos.y = static_cast<float>(screenHeight / 3);

    platformLv5[4].pos.x = static_cast<float>(screenWidth / 2.3f);
    platformLv5[4].pos.y = static_cast<float>(screenHeight / 6);

    //Platforms level 6
    lv6 = CreateLevel();
    lv6.isLvActive = false;

    for (int i = 0; i < maxPlatformsLv6; i++)
    {
        platformLv6[i] = CreatePlatform();
    }

    platformLv6[0].pos.x = static_cast<float>(screenWidth / 2.3f);
    platformLv6[0].pos.y = static_cast<float>(screenHeight / 1.2f);

    platformLv6[1].pos.x = static_cast<float>(screenWidth / 6);
    platformLv6[1].pos.y = static_cast<float>(screenHeight / 1.6f);

    platformLv6[2].pos.x = static_cast<float>(screenWidth / 1.45f);
    platformLv6[2].pos.y = static_cast<float>(screenHeight / 1.6f);

    platformLv6[3].pos.x = static_cast<float>(screenWidth / 6);
    platformLv6[3].pos.y = static_cast<float>(screenHeight / 3.5f);

    platformLv6[4].pos.x = static_cast<float>(screenWidth / 1.45f);
    platformLv6[4].pos.y = static_cast<float>(screenHeight / 3.5f);

    platformLv6[5].pos.x = static_cast<float>(screenWidth / 2.3f);
    platformLv6[5].pos.y = static_cast<float>(screenHeight / 5);

    //Platforms level 7
    lv7 = CreateLevel();
    lv7.isLvActive = false;

    for (int i = 0; i < maxPlatformsLv7; i++)
    {
        platformLv7[i] = CreatePlatform();
    }

    platformLv7[0].pos.x = static_cast<float>(screenWidth / 6);
    platformLv7[0].pos.y = static_cast<float>(screenHeight / 1.2f);
    platformLv7[0].width = 650;

    platformLv7[1].pos.x = static_cast<float>(screenWidth / 6);
    platformLv7[1].pos.y = static_cast<float>(screenHeight / 2);
    platformLv7[1].width = 650;

    platformLv7[2].pos.x = static_cast<float>(screenWidth / 6);
    platformLv7[2].pos.y = static_cast<float>(screenHeight / 6);
    platformLv7[2].width = 650;

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

    for (int i = 0; i < maxEnemiesLv2; i++)
    {
        EnemyMovement(enemyLv2[i], lv2);
    }

    for (int i = 0; i < maxEnemiesLv4; i++)
    {
        EnemyMovement(enemyLv4[i], lv4);
    }

    for (int i = 0; i < maxEnemiesLv5; i++)
    {
        EnemyMovement(enemyLv5[i], lv5);
    }

    for (int i = 0; i < maxEnemiesLv7; i++)
    {
        EnemyMovement(enemyLv7[i], lv7);
    }

    for (int i = 0; i < maxObstaclesLv3; i++)
    {
        ObstacleMovement(obstacleLv3[i], lv3);
    }

    for (int i = 0; i < maxObstaclesLv4; i++)
    {
        ObstacleMovement(obstacleLv4[i], lv4);
    }

    for (int i = 0; i < maxObstaclesLv5; i++)
    {
        ObstacleMovement(obstacleLv5[i], lv5);
    }

    for (int i = 0; i < maxObstaclesLv6; i++)
    {
        ObstacleMovement(obstacleLv6[i], lv6);
    }

    Collisions();
}

void Collisions()
{
    PlayerCollisionLimitLeft(player, wall[0]);
    PlayerCollisionLimitRight(player, wall[1]);

    PlayerCollisionLimitUpAndDown(player, GetScreenHeight(), lv1, lv2, lv3, lv4, lv5, lv6, lv7, lvCounter);

    for (int i = 0; i < maxEnemiesLv2; i++)
    {
        if (enemyLv2[i].isActive == true)
        {
            EnemyCollision(enemyLv2[i]);
        }
    }

    for (int i = 0; i < maxEnemiesLv4; i++)
    {
        if (enemyLv4[i].isActive == true)
        {
            EnemyCollision(enemyLv4[i]);
        }
    }

    for (int i = 0; i < maxEnemiesLv5; i++)
    {
        if (enemyLv5[i].isActive == true)
        {
            EnemyCollision(enemyLv5[i]);
        }
    }

    for (int i = 0; i < maxEnemiesLv7; i++)
    {
        if (enemyLv7[i].isActive == true)
        {
            EnemyCollision(enemyLv7[i]);
        }
    }

    for (int i = 0; i < maxObstaclesLv3; i++)
    {
        if (obstacleLv3[i].isActive == true)
        {
            ObstacleCollisionLimit(obstacleLv3[i], GetScreenHeight());
        }
    }

    for (int i = 0; i < maxObstaclesLv4; i++)
    {
        if (obstacleLv4[i].isActive == true)
        {
            ObstacleCollisionLimit(obstacleLv4[i], GetScreenHeight());
        }
    }

    for (int i = 0; i < maxObstaclesLv5; i++)
    {
        if (obstacleLv5[i].isActive == true)
        {
            ObstacleCollisionLimit(obstacleLv5[i], GetScreenHeight());
        }
    }

    for (int i = 0; i < maxObstaclesLv6; i++)
    {
        if (obstacleLv6[i].isActive == true)
        {
            ObstacleCollisionLimit(obstacleLv6[i], GetScreenHeight());
        }
    }
    
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

    //Level 4 
    if (lv4.isLvActive == true)
    {
        for (int i = 0; i < maxPlatformsLv4; i++)
        {
            DrawPlatform(platformLv4[i]);
        }
    }

    //Level 5 
    if (lv5.isLvActive == true)
    {
        for (int i = 0; i < maxPlatformsLv5; i++)
        {
            DrawPlatform(platformLv5[i]);
        }
    }

    //Level 6
    if (lv6.isLvActive == true)
    {
        for (int i = 0; i < maxPlatformsLv6; i++)
        {
            DrawPlatform(platformLv6[i]);
        }
    }

    //Level 7
    if (lv7.isLvActive == true)
    {
        for (int i = 0; i < maxPlatformsLv7; i++)
        {
            DrawPlatform(platformLv7[i]);
        }
    }

    DrawPlayer(player);

    //Enemy
    //Lv2
    for (int i = 0; i < maxEnemiesLv2; i++)
    {
        if (enemyLv2[i].isActive == true)
        {
            DrawEnemy(enemyLv2[i], lv2);
        }
    }

    //Lv4
    for (int i = 0; i < maxEnemiesLv4; i++)
    {
        if (enemyLv4[i].isActive == true)
        {
            DrawEnemy(enemyLv4[i], lv4);
        }
    }

    //Lv5
    for (int i = 0; i < maxEnemiesLv5; i++)
    {
        if (enemyLv5[i].isActive == true)
        {
            DrawEnemy(enemyLv5[i], lv5);
        }
    }

    //Lv7
    for (int i = 0; i < maxEnemiesLv7; i++)
    {
        if (enemyLv7[i].isActive == true)
        {
            DrawEnemy(enemyLv7[i], lv7);
        }
    }

    //Obstacle
    //Lv3
    for (int i = 0; i < maxObstaclesLv3; i++)
    {
        if (obstacleLv3[i].isActive == true)
        {
            DrawObstacle(obstacleLv3[i], lv3);
        }
    }

    //Lv4
    for (int i = 0; i < maxObstaclesLv4; i++)
    {
        if (obstacleLv4[i].isActive == true)
        {
            DrawObstacle(obstacleLv4[i], lv4);
        }
    }

    //Lv5
    for (int i = 0; i < maxObstaclesLv5; i++)
    {
        if (obstacleLv5[i].isActive == true)
        {
            DrawObstacle(obstacleLv5[i], lv5);
        }
    }

    //Lv6
    for (int i = 0; i < maxObstaclesLv6; i++)
    {
        if (obstacleLv6[i].isActive == true)
        {
            DrawObstacle(obstacleLv6[i], lv6);
        }
    }

    for (int i = 0; i < maxWalls; i++)
    {
        DrawWall(wall[i]);
    }

    DrawUi(ui, lvCounter);

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
                cont = 0.3f;
            }
        }

        if (CheckCollisionRecRec(player.pos, player.width, player.height, platformLv1[0].pos, platformLv1[0].width, platformLv1[0].height))
        {
            player.canGoDown = false;
        }

        else
        {
            player.canGoDown = true;
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
                cont = 0.3f;
            }
        }

        for (int i = 0; i < maxEnemiesLv2; i++)
        {
            if (enemyLv2[i].isActive == true)
            {
                if (CheckCollisionRecRec(player.pos, player.width, player.height, enemyLv2[i].hitPos, enemyLv2[i].widthHit, enemyLv2[i].heightHit))
                {
                    enemyLv2[i].isActive = false;
                }

                if (CheckCollisionRecRec(player.pos, player.width, player.height, enemyLv2[i].pos, enemyLv2[i].width, enemyLv2[i].height))
                {
                    player.isActive = false;
                    RestartGame();
                }
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
                cont = 0.3f;
            }
        }

        for (int i = 0; i < maxObstaclesLv3; i++)
        {
            if (CheckCollisionRecRec(player.pos, player.width, player.height, obstacleLv3[i].pos, obstacleLv3[i].width, obstacleLv3[i].height))
            {
                player.isActive = false;
                RestartGame();
            }
        }
    }

    if (lv4.isLvActive == true)
    {
        for (int i = 0; i < maxPlatformsLv4; i++)
        {
            if (CheckCollisionRecRec(player.pos, player.width, player.height, platformLv4[i].pos, platformLv4[i].width, platformLv4[i].height))
            {
                player.gravity = 0;
                player.canJump = true;
                cont = 0.3f;
            }
        }

        for (int i = 0; i < maxEnemiesLv4; i++)
        {
            if (enemyLv4[i].isActive == true)
            {
                if (CheckCollisionRecRec(player.pos, player.width, player.height, enemyLv4[i].hitPos, enemyLv4[i].widthHit, enemyLv4[i].heightHit))
                {
                    enemyLv4[i].isActive = false;
                }

                if (CheckCollisionRecRec(player.pos, player.width, player.height, enemyLv4[i].pos, enemyLv4[i].width, enemyLv4[i].height))
                {
                    player.isActive = false;
                    RestartGame();
                }
            }
        }

        for (int i = 0; i < maxObstaclesLv4; i++)
        {
            if (CheckCollisionRecRec(player.pos, player.width, player.height, obstacleLv4[i].pos, obstacleLv4[i].width, obstacleLv4[i].height))
            {
                player.isActive = false;
                RestartGame();
            }
        }
    }

    if (lv5.isLvActive == true)
    {
        for (int i = 0; i < maxPlatformsLv5; i++)
        {
            if (CheckCollisionRecRec(player.pos, player.width, player.height, platformLv5[i].pos, platformLv5[i].width, platformLv5[i].height))
            {
                player.gravity = 0;
                player.canJump = true;
                cont = 0.3f;
            }
        }

        for (int i = 0; i < maxEnemiesLv5; i++)
        {
            if (enemyLv5[i].isActive == true)
            {
                if (CheckCollisionRecRec(player.pos, player.width, player.height, enemyLv5[i].hitPos, enemyLv5[i].widthHit, enemyLv5[i].heightHit))
                {
                    enemyLv5[i].isActive = false;
                }

                if (CheckCollisionRecRec(player.pos, player.width, player.height, enemyLv5[i].pos, enemyLv5[i].width, enemyLv5[i].height))
                {
                    player.isActive = false;
                    RestartGame();
                }
            }
        }

        for (int i = 0; i < maxObstaclesLv5; i++)
        {
            if (CheckCollisionRecRec(player.pos, player.width, player.height, obstacleLv5[i].pos, obstacleLv5[i].width, obstacleLv5[i].height))
            {
                player.isActive = false;
                RestartGame();
            }
        }
    }

    if (lv6.isLvActive == true)
    {
        for (int i = 0; i < maxPlatformsLv6; i++)
        {
            if (CheckCollisionRecRec(player.pos, player.width, player.height, platformLv6[i].pos, platformLv6[i].width, platformLv6[i].height))
            {
                player.gravity = 0;
                player.canJump = true;
                cont = 0.3f;
            }
        }

        for (int i = 0; i < maxObstaclesLv6; i++)
        {
            if (CheckCollisionRecRec(player.pos, player.width, player.height, obstacleLv6[i].pos, obstacleLv6[i].width, obstacleLv6[i].height))
            {
                player.isActive = false;
                RestartGame();
            }
        }
    }

    if (lv7.isLvActive == true)
    {
        for (int i = 0; i < maxPlatformsLv7; i++)
        {
            if (CheckCollisionRecRec(player.pos, player.width, player.height, platformLv7[i].pos, platformLv7[i].width, platformLv7[i].height))
            {
                player.gravity = 0;
                player.canJump = true;
                cont = 0.3f;
            }
        }

        for (int i = 0; i < maxEnemiesLv7; i++)
        {
            if (enemyLv7[i].isActive == true)
            {
                if (CheckCollisionRecRec(player.pos, player.width, player.height, enemyLv7[i].hitPos, enemyLv7[i].widthHit, enemyLv7[i].heightHit))
                {
                    enemyLv7[i].isActive = false;
                }

                if (CheckCollisionRecRec(player.pos, player.width, player.height, enemyLv7[i].pos, enemyLv7[i].width, enemyLv7[i].height))
                {
                    player.isActive = false;
                    RestartGame();
                }
            }
        }
    }
}

void EnemyCollision(Enemy& enemyLv)
{
    if (CheckCollisionRecRec(enemyLv.pos, enemyLv.width, enemyLv.height, wall[0].pos, wall[0].width, wall[0].height))
    {
        enemyLv.dir = MoveDir::Left;
    }

    if (CheckCollisionRecRec(enemyLv.pos, enemyLv.width, enemyLv.height, wall[1].pos, wall[1].width, wall[1].height))
    {
        enemyLv.dir = MoveDir::Right;
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

        if (player.canGoDown == true)
        {
            if (IsKeyDown(KEY_S))
            {
                players.pos.y -= players.jumpForce * GetFrameTime();
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
                players.gravity += players.gravity * GetFrameTime();
                players.pos.y = players.pos.y + players.gravity * GetFrameTime();
            }
        }
    }
}

void PlayerJump(Player& players)
{
    players.gravity = -350;
    players.pos.y = players.pos.y + players.jumpForce * GetFrameTime();
}

void EnemyMovement(Enemy& enemys, Level& lv)
{
    if (enemys.isActive == true && lv.isLvActive == true)
    {
        if (enemys.dir == MoveDir::Left)
        {
            enemys.pos.x -= enemys.speed * GetFrameTime();
            enemys.hitPos.x -= enemys.speed * GetFrameTime();
        }

        if (enemys.dir == MoveDir::Right)
        {
            enemys.pos.x += enemys.speed * GetFrameTime();
            enemys.hitPos.x += enemys.speed * GetFrameTime();
        }
    }
}

void ObstacleMovement(Obstacle& obstacles, Level& lv)
{
    if (lv.isLvActive == true)
    {
        obstacles.pos.y += obstacles.speed * GetFrameTime();
    }
}

void RestartGame()
{
    lvCounter = 1;
    cont = 0.3f;

    lv1.isLvActive = true;
    lv2.isLvActive = false;
    lv3.isLvActive = false;
    lv4.isLvActive = false;
    lv5.isLvActive = false;
    lv6.isLvActive = false;
    lv7.isLvActive = false;

    player.pos.x = static_cast<float>(GetScreenWidth() / 2.1f);
    player.pos.y = static_cast<float>(GetScreenHeight() / 1.2f);

    for (int i = 0; i < maxEnemiesLv2; i++)
    {
        enemyLv2[i].isActive = true;
    }
    enemyLv2[1].dir = MoveDir::Left;

    for (int i = 0; i < maxEnemiesLv4; i++)
    {
        enemyLv4[i].isActive = true;
    }

    for (int i = 0; i < maxEnemiesLv5; i++)
    {
        enemyLv5[i].isActive = true;
    }
    enemyLv5[0].pos.x = static_cast<float>(GetScreenWidth() / 1.4f);
    enemyLv5[0].pos.y = static_cast<float>(GetScreenHeight() / 1.37f);
    enemyLv5[0].hitPos.x = enemyLv5[0].pos.x + enemyLv5[0].heightHit;
    enemyLv5[0].hitPos.y = enemyLv5[0].pos.y - enemyLv5[0].heightHit;

    for (int i = 0; i < maxEnemiesLv7; i++)
    {
        enemyLv7[i].isActive = true;
    }
    enemyLv7[0].pos.x = static_cast<float>(GetScreenWidth() / 1.4f);
    enemyLv7[0].pos.y = static_cast<float>(GetScreenHeight() / 1.37f);
    enemyLv7[0].hitPos.x = enemyLv7[0].pos.x + enemyLv7[0].heightHit;
    enemyLv7[0].hitPos.y = enemyLv7[0].pos.y - enemyLv7[0].heightHit;

    enemyLv7[1].pos.x = static_cast<float>(GetScreenWidth() / 6);
    enemyLv7[1].pos.y = static_cast<float>(GetScreenHeight() / 1.37f);
    enemyLv7[1].hitPos.x = enemyLv7[1].pos.x + enemyLv7[1].heightHit;
    enemyLv7[1].hitPos.y = enemyLv7[1].pos.y - enemyLv7[1].heightHit;

    enemyLv7[2].pos.x = static_cast<float>(GetScreenWidth() / 1.4f);
    enemyLv7[2].pos.y = static_cast<float>(GetScreenHeight() / 2.5f);
    enemyLv7[2].hitPos.x = enemyLv7[2].pos.x + enemyLv7[2].heightHit;
    enemyLv7[2].hitPos.y = enemyLv7[2].pos.y - enemyLv7[2].heightHit;

    enemyLv7[3].pos.x = static_cast<float>(GetScreenWidth() / 6);
    enemyLv7[3].pos.y = static_cast<float>(GetScreenHeight() / 2.5f);
    enemyLv7[3].hitPos.x = enemyLv7[3].pos.x + enemyLv7[3].heightHit;
    enemyLv7[3].hitPos.y = enemyLv7[3].pos.y - enemyLv7[3].heightHit;

    for (int i = 0; i < maxObstaclesLv3; i++)
    {
        obstacleLv3[i].pos.y = static_cast<float>(GetScreenWidth() / GetScreenWidth());
    }

    for (int i = 0; i < maxObstaclesLv4; i++)
    {
        obstacleLv4[i].pos.y = static_cast<float>(GetScreenWidth() / GetScreenWidth());
    }

    for (int i = 0; i < maxObstaclesLv5; i++)
    {
        obstacleLv5[i].pos.y = static_cast<float>(GetScreenWidth() / GetScreenWidth());
    }

    for (int i = 0; i < maxObstaclesLv6; i++)
    {
        obstacleLv6[i].pos.y = static_cast<float>(GetScreenWidth() / GetScreenWidth());
    }

    player.isActive = true;
}