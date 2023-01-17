#include <iostream>

#include "raylib.h"

#include "Window/PlayGame.h"
#include "Window/LevelManager.h"
#include "Window/Ui.h"
#include "Window/Menu.h"
#include "Window/PauseMenu.h"
#include "Window/RestartMenu.h"

#include "Objects/Player.h"
#include "Objects/Platform.h"
#include "Objects/Wall.h"
#include "Objects/Enemy.h"
#include "Objects/Obstacle.h"
#include "Objects/Mouse.h"
#include "Objects/Background.h"

using namespace std;

//Init
void InitEnemies(int screenWidht, int screenHeight);
void InitObstacles(int screenWidht);
void InitPlatforms(int screenWidth, int screenHeight);

//Collisions
bool CheckCollisionRecRec(Vector2 r1, float r1w, float r1h, Vector2 r2, float r2w, float r2h);
void PlayerCollisions();
void PlayerCollisionLimitLeft(Player& player, Wall& wall);
void PlayerCollisionLimitRight(Player& player, Wall& wall);
void PlayerCollisionLimitUpAndDown(Player& player, int screenHeight);
void PlayerPlatformsCollision(Player& players, Level& lvs, Platform& platforms);
void PlayerEnemyCollision(Player& players, Level& lvs, Enemy& enemy);
void PlayerObstacleCollision(Player& players, Level& lvs, Obstacle& obstacle);
void EnemyWallCollision(Enemy& enemyLv);

//Movement
void PlayerMovement(Player& player);
void PlayerJump(Player& player);
void AllEnemiesMovement();
void EnemyMovement(Enemy& enemy, Level& lv);
void AllObstaclesMovement();
void ObstacleMovement(Obstacle& obstacles, Level& lv);
void MouseMovement();

void NextLevel(int screenHeight);
void PreviusLevel(int screenHeight);


//Menu
int optionSelect = 0;
bool playGame = false;
Texture menuBackground;

Texture subMenusBackground;

//Pause
bool pause = false;
SubMenu pauseMenu;
Button pauseButtonOff;
Button pauseButtonOn;
Button resumeButton;
Button returnMenuButton;
Button quitGameButton;

//RestartMenu
SubMenu restartMenu;
Button restartButton;

//UI
Ui ui;

//Player
Player player;
float cont = 0.3f;
int currentFrame = 0;

//Enemy
int const maxEnemies = 8;
Enemy enemies[maxEnemies];

int const maxEnemiesLv2 = 2;
int const maxEnemiesLv4 = 3;
int const maxEnemiesLv5 = 4;
int const maxEnemiesLv7 = 8;

//Obstacle
int const maxObstacles = 11;
Obstacle obstacles[maxObstacles];

int const maxObstaclesLv3 = 2;
int const maxObstaclesLv4 = 5;
int const maxObstaclesLv5 = 7;
int const maxObstaclesLv6 = 11;

//Levels
int const maxPlatforms = 34;
Platform platforms[maxPlatforms];
int lvCounter = 1;

//Level 1
Level lv1;
int const maxPlatformsLv1 = 5;

//Level 2
Level lv2;
int const maxPlatformsLv2 = 8;

//Level 3
Level lv3;
int const maxPlatformsLv3 = 12;

//Level 4
Level lv4;
int const maxPlatformsLv4 = 17;

//Level 5
Level lv5;
int const maxPlatformsLv5 = 22;

//Level 6
Level lv6;
int const maxPlatformsLv6 = 28;

//Level 7
Level lv7;
int const maxPlatformsLv7 = 31;

//Level 8
Level lv8;
int const maxPlatformsLv8 = 34;

//Walls
int const maxWalls = 2;
Wall wall[maxWalls];

//Background
Background background;

//Mouse
Mouse mouse;

//Music
Music music;

//Font
Font gameFont;

void StartGame()
{
    int screenWidth = 1024;
    int screenHeight = 768;

    InitGame(screenWidth, screenHeight);

    GameLoop();
}

void InitGame(int screenWidth, int screenHeight)
{
    InitWindow(screenWidth, screenHeight, "Pingu Climber V0.3");

    //Menu
    menuBackground = LoadTexture("resources/Sprites/MenuBackground.png");

    subMenusBackground = LoadTexture("resources/Sprites/SubMenusBackground.png");
    InitMenu();

    //Pause Menu
    InitPauseMenu(pauseMenu, pauseButtonOff, pauseButtonOn, resumeButton, returnMenuButton, quitGameButton, screenWidth, screenHeight);

    //Restart Menu
    InitRestartMenu(restartMenu, restartButton, returnMenuButton, quitGameButton, screenWidth, screenHeight);

    //Ui
    ui = CreateUi();

    //Player
    player = CreatePlayer(screenWidth, screenHeight);
    InitAnimations(player);
    
    //Level
    lv1.isLvActive = true;

    //Enemy
    for (int i = 0; i < maxEnemies; i++)
    {
        enemies[i] = CreateEnemy();
    }
    InitEnemies(screenWidth, screenHeight);

    //Obstacle
    for (int i = 0; i < maxObstacles; i++)
    {
        obstacles[i] = CreateObstacle();
    }
    InitObstacles(screenWidth);

    //Platforms
    for (int i = 0; i < maxPlatforms; i++)
    {
        platforms[i] = CreatePlatform();
    }
    InitPlatforms(screenWidth, screenHeight);
    
    //Walls 
    for (int i = 0; i < maxWalls; i++)
    {
        wall[i] = CreateWall();
    }

    //Background
    background = CreateBackground();
    
    background.pos.x = 200;
    background.pos.y = 0;
    
    background.width = 630;
    background.height = 730;

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

    //Mouse
    mouse = CreateMouse();
    HideCursor();

    //Font
    gameFont = LoadFont("resources/Font/Rocket Vintage.otf");
}

