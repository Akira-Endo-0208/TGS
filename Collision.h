#pragma once
#include "Player.h"
#include "Enemy.h"
#include "OtherScene.h"


class Collision
{
public: // メンバ関数
	void collisionInitialize(Player* player_, Enemy* enemy_, OtherScene* otherScene_);
	void collisionUpdate();
	void collisionPlayerEnemy();
private: // メンバ変数
	// ポインタ
	Player* player;
	Enemy* enemy;
	OtherScene* otherScene;
};