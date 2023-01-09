#include "Objects/Enemy.h"

Enemy CreateEnemy()
{
	Enemy enemy;

	enemy.pos.x = 0;
	enemy.pos.y = 0;

	enemy.width = 120;
	enemy.height = 80;

	enemy.hitPos.x = 0;
	enemy.hitPos.y = 0;

	enemy.widthHit = 120;
	enemy.heightHit = 20;

	enemy.dir = MoveDir::Right;

	enemy.speed = 200.0f;

	enemy.isActive = true;

	enemy.color = PURPLE;
	enemy.hitColor = ORANGE;

	return enemy;
}

void DrawEnemy(Enemy& enemy, Level& lv)
{
	if (lv.isLvActive == true)
	{
		DrawRectangle(static_cast<int>(enemy.pos.x), static_cast<int>(enemy.pos.y), static_cast<int>(enemy.width), static_cast<int>(enemy.height), enemy.color);
		DrawRectangle(static_cast<int>(enemy.hitPos.x), static_cast<int>(enemy.hitPos.y), static_cast<int>(enemy.widthHit), static_cast<int>(enemy.heightHit), enemy.hitColor);
	}
}