void InitEnemies(int screenWidth, int screenHeight)
{
    //Lv2
    enemies[0].pos.x = static_cast<float>(screenWidth / 2.1f);
    enemies[0].pos.y = static_cast<float>(screenHeight / 1.37f);
    enemies[0].hitPos.x = enemies[0].pos.x + enemies[0].heightHit;
    enemies[0].hitPos.y = enemies[0].pos.y - enemies[0].heightHit;

    enemies[1].pos.x = static_cast<float>(screenWidth / 2.1f);
    enemies[1].pos.y = static_cast<float>(screenHeight / 2.68f);
    enemies[1].hitPos.x = enemies[1].pos.x + enemies[1].heightHit;
    enemies[1].hitPos.y = enemies[1].pos.y - enemies[1].heightHit;
    enemies[1].dir = MoveDir::Left;

    //Lv4
    enemies[2].pos.x = static_cast<float>(screenWidth / 2.1f);
    enemies[2].pos.y = static_cast<float>(screenHeight / 4.8f);
    enemies[2].hitPos.x = enemies[2].pos.x + enemies[2].heightHit;
    enemies[2].hitPos.y = enemies[2].pos.y - enemies[2].heightHit;
    enemies[2].dir = MoveDir::Left;

    //Lv5
    enemies[3].pos.x = static_cast<float>(screenWidth / 1.4f);
    enemies[3].pos.y = static_cast<float>(screenHeight / 1.37f);
    enemies[3].hitPos.x = enemies[3].pos.x + enemies[3].heightHit;
    enemies[3].hitPos.y = enemies[3].pos.y - enemies[3].heightHit;

    //Lv7
    enemies[4].pos.x = static_cast<float>(GetScreenWidth() / 1.4f);
    enemies[4].pos.y = static_cast<float>(GetScreenHeight() / 1.37f);
    enemies[4].hitPos.x = enemies[4].pos.x + enemies[4].heightHit;
    enemies[4].hitPos.y = enemies[4].pos.y - enemies[4].heightHit;

    enemies[5].pos.x = static_cast<float>(GetScreenWidth() / 6);
    enemies[5].pos.y = static_cast<float>(GetScreenHeight() / 1.37f);
    enemies[5].hitPos.x = enemies[5].pos.x + enemies[5].heightHit;
    enemies[5].hitPos.y = enemies[5].pos.y - enemies[5].heightHit;

    enemies[6].pos.x = static_cast<float>(GetScreenWidth() / 1.4f);
    enemies[6].pos.y = static_cast<float>(GetScreenHeight() / 2.5f);
    enemies[6].hitPos.x = enemies[6].pos.x + enemies[6].heightHit;
    enemies[6].hitPos.y = enemies[6].pos.y - enemies[6].heightHit;

    enemies[7].pos.x = static_cast<float>(GetScreenWidth() / 6);
    enemies[7].pos.y = static_cast<float>(GetScreenHeight() / 2.5f);
    enemies[7].hitPos.x = enemies[7].pos.x + enemies[7].heightHit;
    enemies[7].hitPos.y = enemies[7].pos.y - enemies[7].heightHit;
}

void InitObstacles(int screenWidth)
{
    //Lv3
    obstacles[0].pos.x = static_cast<float>(screenWidth / 1.7f);

    obstacles[1].pos.x = static_cast<float>(screenWidth / 3);

    //Lv4
    obstacles[2].pos.x = static_cast<float>(screenWidth / 1.4f);

    obstacles[3].pos.x = static_cast<float>(screenWidth / 2.1f);

    obstacles[4].pos.x = static_cast<float>(screenWidth / 4.5f);

    //Lv5
    obstacles[5].pos.x = static_cast<float>(screenWidth / 1.8f);

    obstacles[6].pos.x = static_cast<float>(screenWidth / 2.5f);

    //Lv6
    obstacles[7].pos.x = static_cast<float>(screenWidth / 1.8f);

    obstacles[8].pos.x = static_cast<float>(screenWidth / 2.5f);

    obstacles[9].pos.x = static_cast<float>(screenWidth / 4.5f);

    obstacles[10].pos.x = static_cast<float>(screenWidth / 1.4f);
}

