#include "DxLib.h"
#include "GameScene.h"
#include <time.h>


// ������
void GameScene::Initialize()
{
	player = new Player();
	enemy = new Enemy();
	input = new Input();
	map = new Map();

	player->playerInitialize();
	enemy->enemyInitialize();
	map->Initialize(player);

	// �����̏�����
	srand(time(NULL));
}

// �X�V
void GameScene::Update()
{
	input->SaveoldKey();
	GetHitKeyStateAll(key);

	switch (scene)
	{
	case 0:	// �^�C�g��
		break;
	case 1:	// �Q�[�����
		player->playerUpdate();
		enemy->enemyUpdate();
		break;
	case 2:	// �`���[�g���A��
		break;
	case 3:	// �Q�[���I�[�o�[
		break;
	case 4:	// �Q�[���N���A
		break;
	}
}

// �`��
void GameScene::Draw()
{
	switch (scene)
	{
	case 0:	// �^�C�g��
		break;
	case 1:	// �Q�[�����
		
		player->playerDraw();
		enemy->enemyDraw();
		map->Draw();
		break;
	case 2:	// �`���[�g���A��
		break;
	case 3:	// �Q�[���I�[�o�[
		break;
	case 4:	// �Q�[���N���A
		break;
	}
}