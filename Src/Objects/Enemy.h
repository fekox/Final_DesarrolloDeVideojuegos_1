#pragma once

#include "raylib.h"

#include "Objects/Wall.h"

#include "Window/LevelManager.h"

enum class MoveDir
{
	Right,
	Left
};

struct Enemy
{
	Vector2 pos;

	Vector2 hitPos;

	float width;
	float height;

	float widthHit;
	float heightHit;

	float speed;

	bool isActive;

	MoveDir dir;

	Texture tex;
	Color color;
	Color hitColor;
};

Enemy CreateEnemy();
void DrawEnemy(Enemy& enemy, Level& lv);
