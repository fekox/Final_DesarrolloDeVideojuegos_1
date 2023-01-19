#pragma once
#include "raylib.h"

enum class Levels
{
    one = 1,
    two,
    three,
    four,
    five, 
    six,
    seven,
    eight
};

struct SubMenu
{
    Vector2 pos;

    float width;
    float height;

    Texture texture;

    bool isActive;
};

struct Button
{
    Vector2 pos;

    float width;
    float height;

    int size;

    Texture texture;

    Color color;
};

void StartGame();
void InitGame(int screenWidth, int screenHeight);
void GameLoop();
void Update();
void Collisions();
void Draw();

void RestartGame();
void UnloadData();
