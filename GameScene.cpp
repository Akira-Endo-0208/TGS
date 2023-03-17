#include "DxLib.h"
#include "GameScene.h"
#include <time.h>


// ������
void GameScene::Initialize()
{
	player = new Player();
	enemy = new Enemy();
	collision = new Collision();
	input = new Input();

	player->playerInitialize(input);
	enemy->enemyInitialize();
	collision->collisionInitialize(player, enemy);

	// �����̏�����
	srand(time(NULL));
}

// �X�V
void GameScene::Update()
{
	switch (scene)
	{
	case 0:	// �^�C�g��
		break;
	case 1:	// �Q�[�����
		player->playerUpdate();
		enemy->enemyUpdate();
		collision->collisionUpdate();
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
		DrawFormatString(0, 0, GetColor(255, 255, 255), "SPACE             �W�����v");
		DrawFormatString(0, 20, GetColor(255, 255, 255), "�W�����v����SPACE  2�i�W�����v");
		DrawFormatString(0, 40, GetColor(255, 255, 255), "S                 �X���C�f�B���O");
		break;
	case 2:	// �`���[�g���A��
		break;
	case 3:	// �Q�[���I�[�o�[
		break;
	case 4:	// �Q�[���N���A
		break;
	}
}