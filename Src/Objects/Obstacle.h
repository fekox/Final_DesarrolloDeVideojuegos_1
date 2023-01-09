#pragma once
#include "raylib.h"

#include "Window/LevelManager.h"

struct Obstacle
{
	Vector2 pos;

	float width;
	float height;

	float speed;

	bool isActive;

	Texture tex;
	Color color;
};

Obstacle CreateObstacle();

void ObstacleCollisionLimit(Obstacle& obstacle, int screenHeight);

void DrawObstacle(Obstacle& obstacle, Level& lv);