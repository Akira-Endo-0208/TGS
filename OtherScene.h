#pragma once
#include "Input.h"


class OtherScene
{
public: // �����o�֐�
	void OtherSceneInitialize();
	void OtherSceneUpdate();
	void OtherSceneDraw();
	int GetScene() { return scene; }
	int TitleScene() { return scene = 0; }
	int GameOverScene() { return scene = 2; }
	int GameClaerScene() { return scene = 3; }

private: // �����o�ϐ�
	// �V�[���؂�ւ�
	int scene = 0;
	int selectScene = 5;

	// �L�[�{�[�h�ϐ�
	char key[256] = { 0 }; //�ŐV�̃L�[�{�[�h���p
	char oldkey[256] = { 0 };//1���[�v�i�t���[���j�O�̃L�[�{�[�h���

	// �摜
	int titleGraph = LoadGraph("Resources/Title.png");
	int gameOverGraph = LoadGraph("Resources/gameOver_.png");
	int gameClearGraph = LoadGraph("Resources/GameClear_.png");

	// �|�C���^
	Input* input;
};