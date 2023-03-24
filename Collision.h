#pragma once
#include "Player.h"
#include "Enemy.h"


class Collision
{
public:
	void collisionInitialize(Player* player_, Enemy* enemy_);
	void collisionUpdate();
	void collisionPlayerEnemy();
private:
	Player* player;
	Enemy* enemy;
};