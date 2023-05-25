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
		case 0: // タイトル->ステージセレクト
			scene = 1;
			break;
		case 1: // ステージセレクト->ゲーム画面
			scene = selectScene;
			break;
		case 2: // ゲームオーバー->ステージセレクト
			scene = 1;
			break;
		case 3: // ゲームクリア->ステージセレクト
			scene = 1;
			break;
		}
	}
}

void OtherScene::OtherSceneDraw()
{
	switch (scene)
	{
	case 0: // タイトル
		DrawGraph(0, 0, titleGraph, TRUE);
		break;
	case 1: // ステージセレクト
		DrawRectGraph(0, 0, 0 + selectFlag, 0, 1280, 720, stageSelectGraph, TRUE, FALSE);
		//DrawFormatString(0, 0, GetColor(255, 255, 255), "チュートリアル->4 ステージ1->5");
		//DrawFormatString(0, 20, GetColor(255, 255, 255), "キーA->-  キーD->+  (%d)", selectScene);
		break;
	case 2: // ゲームオーバー
		DrawGraph(0, 0, gameOverGraph, TRUE);
		break;
	case 3: // ゲームクリア
		DrawGraph(0, 0, gameClearGraph, TRUE);
		break;
	}
}