#pragma once

#include "Player.h"
#include "Enemy.h"
#include "Collision.h"
#include "Input.h"
#include "OtherScene.h"


class GameScene
{
public:	// �����o�֐�
	void Initialize();	// ������
	void Update();		// �X�V
	void Draw();		// �`��
private: // �����o�ϐ�
	// �|�C���^
	Player* player;
	Enemy* enemy;
	Collision* collision;
	Input* input;
	OtherScene* otherScene;
};