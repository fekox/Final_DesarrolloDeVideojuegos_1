#include "Window/RestartMenu.h"
#include "Window/PlayGame.h"

#include "Objects/Player.h"

void InitRestartMenu(SubMenu& restartMenu, Button& restartButton, Button& returnMenuButton, Button& quitGameButton, int screenWidth, int screenHeight)
{
    //Restart menu
    restartMenu.width = 600;
    restartMenu.height = 500;
    restartMenu.pos.x = static_cast<float>(screenWidth / 4.5);
    restartMenu.pos.y = static_cast<float>(screenHeight / 4.5);
    restartMenu.isActive = false;
    restartMenu.texture = LoadTexture("resources/Sprites/RestartGameMenu.png");

    //Restart Button
    restartButton.width = static_cast<float>(screenWidth / 2.2);
    restartButton.height = static_cast<float>(screenHeight / 2.1);
    restartButton.size = 50;
    restartButton.color = WHITE;

    //Menu Button
    returnMenuButton.width = static_cast<float>(screenWidth / 2.1);
    returnMenuButton.height = static_cast<float>(screenHeight / 1.65);
    returnMenuButton.size = 50;
    returnMenuButton.color = WHITE;

    //Quit Button
    quitGameButton.width = static_cast<float>(screenWidth / 2.1);
    quitGameButton.height = static_cast<float>(screenHeight / 1.37);
    quitGameButton.size = 50;
    quitGameButton.color = WHITE;
}

void RestartMenuInputs(SubMenu& restartMenu, bool& pause, bool& playGame, bool& gameOn, int& optionSelect, Mouse& mouse, int screenWidth, int screenHeight, Player& player)
{
    if (restartMenu.isActive)
    {
        pause = true;

        //Restart Button
        if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 2.5), static_cast<float>(screenHeight / 2.2), static_cast<float>(screenWidth / 4), static_cast<float>(screenHeight / 10) }))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                RestartGame();
                player.deadCount = 0;
            }
        }

        //Return Menu Button
        if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 2.5), static_cast<float>(screenHeight / 1.7), static_cast<float>(screenWidth / 4), static_cast<float>(screenHeight / 12) }))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                RestartGame();
                player.deadCount = 0;

                restartMenu.isActive = false;
                playGame = false;
                optionSelect = 0;
            }
        }

        //Quit Game Button
        if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 2.5), static_cast<float>(screenHeight / 1.4), static_cast<float>(screenWidth / 4), static_cast<float>(screenHeight / 12) }))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                gameOn = false;
            }
        }
    }
}

void RestarGameMenuCollisions(SubMenu& restartMenu, Button& restartButton, Button& returnMenuButton, Button& quitGameButton, Mouse& mouse, int screenWidth, int screenHeight)
{
    if (restartMenu.isActive)
    {
        //Restart Button
        if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 2.7), static_cast<float>(screenHeight / 2.2), static_cast<float>(screenWidth / 3.2), static_cast<float>(screenHeight / 10) }))
        {
            restartButton.color = RED;
        }

        else
        {
            restartButton.color = WHITE;
        }

        //Return Menu Button
        if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 2.5), static_cast<float>(screenHeight / 1.7), static_cast<float>(screenWidth / 4), static_cast<float>(screenHeight / 12) }))
        {
            returnMenuButton.color = RED;
        }

        else
        {
            returnMenuButton.color = WHITE;
        }

        //Quit Game Button
        if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(screenWidth / 2.5), static_cast<float>(screenHeight / 1.4), static_cast<float>(screenWidth / 4), static_cast<float>(screenHeight / 12) }))
        {
            quitGameButton.color = RED;
        }

        else
        {
            quitGameButton.color = WHITE;
        }
    }
}

void DrawRestarGameMenu(SubMenu& restartMenu, Button& restartButton, Button& returnMenuButton, Button& quitGameButton, Player& player, Font gameFont, int screenWidth, int screenHeight, int& lvCounter)
{
    DrawRectangle(static_cast<int>(restartMenu.pos.x), static_cast<int>(restartMenu.pos.y), static_cast<int>(restartMenu.width), static_cast<int>(restartMenu.height), BLANK);
    restartMenu.isActive = true;

    DrawTexture(restartMenu.texture, static_cast<int>(restartMenu.pos.x), static_cast<int>(restartMenu.pos.y), WHITE);

    if (PlayerWin(player, lvCounter))
    {
        DrawTextEx(gameFont, "YOU WIN", { static_cast<float>(screenWidth / 2.4), static_cast<float>(screenHeight / 3.1) }, 70, 0, GOLD);
    }


    //Restart Button
    DrawRectangle(static_cast<int>(screenWidth / 2.7), static_cast<int>(screenHeight / 2.2), static_cast<int>(screenWidth / 3.2), static_cast<int>(screenHeight / 10), BLANK);
    DrawTextEx(gameFont, "RESTART", { static_cast<float>(restartButton.width), static_cast<float>(restartButton.height) }, static_cast<float>(restartButton.size), 0, restartButton.color);


    //Return Menu Button
    DrawRectangle(static_cast<int>(screenWidth / 2.5), static_cast<int>(screenHeight / 1.7), static_cast<int>(screenWidth / 4), static_cast<int>(screenHeight / 12), BLANK);
    DrawTextEx(gameFont, "MENU", { static_cast<float>(returnMenuButton.width), static_cast<float>(returnMenuButton.height) }, static_cast<float>(returnMenuButton.size), 0, returnMenuButton.color);

    //Quit Game Button
    DrawRectangle(static_cast<int>(screenWidth / 2.5), static_cast<int>(screenHeight / 1.4), static_cast<int>(screenWidth / 4), static_cast<int>(screenHeight / 12), BLANK);
    DrawTextEx(gameFont, "QUIT", { static_cast<float>(quitGameButton.width), static_cast<float>(quitGameButton.height) }, static_cast<float>(quitGameButton.size), 0, quitGameButton.color);
}