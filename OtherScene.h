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
	int GetSelectScene() { return selectScene; }

private: // �����o�ϐ�
	// �V�[���؂�ւ�
	int scene = 0;
	int selectScene = 4;

	// �L�[�{�[�h�ϐ�
	char key[256] = { 0 }; //�ŐV�̃L�[�{�[�h���p
	char oldkey[256] = { 0 };//1���[�v�i�t���[���j�O�̃L�[�{�[�h���

	// �摜
	int titleGraph = LoadGraph("Resources/title.png");
	int stageSelectGraph = LoadGraph("Resources/stageSelect.png");
	int gameOverGraph = LoadGraph("Resources/gameOver_.png");
	int gameClearGraph = LoadGraph("Resources/clear_kari.png");

	// �|�C���^
	Input* input;
};