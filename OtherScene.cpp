#include "DxLib.h"
#include "OtherScene.h"


void OtherScene::OtherSceneInitialize()
{

}

void OtherScene::OtherSceneUpdate()
{
	for (int i = 0; i < 256; ++i)
	{
		oldkey[i] = key[i];
	}
	GetHitKeyStateAll(key);

	if (key[KEY_INPUT_A] == 1 && oldkey[KEY_INPUT_A] == 0 && scene == 1 && selectScene > 4)
	{
		selectScene--;
	} else if (key[KEY_INPUT_D] == 1 && oldkey[KEY_INPUT_D] == 0 && scene == 1 && selectScene < 7) {
		selectScene++;
	}

	if (key[KEY_INPUT_SPACE] == 1 && oldkey[KEY_INPUT_SPACE] == 0)
	{
		switch (scene)
		{
		case 0: // �^�C�g��->�X�e�[�W�Z���N�g
			scene = 1;
			break;
		case 1: // �X�e�[�W�Z���N�g->�Q�[�����
			scene = selectScene;
			break;
		case 2: // �Q�[���I�[�o�[->�^�C�g��
			scene = 0;
			break;
		case 3: // �Q�[���N���A->�^�C�g��
			scene = 0;
			break;
		}
	}
}

void OtherScene::OtherSceneDraw()
{
	switch (scene)
	{
	case 0: // �^�C�g��
		DrawGraph(0, 0, titleGraph, TRUE);
		break;
	case 1: // �X�e�[�W�Z���N�g
		DrawGraph(0, 0, stageSelectGraph, TRUE);
		DrawFormatString(0, 0, GetColor(255, 255, 255), "�`���[�g���A��->4 �X�e�[�W1->5");
		DrawFormatString(0, 20, GetColor(255, 255, 255), "�L�[A->-  �L�[D->+  (%d)", selectScene);
		break;
	case 2: // �Q�[���I�[�o�[
		DrawGraph(0, 0, gameOverGraph, TRUE);
		break;
	case 3: // �Q�[���N���A
		DrawGraph(0, 0, gameClearGraph, TRUE);
		break;
	}
}