#pragma once
#include "Player.h"
#include "Enemy.h"
#include "OtherScene.h"


class Collision
{
public: // �����o�֐�
	void collisionInitialize(Player* player_, Enemy* enemy_, OtherScene* otherScene_);
	void collisionUpdate();
	void collisionPlayerEnemy();
private: // �����o�ϐ�
	// �|�C���^
	Player* player;
	Enemy* enemy;
	OtherScene* otherScene;
};