void InitPlatforms(int screenWidth, int screenHeight)
{
    //Platforms Lv1
    platforms[0].pos.x = static_cast<float>(screenWidth / screenWidth);
    platforms[0].pos.y = static_cast<float>(screenHeight / 1.1f);
    platforms[0].width = static_cast<float>(screenWidth);
    platforms[0].height = 70;

    platforms[1].pos.x = static_cast<float>(screenWidth / 5);
    platforms[1].pos.y = static_cast<float>(screenHeight / 1.5f);

    platforms[2].pos.x = static_cast<float>(screenWidth / 2.1);
    platforms[2].pos.y = static_cast<float>(screenHeight / 2);

    platforms[3].pos.x = static_cast<float>(screenWidth / 3.8f);
    platforms[3].pos.y = static_cast<float>(screenHeight / 4);

    platforms[4].pos.x = static_cast<float>(screenWidth / 1.9f);
    platforms[4].pos.y = static_cast<float>(screenHeight / 10);

    //Platforms Lv2
    platforms[5].pos.x = static_cast<float>(screenWidth / 6);
    platforms[5].pos.y = static_cast<float>(screenHeight / 1.2f);
    platforms[5].width = 650;

    platforms[6].pos.x = static_cast<float>(screenWidth / 6);
    platforms[6].pos.y = static_cast<float>(screenHeight / 2.1);
    platforms[6].width = 650;

    platforms[7].pos.x = static_cast<float>(screenWidth / 6);
    platforms[7].pos.y = static_cast<float>(screenHeight / 6);

    //Platforms Lv3
    platforms[8].pos.x = static_cast<float>(screenWidth / 2.6f);
    platforms[8].pos.y = static_cast<float>(screenHeight / 1.2f);
    platforms[8].width = 450;

    platforms[9].pos.x = static_cast<float>(screenWidth / 1.5f);
    platforms[9].pos.y = static_cast<float>(screenHeight / 2);

    platforms[10].pos.x = static_cast<float>(screenWidth / 2.5f);
    platforms[10].pos.y = static_cast<float>(screenHeight / 3.3f);

    platforms[11].pos.x = static_cast<float>(screenWidth / 5.5f);
    platforms[11].pos.y = static_cast<float>(screenHeight / 7);

    //Platforms Lv4
    platforms[12].pos.x = static_cast<float>(screenWidth / 5.5f);
    platforms[12].pos.y = static_cast<float>(screenHeight / 1.1f);

    platforms[13].pos.x = static_cast<float>(screenWidth / 2.3f);
    platforms[13].pos.y = static_cast<float>(screenHeight / 1.3f);

    platforms[14].pos.x = static_cast<float>(screenWidth / 1.5f);
    platforms[14].pos.y = static_cast<float>(screenHeight / 1.5f);

    platforms[15].pos.x = static_cast<float>(screenWidth / 6);
    platforms[15].pos.y = static_cast<float>(screenHeight / 3.2f);
    platforms[15].width = 650;

    platforms[16].pos.x = static_cast<float>(screenWidth / 6);
    platforms[16].pos.y = static_cast<float>(screenHeight / 7);

    //Platforms Lv5
    platforms[17].pos.x = static_cast<float>(screenWidth / 6);
    platforms[17].pos.y = static_cast<float>(screenHeight / 1.2f);
    platforms[17].width = 650;

    platforms[18].pos.x = static_cast<float>(screenWidth / 2.3f);
    platforms[18].pos.y = static_cast<float>(screenHeight / 1.8f);

    platforms[19].pos.x = static_cast<float>(screenWidth / 5.8f);
    platforms[19].pos.y = static_cast<float>(screenHeight / 3);

    platforms[20].pos.x = static_cast<float>(screenWidth / 1.45f);
    platforms[20].pos.y = static_cast<float>(screenHeight / 3);

    platforms[21].pos.x = static_cast<float>(screenWidth / 2.3f);
    platforms[21].pos.y = static_cast<float>(screenHeight / 6);

    //Platforms Lv6
    platforms[22].pos.x = static_cast<float>(screenWidth / 2.3f);
    platforms[22].pos.y = static_cast<float>(screenHeight / 1.2f);

    platforms[23].pos.x = static_cast<float>(screenWidth / 6);
    platforms[23].pos.y = static_cast<float>(screenHeight / 1.6f);

    platforms[24].pos.x = static_cast<float>(screenWidth / 1.45f);
    platforms[24].pos.y = static_cast<float>(screenHeight / 1.6f);

    platforms[25].pos.x = static_cast<float>(screenWidth / 6);
    platforms[25].pos.y = static_cast<float>(screenHeight / 3.5f);

    platforms[26].pos.x = static_cast<float>(screenWidth / 1.45f);
    platforms[26].pos.y = static_cast<float>(screenHeight / 3.5f);

    platforms[27].pos.x = static_cast<float>(screenWidth / 2.3f);
    platforms[27].pos.y = static_cast<float>(screenHeight / 5);

    //Platforms Lv7
    platforms[28].pos.x = static_cast<float>(screenWidth / 6);
    platforms[28].pos.y = static_cast<float>(screenHeight / 1.2f);
    platforms[28].width = 650;

    platforms[29].pos.x = static_cast<float>(screenWidth / 6);
    platforms[29].pos.y = static_cast<float>(screenHeight / 2);
    platforms[29].width = 650;

    platforms[30].pos.x = static_cast<float>(screenWidth / 6);
    platforms[30].pos.y = static_cast<float>(screenHeight / 6);
    platforms[30].width = 650;

    //Platforms Lv8
    platforms[31].pos.x = static_cast<float>(screenWidth / 1.5f);
    platforms[31].pos.y = static_cast<float>(screenHeight / 1.2f);

    platforms[32].pos.x = static_cast<float>(screenWidth / 6);
    platforms[32].pos.y = static_cast<float>(screenHeight / 2);
    platforms[32].width = 650;

    platforms[33].pos.x = static_cast<float>(screenWidth / 2.5f);
    platforms[33].pos.y = static_cast<float>(screenHeight / 5);
}

