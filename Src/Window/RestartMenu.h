#pragma once
#include "Window/PlayGame.h"

#include "Objects/Mouse.h"

#include "Objects/Player.h"

void InitRestartMenu(SubMenu& restartMenu, Button& restartButton, Button& returnMenuButton, Button& quitGameButton, int screenWidth, int screenHeight);
void RestartMenuInputs(SubMenu& restartMenu, bool& pause, bool& playGame, bool& gameOn, int& optionSelect, Mouse& mouse, int screenWidth, int screenHeight, Player& player);
void RestarGameMenuCollisions(SubMenu& restartMenu, Button& restartButton, Button& returnMenuButton, Button& quitGameButton, Mouse& mouse, int screenWidth, int screenHeight);
void DrawRestarGameMenu(SubMenu& restartMenu, Button& restartButton, Button& returnMenuButton, Button& quitGameButton, Player& player, Font gameFont, int screenWidth, int screenHeigh, int& lvCounter);