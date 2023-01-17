#include "Objects/Enemy.h"

Enemy CreateEnemy()
{
	Enemy enemy;

	enemy.pos.x = 0;
	enemy.pos.y = 0;

	enemy.width = 130;
	enemy.height = 80;

	enemy.hitPos.x = 0;
	enemy.hitPos.y = 0;

	enemy.widthHit = 100;
	enemy.heightHit = 20;

	enemy.dir = MoveDir::Right;

	enemy.speed = 200.0f;

	enemy.isActive = true;

	enemy.texWalkLeft = LoadTexture("resources/Sprites/Seal_Left.png");
	enemy.texWalkRight = LoadTexture("resources/Sprites/Seal_Right.png");

	enemy.color = BLANK;
	enemy.hitColor = BLANK;

	return enemy;
}

void DrawEnemy(Enemy& enemy, Level& lv)
{
	int texRepoX = 20;
	int texRepoY = 12;

	if (lv.isLvActive == true)
	{
		DrawRectangle(static_cast<int>(enemy.pos.x), static_cast<int>(enemy.pos.y), static_cast<int>(enemy.width), static_cast<int>(enemy.height), enemy.color);
		DrawRectangle(static_cast<int>(enemy.hitPos.x), static_cast<int>(enemy.hitPos.y), static_cast<int>(enemy.widthHit), static_cast<int>(enemy.heightHit), enemy.hitColor);

		if (enemy.goLeft == true)
		{
			DrawTexture(enemy.texWalkLeft, static_cast<int>(enemy.pos.x - texRepoX), static_cast<int>(enemy.pos.y - texRepoY), WHITE);
		}

		if (enemy.goRight == true)
		{
			DrawTexture(enemy.texWalkRight, static_cast<int>(enemy.pos.x - texRepoX), static_cast<int>(enemy.pos.y - texRepoY), WHITE);
		}
	}
}