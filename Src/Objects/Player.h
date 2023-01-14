#pragma once

#include "raylib.h"

#include "Objects/Wall.h"

#include "Window/LevelManager.h"

struct Player
{
	Vector2 pos;

	float width;
	float height;

	float speed;

	float gravity;
	float jumpForce;

	int deadCount;

	bool canJump;
	bool isAlive;
	bool win;
	bool isActive;
	bool canGoDown;

	Texture tex;
	Color color;
};

Player CreatePlayer(int screenWidth, int screenHeight);

void DrawPlayer(Player& player);

void AddDead(Player& player);

bool PlayerWin(Player& player, int& lvCounter);