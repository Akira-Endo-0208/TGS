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

	if (selectScene == 4)
	{
		if (key[KEY_INPUT_D] == 1 && oldkey[KEY_INPUT_D] == 0 && scene == 1)
		{
			selectScene = 5;
			selectFlag += 1280;
		}
		else if (key[KEY_INPUT_S] == 1 && oldkey[KEY_INPUT_S] == 0 && scene == 1) {
			selectScene = 6;
			selectFlag += 2560;
		}
	}
	if (selectScene == 5)
	{
		if (key[KEY_INPUT_A] == 1 && oldkey[KEY_INPUT_A] == 0 && scene == 1)
		{
			selectScene = 4;
			selectFlag -= 1280;
		}
		else if (key[KEY_INPUT_S] == 1 && oldkey[KEY_INPUT_S] == 0 && scene == 1) {
			selectScene = 7;
			selectFlag += 2560;
		}
	}
	if (selectScene == 6)
	{
		if (key[KEY_INPUT_D] == 1 && oldkey[KEY_INPUT_D] == 0 && scene == 1)
		{
			selectScene = 7;
			selectFlag += 1280;
		}
		else if (key[KEY_INPUT_W] == 1 && oldkey[KEY_INPUT_W] == 0 && scene == 1) {
			selectScene = 4;
			selectFlag -= 2560;
		}
	}
	if (selectScene == 7)
	{
		if (key[KEY_INPUT_A] == 1 && oldkey[KEY_INPUT_A] == 0 && scene == 1)
		{
			selectScene = 6;
			selectFlag -= 1280;
		}
		else if (key[KEY_INPUT_W] == 1 && oldkey[KEY_INPUT_W] == 0 && scene == 1) {
			selectScene = 5;
			selectFlag -= 2560;
		}
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
		case 2: // �Q�[���I�[�o�[->�X�e�[�W�Z���N�g
			scene = 1;
			break;
		case 3: // �Q�[���N���A->�X�e�[�W�Z���N�g
			scene = 1;
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
		DrawRectGraph(0, 0, 0 + selectFlag, 0, 1280, 720, stageSelectGraph, TRUE, FALSE);
		//DrawFormatString(0, 0, GetColor(255, 255, 255), "�`���[�g���A��->4 �X�e�[�W1->5");
		//DrawFormatString(0, 20, GetColor(255, 255, 255), "�L�[A->-  �L�[D->+  (%d)", selectScene);
		break;
	case 2: // �Q�[���I�[�o�[
		DrawGraph(0, 0, gameOverGraph, TRUE);
		break;
	case 3: // �Q�[���N���A
		DrawGraph(0, 0, gameClearGraph, TRUE);
		break;
	}
}