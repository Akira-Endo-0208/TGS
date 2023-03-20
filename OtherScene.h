#pragma once
#include "GameScene.h"
#include "Input.h"


class OtherScene
{
public:
	void OtherSceneInitialize();
	void OtherSceneUpdate();
	void OtherSceneDraw();
private:
	// キーボード変数
	char key[256] = { 0 }; //最新のキーボード情報用
	char oldkey[256] = { 0 };//1ループ（フレーム）前のキーボード情報

	int titleGraph = LoadGraph("Resources/Title.png");
	int gameOverGraph = LoadGraph("Resources/gameOver_.png");
	int gameClearGraph = LoadGraph("Resources/GameClear_.png");

	Input* input;
};