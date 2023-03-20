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
	//otherScene = new OtherScene();

	player->playerInitialize(input);
	enemy->enemyInitialize();
	collision->collisionInitialize(player, enemy);
	//otherScene->OtherSceneInitialize();

	// �����̏�����
	srand(time(NULL));
}

// �X�V
void GameScene::Update()
{
	switch (scene)
	{
	case 0:	// �^�C�g��
		//otherScene->OtherSceneUpdate();
		break;
	case 1:	// �Q�[���I�[�o�[
		//otherScene->OtherSceneUpdate();
		break;
	case 2:	// �Q�[���N���A
		//otherScene->OtherSceneUpdate();
		break;
	case 3:	// �`���[�g���A��
		player->playerUpdate();
		enemy->enemyUpdate();
		collision->collisionUpdate();
		break;
	case 4:	// �Q�[�����
		player->playerUpdate();
		enemy->enemyUpdate();
		collision->collisionUpdate();
		break;
	}
}

// �`��
void GameScene::Draw()
{
	switch (scene)
	{
	case 0:	// �^�C�g��
		//otherScene->OtherSceneDraw();
		DrawFormatString(0, 0, GetColor(255, 255, 255), "�^�C�g��   SPACE->�Q�[�����");
		break;
	case 1:	// �Q�[���I�[�o�[
		//otherScene->OtherSceneDraw();
		DrawFormatString(0, 0, GetColor(255, 255, 255), "�Q�[���I�[�o�[   SPACE->�^�C�g��");
		break;
	case 2:	// �Q�[���N���A
		//otherScene->OtherSceneDraw();
		DrawFormatString(0, 0, GetColor(255, 255, 255), "�Q�[���N���A  SPACE->�^�C�g��");
		break;
	case 3:	// �`���[�g���A��
		player->playerDraw();
		enemy->enemyDraw();
		DrawFormatString(0, 0, GetColor(255, 255, 255), "�`���[�g���A��   SPACE->�Q�[�����");
		break;
	case 4:	// �Q�[�����
		player->playerDraw();
		enemy->enemyDraw();
		DrawFormatString(0, 0, GetColor(255, 255, 255), "SPACE             �W�����v");
		DrawFormatString(0, 20, GetColor(255, 255, 255), "�W�����v����SPACE  2�i�W�����v");
		DrawFormatString(0, 40, GetColor(255, 255, 255), "S                 �X���C�f�B���O");
		break;
	}
}