void GameLoop()
{
    SetExitKey(NULL);

    bool gameOn = true;

    if (gameOn == true)
    {
        while (!WindowShouldClose() && gameOn)
        {
            MouseMovement();
            MenuCollisions(mouse, optionSelect);
            MenuInputs(mouse, optionSelect, playGame);

            if (playGame == true)
            {
                PauseMenusInputs(gameOn, playGame, optionSelect, pause, restartMenu, pauseMenu, pauseButtonOff, pauseButtonOn, music, mouse, GetScreenWidth(), GetScreenHeight());
                RestartMenuInputs(restartMenu, pause, playGame, gameOn, optionSelect, mouse, GetScreenWidth(), GetScreenHeight(), player);

                if (!pause)
                {
                    Update();
                }

                PauseMenuCollisions(pauseMenu, mouse, resumeButton, returnMenuButton, quitGameButton, GetScreenWidth(), GetScreenHeight());
                RestarGameMenuCollisions(restartMenu, restartButton, returnMenuButton, quitGameButton, mouse, GetScreenWidth(), GetScreenHeight());
            }

            switch (optionSelect)
            {
            case static_cast<int>(Menu::MainMenu):
                BeginDrawing();
                ClearBackground(BLACK);
                DrawMenu(gameFont, menuBackground);
                DrawMouse(mouse, mouse.mouseRec);
                player.deadCount = 0;
                EndDrawing();
                break;

            case static_cast<int>(Menu::Play):
                Draw();
                break;

            case static_cast<int>(Menu::Controlls):
                BeginDrawing();
                ClearBackground(BLACK);
                DrawControlls(gameFont, subMenusBackground);
                DrawMouse(mouse, mouse.mouseRec);
                EndDrawing();
                break;

            case static_cast<int>(Menu::Rules):
                BeginDrawing();
                ClearBackground(BLACK);
                DrawRules(gameFont, subMenusBackground);
                DrawMouse(mouse, mouse.mouseRec);
                EndDrawing();
                break;

            case static_cast<int>(Menu::Credits):
                BeginDrawing();
                ClearBackground(BLACK);
                DrawCredits(gameFont, subMenusBackground);
                DrawMouse(mouse, mouse.mouseRec);
                EndDrawing();
                break;

            case static_cast<int>(Menu::Quit):
                gameOn = false;
                break;
            }
        }
    }

    if (!gameOn)
    {
        UnloadData();
        CloseWindow();
    }
}

void Update()
{
    PlayerMovement(player);

    AllEnemiesMovement();
    AllObstaclesMovement();

    NextLevel(GetScreenHeight());
    PreviusLevel(GetScreenHeight());

    Collisions();
}

void Collisions()
{
    PlayerCollisions();

    for (int i = 0; i < maxEnemies; i++)
    {
        if (enemies[i].isActive == true)
        {
            EnemyWallCollision(enemies[i]);
        }
    }

    for (int i = 0; i < maxObstacles; i++)
    {
        if (obstacles[i].isActive == true)
        {
            ObstacleCollisionLimit(obstacles[i], GetScreenHeight());
        }
    }
}

