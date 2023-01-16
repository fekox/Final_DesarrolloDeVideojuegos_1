#pragma once

#include "raylib.h"

#include "Objects/Wall.h"

#include "Window/LevelManager.h"

enum class PlayerAnimations
{
	WalkRight,
	Jump,
	Grab
};

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

	int actualAnim;

	Texture tex;

	Rectangle frameRec;
	int frameCounter;
	int frameSpeed;

	Color color;
};

Player CreatePlayer(int screenWidth, int screenHeight);

void DrawPlayer(Player& player);

void InitAnimations(Player& player);

void AddDead(Player& player);

bool PlayerWin(Player& player, int& lvCounter);