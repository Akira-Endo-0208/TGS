#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Map.h"
#include "OtherScene.h"


class Collision
{
public: // メンバ関数
	void collisionInitialize(Player* player_, Enemy* enemy_, OtherScene* otherScene_, Map* map_);
	void collisionUpdate();
	void collisionPlayerEnemy();
	void collisionPlayerBlock();
	void collisionPlayerClaer();
private: // メンバ変数
	// ポインタ
	Player* player;
	Enemy* enemy;
	Map* map;
	OtherScene* otherScene;
	int damageSoundHandle = LoadSoundMem("Resources/Sounds/damage.wav");
};