void Draw()
{
    BeginDrawing();

    ClearBackground(BLACK);

    DrawBackground(background, lvCounter);
    
    //Level 1
    if (lv1.isLvActive == true)
    {
        for (int i = 0; i < maxPlatformsLv1; i++)
        {
            DrawPlatform(platforms[i]);
        }
    }

    //Level 2
    if (lv2.isLvActive == true)
    {
        for (int i = maxPlatformsLv1; i < maxPlatformsLv2; i++)
        {
            DrawPlatform(platforms[i]);
        }
    }

    //Level 3 
    if (lv3.isLvActive == true)
    {
        for (int i = maxPlatformsLv2; i < maxPlatformsLv3; i++)
        {
            DrawPlatform(platforms[i]);
        }
    }

    //Level 4 
    if (lv4.isLvActive == true)
    {
        for (int i = maxPlatformsLv3; i < maxPlatformsLv4; i++)
        {
            DrawPlatform(platforms[i]);
        }
    }

    //Level 5 
    if (lv5.isLvActive == true)
    {
        for (int i = maxPlatformsLv4; i < maxPlatformsLv5; i++)
        {
            DrawPlatform(platforms[i]);
        }
    }

    //Level 6
    if (lv6.isLvActive == true)
    {
        for (int i = maxPlatformsLv5; i < maxPlatformsLv6; i++)
        {
            DrawPlatform(platforms[i]);
        }
    }

    //Level 7
    if (lv7.isLvActive == true)
    {
        for (int i = maxPlatformsLv6; i < maxPlatformsLv7; i++)
        {
            DrawPlatform(platforms[i]);
        }
    }

    //Level 8
    if (lv8.isLvActive == true)
    {
        for (int i = maxPlatformsLv7; i < maxPlatformsLv8; i++)
        {
            DrawPlatform(platforms[i]);
        }
    }

    DrawPlayer(player, pause);

    //Enemy
    //Lv2
    for (int i = 0; i < maxEnemiesLv2; i++)
    {
        if (enemies[i].isActive == true)
        {
            DrawEnemy(enemies[i], lv2);
        }
    }

    //Lv4
    for (int i = maxEnemiesLv2; i < maxEnemiesLv4; i++)
    {
        if (enemies[i].isActive == true)
        {
            DrawEnemy(enemies[i], lv4);
        }
    }

    //Lv5
    for (int i = maxEnemiesLv4; i < maxEnemiesLv5; i++)
    {
        if (enemies[i].isActive == true)
        {
            DrawEnemy(enemies[i], lv5);
        }
    }

    //Lv7
    for (int i = maxEnemiesLv5; i < maxEnemiesLv7; i++)
    {
        if (enemies[i].isActive == true)
        {
            DrawEnemy(enemies[i], lv7);
        }
    }

    //Obstacle
    //Lv3
    for (int i = 0; i < maxObstaclesLv3; i++)
    {
        if (obstacles[i].isActive == true)
        {
            DrawObstacle(obstacles[i], lv3);
        }
    }

    //Lv4
    for (int i = maxObstaclesLv3; i < maxObstaclesLv4; i++)
    {
        if (obstacles[i].isActive == true)
        {
            DrawObstacle(obstacles[i], lv4);
        }
    }

    //Lv5
    for (int i = maxObstaclesLv4; i < maxObstaclesLv5; i++)
    {
        if (obstacles[i].isActive == true)
        {
            DrawObstacle(obstacles[i], lv5);
        }
    }

    //Lv6
    for (int i = maxObstaclesLv5; i < maxObstaclesLv6; i++)
    {
        if (obstacles[i].isActive == true)
        {
            DrawObstacle(obstacles[i], lv6);
        }
    }

    for (int i = 0; i < maxWalls; i++)
    {
        DrawWall(wall[i]);
    }

    DrawUi(ui, lvCounter, gameFont, player);

    if (!pauseMenu.isActive)
    {
        DrawRectangle(static_cast<int>(pauseButtonOff.pos.x), static_cast<int>(pauseButtonOff.pos.y), static_cast<int>(pauseButtonOff.width), static_cast<int>(pauseButtonOff.height), BLANK);
        DrawTexture(pauseButtonOff.texture, static_cast<int>(pauseButtonOff.pos.x), static_cast<int>(pauseButtonOff.pos.y), pauseButtonOff.color);
    }

    if (pauseMenu.isActive)
    {
        DrawRectangle(static_cast<int>(pauseButtonOff.pos.x), static_cast<int>(pauseButtonOff.pos.y), static_cast<int>(pauseButtonOff.width), static_cast<int>(pauseButtonOff.height), BLANK);
        DrawTexture(pauseButtonOn.texture, static_cast<int>(pauseButtonOn.pos.x), static_cast<int>(pauseButtonOn.pos.y), pauseButtonOn.color);

        DrawPauseMenu(pauseMenu, resumeButton, returnMenuButton, quitGameButton, gameFont, GetScreenWidth(), GetScreenHeight());
    }

    if (PlayerWin(player, lvCounter))
    {
        player.isActive = false;
        DrawRestarGameMenu(restartMenu, restartButton, returnMenuButton, quitGameButton, player, gameFont, GetScreenWidth(), GetScreenHeight(), lvCounter);
    }

    DrawMouse(mouse, mouse.mouseRec);

    EndDrawing();
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

void PlayerCollisions()
{
    PlayerCollisionLimitLeft(player, wall[0]);
    PlayerCollisionLimitRight(player, wall[1]);

    PlayerCollisionLimitUpAndDown(player, GetScreenHeight());

    //Lv1
    for (int i = 0; i < maxPlatformsLv1; i++)
    {
        PlayerPlatformsCollision(player, lv1, platforms[i]);
    }

    //Lv2
    for (int i = maxPlatformsLv1; i < maxPlatformsLv2; i++)
    {
        PlayerPlatformsCollision(player, lv2, platforms[i]);
    }

    for (int i = 0; i < maxEnemiesLv2; i++)
    {
        PlayerEnemyCollision(player, lv2, enemies[i]);
    }

    //Lv3
    for (int i = maxPlatformsLv2; i < maxPlatformsLv3; i++)
    {
        PlayerPlatformsCollision(player, lv3, platforms[i]);
    }

    for (int i = 0; i < maxObstaclesLv3; i++)
    {
        PlayerObstacleCollision(player, lv3, obstacles[i]);
    }

    //Lv4
    for (int i = maxPlatformsLv3; i < maxPlatformsLv4; i++)
    {
        PlayerPlatformsCollision(player, lv4, platforms[i]);
    }

    for (int i = maxEnemiesLv2; i < maxEnemiesLv4; i++)
    {
        PlayerEnemyCollision(player, lv4, enemies[i]);
    }

    for (int i = maxObstaclesLv3; i < maxObstaclesLv4; i++)
    {
        PlayerObstacleCollision(player, lv4, obstacles[i]);
    }

    //Lv5
    for (int i = maxPlatformsLv4; i < maxPlatformsLv5; i++)
    {
        PlayerPlatformsCollision(player, lv5, platforms[i]);
    }

    for (int i = maxEnemiesLv4; i < maxEnemiesLv5; i++)
    {
        PlayerEnemyCollision(player, lv5, enemies[i]);
    }

    for (int i = maxObstaclesLv4; i < maxObstaclesLv5; i++)
    {
        PlayerObstacleCollision(player, lv5, obstacles[i]);
    }

    //Lv6
    for (int i = maxPlatformsLv5; i < maxPlatformsLv6; i++)
    {
        PlayerPlatformsCollision(player, lv6, platforms[i]);
    }

    for (int i = maxObstaclesLv5; i < maxObstaclesLv6; i++)
    {
        PlayerObstacleCollision(player, lv6, obstacles[i]);
    }

    //Lv7
    for (int i = maxPlatformsLv6; i < maxPlatformsLv7; i++)
    {
        PlayerPlatformsCollision(player, lv7, platforms[i]);
    }

    for (int i = maxEnemiesLv5; i < maxEnemiesLv7; i++)
    {
        PlayerEnemyCollision(player, lv7, enemies[i]);
    }

    //Lv8
    for (int i = maxPlatformsLv7; i < maxPlatformsLv8; i++)
    {
        PlayerPlatformsCollision(player, lv8, platforms[i]);
    }
}

void PlayerCollisionLimitLeft(Player& players, Wall& walls)
{
    if (players.pos.x > walls.pos.x - walls.width)
    {
        players.pos.x = walls.pos.x - walls.width;
    }
}

void PlayerCollisionLimitRight(Player& players, Wall& walls)
{
    if (players.pos.x < walls.pos.x + walls.width)
    {
        players.pos.x = walls.pos.x + walls.width;
    }
}

void PlayerCollisionLimitUpAndDown(Player& players, int screenHeight)
{
    if (players.pos.y > static_cast<float>(screenHeight))
    {
        players.pos.y = static_cast<float>(screenHeight / screenHeight);
    }

    if (players.pos.y < static_cast<float>(screenHeight / screenHeight))
    {
        players.pos.y = static_cast<float>(screenHeight);
    }
}

void PlayerPlatformsCollision(Player& players, Level& lvs, Platform& platform)
{
    if (lvs.isLvActive == true)
    {
        if (CheckCollisionRecRec(players.pos, players.width, players.height, platform.pos, platform.width, platform.height))
        {
            player.gravity = 0;
            player.canJump = true;
            cont = 0.3f;
        }

        if (lv1.isLvActive == true)
        {
            if (CheckCollisionRecRec(player.pos, player.width, player.height, platforms[0].pos, platforms[0].width, platforms[0].height))
            {
                player.canGoDown = false;
            }

            else
            {
                player.canGoDown = true;
            }
        }
    }
}

void PlayerEnemyCollision(Player& players, Level& lvs, Enemy& enemy)
{
    if (lvs.isLvActive == true)
    {
        if (enemy.isActive == true)
        {
            if (CheckCollisionRecRec(players.pos, players.width, players.height, enemy.hitPos, enemy.widthHit, enemy.heightHit))
            {
                enemy.isActive = false;
            }

            if (CheckCollisionRecRec(players.pos, players.width, players.height, enemy.pos, enemy.width, enemy.height))
            {
                players.isActive = false;
                AddDead(players);
                RestartGame();
            }
        }
    }
}

void PlayerObstacleCollision(Player& players, Level& lvs, Obstacle& obstacle)
{
    if (lvs.isLvActive == true)
    {
        if (CheckCollisionRecRec(players.pos, players.width, players.height, obstacle.pos, obstacle.width, obstacle.height))
        {
            players.isActive = false;
            AddDead(players);
            RestartGame();
        }
    }
}

void EnemyWallCollision(Enemy& enemyLv)
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
    int texWidthLimitRight = 1070;
    int texWidthLimitLeft = 1070;

    players.frameCounter++;

    if (players.isActive == true && pause == false)
    {
        if (IsKeyDown(KEY_A))
        {
            players.pos.x -= players.speed * GetFrameTime();

            if (players.frameCounter >= (60 / players.frameSpeed))
            {
                players.frameCounter = 0;

                currentFrame++;

                if (currentFrame > 8)
                {
                    currentFrame = 0;
                }

                players.frameRec.x = static_cast<float>(currentFrame) * static_cast<float>(player.texWalkLeft.width - texWidthLimitLeft);
            }
        }

        if (IsKeyDown(KEY_D))
        {
            players.pos.x += players.speed * GetFrameTime();

            if (players.frameCounter >= (60 / players.frameSpeed))
            {
                players.frameCounter = 0;

                currentFrame++;

                if (currentFrame > 8)
                {
                    currentFrame = 0;
                }

                players.frameRec.x = static_cast<float>(currentFrame) * static_cast<float>(player.texWalkRight.width - texWidthLimitRight);
            }
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

        if (!IsKeyDown(KEY_A) && !IsKeyDown(KEY_D) && IsKeyDown(KEY_S) && IsKeyDown(KEY_W))
        {
            players.actualAnim = 0;
        }
    }
}

void PlayerJump(Player& players)
{
    players.gravity = -350;
    players.pos.y = players.pos.y + players.jumpForce * GetFrameTime();
}

void AllEnemiesMovement()
{
    for (int i = 0; i < maxEnemiesLv2; i++)
    {
        EnemyMovement(enemies[i], lv2);
    }

    for (int i = maxEnemiesLv2; i < maxEnemiesLv4; i++)
    {
        EnemyMovement(enemies[i], lv4);
    }

    for (int i = maxEnemiesLv4; i < maxEnemiesLv5; i++)
    {
        EnemyMovement(enemies[i], lv5);
    }

    for (int i = maxEnemiesLv5; i < maxEnemiesLv7; i++)
    {
        EnemyMovement(enemies[i], lv7);
    }
}

void EnemyMovement(Enemy& enemys, Level& lv)
{
    if (enemys.isActive == true && lv.isLvActive == true)
    {
        if (enemys.dir == MoveDir::Left)
        {
            enemys.goRight = false;
            enemys.goLeft = true;
            enemys.pos.x -= enemys.speed * GetFrameTime();
            enemys.hitPos.x -= enemys.speed * GetFrameTime();
        }

        if (enemys.dir == MoveDir::Right)
        {
            enemys.goRight = true;
            enemys.goLeft = false;
            enemys.pos.x += enemys.speed * GetFrameTime();
            enemys.hitPos.x += enemys.speed * GetFrameTime();
        }
    }
}

void AllObstaclesMovement()
{
    for (int i = 0; i < maxObstaclesLv3; i++)
    {
        ObstacleMovement(obstacles[i], lv3);
    }

    for (int i = maxObstaclesLv3; i < maxObstaclesLv4; i++)
    {
        ObstacleMovement(obstacles[i], lv4);
    }

    for (int i = maxObstaclesLv4; i < maxObstaclesLv5; i++)
    {
        ObstacleMovement(obstacles[i], lv5);
    }

    for (int i = maxObstaclesLv5; i < maxObstaclesLv6; i++)
    {
        ObstacleMovement(obstacles[i], lv6);
    }
}

void ObstacleMovement(Obstacle& obstacle, Level& lv)
{
    if (lv.isLvActive == true)
    {
        obstacle.pos.y += obstacle.speed * GetFrameTime();
    }
}

void MouseMovement()
{
    mouse.position = GetMousePosition();
}

void NextLevel(int screenHeight)
{
    if (player.pos.y < static_cast<float>(screenHeight / screenHeight))
    {
        lvCounter++;

        if (lvCounter == 2)
        {
            lv1.isLvActive = false;
            lv2.isLvActive = true;
            lv3.isLvActive = false;
            lv4.isLvActive = false;
            lv5.isLvActive = false;
            lv6.isLvActive = false;
            lv7.isLvActive = false;
            lv8.isLvActive = false;
        }

        if (lvCounter == 3)
        {
            lv1.isLvActive = false;
            lv2.isLvActive = false;
            lv3.isLvActive = true;
            lv4.isLvActive = false;
            lv5.isLvActive = false;
            lv6.isLvActive = false;
            lv7.isLvActive = false;
            lv8.isLvActive = false;
        }

        if (lvCounter == 4)
        {
            lv1.isLvActive = false;
            lv2.isLvActive = false;
            lv3.isLvActive = false;
            lv4.isLvActive = true;
            lv5.isLvActive = false;
            lv6.isLvActive = false;
            lv7.isLvActive = false;
            lv8.isLvActive = false;
        }

        if (lvCounter == 5)
        {
            lv1.isLvActive = false;
            lv2.isLvActive = false;
            lv3.isLvActive = false;
            lv4.isLvActive = false;
            lv5.isLvActive = true;
            lv6.isLvActive = false;
            lv7.isLvActive = false;
            lv8.isLvActive = false;
        }

        if (lvCounter == 6)
        {
            lv1.isLvActive = false;
            lv2.isLvActive = false;
            lv3.isLvActive = false;
            lv4.isLvActive = false;
            lv5.isLvActive = false;
            lv6.isLvActive = true;
            lv7.isLvActive = false;
            lv8.isLvActive = false;
        }

        if (lvCounter == 7)
        {
            lv1.isLvActive = false;
            lv2.isLvActive = false;
            lv3.isLvActive = false;
            lv4.isLvActive = false;
            lv5.isLvActive = false;
            lv6.isLvActive = false;
            lv7.isLvActive = true;
            lv8.isLvActive = false;
        }

        if (lvCounter == 8)
        {
            lv1.isLvActive = false;
            lv2.isLvActive = false;
            lv3.isLvActive = false;
            lv4.isLvActive = false;
            lv5.isLvActive = false;
            lv6.isLvActive = false;
            lv7.isLvActive = false;
            lv8.isLvActive = true;
        }
    }
}

void PreviusLevel(int screenHeight)
{
    if (player.pos.y > static_cast<float>(screenHeight))
    {
        lvCounter--;

        if (lvCounter == 1)
        {
            lv1.isLvActive = true;
            lv2.isLvActive = false;
            lv3.isLvActive = false;
            lv4.isLvActive = false;
            lv5.isLvActive = false;
            lv6.isLvActive = false;
            lv7.isLvActive = false;
            lv8.isLvActive = false;
        }

        if (lvCounter == 2)
        {
            lv1.isLvActive = false;
            lv2.isLvActive = true;
            lv3.isLvActive = false;
            lv4.isLvActive = false;
            lv5.isLvActive = false;
            lv6.isLvActive = false;
            lv7.isLvActive = false;
            lv8.isLvActive = false;
        }

        if (lvCounter == 3)
        {
            lv1.isLvActive = false;
            lv2.isLvActive = false;
            lv3.isLvActive = true;
            lv4.isLvActive = false;
            lv5.isLvActive = false;
            lv6.isLvActive = false;
            lv7.isLvActive = false;
            lv8.isLvActive = false;
        }

        if (lvCounter == 4)
        {
            lv1.isLvActive = false;
            lv2.isLvActive = false;
            lv3.isLvActive = false;
            lv4.isLvActive = true;
            lv5.isLvActive = false;
            lv6.isLvActive = false;
            lv7.isLvActive = false;
            lv8.isLvActive = false;
        }

        if (lvCounter == 5)
        {
            lv1.isLvActive = false;
            lv2.isLvActive = false;
            lv3.isLvActive = false;
            lv4.isLvActive = false;
            lv5.isLvActive = true;
            lv6.isLvActive = false;
            lv7.isLvActive = false;
            lv8.isLvActive = false;
        }

        if (lvCounter == 6)
        {
            lv1.isLvActive = false;
            lv2.isLvActive = false;
            lv3.isLvActive = false;
            lv4.isLvActive = false;
            lv5.isLvActive = false;
            lv6.isLvActive = true;
            lv7.isLvActive = false;
            lv8.isLvActive = false;
        }

        if (lvCounter == 7)
        {
            lv1.isLvActive = false;
            lv2.isLvActive = false;
            lv3.isLvActive = false;
            lv4.isLvActive = false;
            lv5.isLvActive = false;
            lv6.isLvActive = false;
            lv7.isLvActive = true;
            lv8.isLvActive = false;
        }
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
    lv8.isLvActive = false;

    player.pos.x = static_cast<float>(GetScreenWidth() / 2.1f);
    player.pos.y = static_cast<float>(GetScreenHeight() / 1.2f);

    //Enemies
    for (int i = 0; i < maxEnemies; i++)
    {
        enemies[i].isActive = true;
    }
    //Lv2
    enemies[0].pos.x = static_cast<float>(GetScreenWidth() / 2.1f);
    enemies[0].pos.y = static_cast<float>(GetScreenHeight() / 1.37f);
    enemies[0].hitPos.x = enemies[0].pos.x + enemies[0].heightHit;
    enemies[0].hitPos.y = enemies[0].pos.y - enemies[0].heightHit;

    enemies[1].pos.x = static_cast<float>(GetScreenWidth() / 2.1f);
    enemies[1].pos.y = static_cast<float>(GetScreenHeight() / 2.68f);
    enemies[1].hitPos.x = enemies[1].pos.x + enemies[1].heightHit;
    enemies[1].hitPos.y = enemies[1].pos.y - enemies[1].heightHit;
    enemies[1].dir = MoveDir::Left;

    //Lv4
    enemies[2].pos.x = static_cast<float>(GetScreenWidth() / 2.1f);
    enemies[2].pos.y = static_cast<float>(GetScreenHeight() / 4.8f);
    enemies[2].hitPos.x = enemies[2].pos.x + enemies[2].heightHit;
    enemies[2].hitPos.y = enemies[2].pos.y - enemies[2].heightHit;
    enemies[2].dir = MoveDir::Left;

    //Lv5
    enemies[3].pos.x = static_cast<float>(GetScreenWidth() / 1.4f);
    enemies[3].pos.y = static_cast<float>(GetScreenHeight() / 1.37f);
    enemies[3].hitPos.x = enemies[3].pos.x + enemies[3].heightHit;
    enemies[3].hitPos.y = enemies[3].pos.y - enemies[3].heightHit;

    //Lv7
    enemies[4].pos.x = static_cast<float>(GetScreenWidth() / 1.4f);
    enemies[4].pos.y = static_cast<float>(GetScreenHeight() / 1.37f);
    enemies[4].hitPos.x = enemies[4].pos.x + enemies[4].heightHit;
    enemies[4].hitPos.y = enemies[4].pos.y - enemies[4].heightHit;

    enemies[5].pos.x = static_cast<float>(GetScreenWidth() / 6);
    enemies[5].pos.y = static_cast<float>(GetScreenHeight() / 1.37f);
    enemies[5].hitPos.x = enemies[5].pos.x + enemies[5].heightHit;
    enemies[5].hitPos.y = enemies[5].pos.y - enemies[5].heightHit;

    enemies[6].pos.x = static_cast<float>(GetScreenWidth() / 1.4f);
    enemies[6].pos.y = static_cast<float>(GetScreenHeight() / 2.5f);
    enemies[6].hitPos.x = enemies[6].pos.x + enemies[6].heightHit;
    enemies[6].hitPos.y = enemies[6].pos.y - enemies[6].heightHit;

    enemies[7].pos.x = static_cast<float>(GetScreenWidth() / 6);
    enemies[7].pos.y = static_cast<float>(GetScreenHeight() / 2.5f);
    enemies[7].hitPos.x = enemies[7].pos.x + enemies[7].heightHit;
    enemies[7].hitPos.y = enemies[7].pos.y - enemies[7].heightHit;

    for (int i = 0; i < maxObstacles; i++)
    {
        obstacles[i].pos.y = -150;
    }

    player.isActive = true;

    //RestartMenu
    restartMenu.isActive = false;
    pause = false;
}

void UnloadData()
{
    UnloadFont(gameFont);

    UnloadTexture(mouse.texture);

    UnloadTexture(player.texWalkRight);
    UnloadTexture(player.texWalkLeft);

    UnloadTexture(restartMenu.texture);
    UnloadTexture(pauseMenu.texture);
    UnloadTexture(pauseButtonOff.texture);
    UnloadTexture(pauseButtonOn.texture);

    UnloadTexture(menuBackground);
    UnloadTexture(subMenusBackground);

    for (int i = 0; i < maxEnemies; i++)
    {
        UnloadTexture(enemies[i].texWalkLeft);
    }

    for (int i = 0; i < maxObstacles; i++)
    {
        UnloadTexture(obstacles[i].tex);
    }

    UnloadTexture(background.tex);
    UnloadTexture(background.tex2);

    UnloadMusicStream(music);
}