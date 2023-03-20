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

	if (key[KEY_INPUT_SPACE] == 1 && oldkey[KEY_INPUT_SPACE] == 0)
	{

	}
}

void OtherScene::OtherSceneDraw()
{

}