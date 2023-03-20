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
	// �L�[�{�[�h�ϐ�
	char key[256] = { 0 }; //�ŐV�̃L�[�{�[�h���p
	char oldkey[256] = { 0 };//1���[�v�i�t���[���j�O�̃L�[�{�[�h���

	int titleGraph = LoadGraph("Resources/Title.png");
	int gameOverGraph = LoadGraph("Resources/gameOver_.png");
	int gameClearGraph = LoadGraph("Resources/GameClear_.png");

	Input* input;
};