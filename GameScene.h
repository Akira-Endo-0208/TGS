#pragma once

#include "Player.h"
#include "Enemy.h"
#include "Collision.h"
#include "Input.h"


class GameScene
{
public:	// �����o�֐�
	void Initialize();	// ������
	void Update();		// �X�V
	void Draw();		// �`��
	int GetScene() { return scene; }
private: // �����o�ϐ�
	// �V�[���؂�ւ�
	int scene = 4;

	Player* player;
	Enemy* enemy;
	Collision* collision;
	Input* input;
};