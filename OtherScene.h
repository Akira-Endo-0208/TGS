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
	int SelectScene() { return scene = 1; }
	int GameOverScene() { return scene = 2; }
	int GameClaerScene() { return scene = 3; }
	int GetSelectScene() { return selectScene; }

private: // メンバ変数
	// シーン切り替え
	int scene = 0;
	int selectScene = 4;
	int selectFlag = 0;

	// キーボード変数
	char key[256] = { 0 }; //最新のキーボード情報用
	char oldkey[256] = { 0 };//1ループ（フレーム）前のキーボード情報

	// 画像
	int titleGraph = LoadGraph("Resources/Title.png");
	int stageSelectGraph = LoadGraph("Resources/StageSelect.png");
	int gameOverGraph = LoadGraph("Resources/GameOver.png");
	int gameClearGraph = LoadGraph("Resources/GameClear.png");

	// ポインタ
	Input* input;
};