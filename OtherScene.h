#pragma once
#include "Input.h"

class OtherScene
{
public: // メンバ関数
	void OtherSceneInitialize();
	void OtherSceneUpdate();
	void OtherSceneDraw();
	int GetScene() { return scene; }
	int TitleScene() { return scene = 0; }
	int GameOverScene() { return scene = 2; }
	int GameClaerScene() { return scene = 3; }
	int GetSelectScene() { return selectScene; }

private: // メンバ変数
	// シーン切り替え
	int scene = 0;
	int selectScene = 4;

	// キーボード変数
	char key[256] = { 0 }; //最新のキーボード情報用
	char oldkey[256] = { 0 };//1ループ（フレーム）前のキーボード情報

	// 画像
	int titleGraph = LoadGraph("Resources/title.png");
	int stageSelectGraph = LoadGraph("Resources/stageSelect.png");
	int gameOverGraph = LoadGraph("Resources/gameOver_.png");
	int gameClearGraph = LoadGraph("Resources/clear_kari.png");

	// ポインタ
	Input* input;
};