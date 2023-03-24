#pragma once

#include "Player.h"
#include "Enemy.h"
#include "Input.h"
#include "Map.h"

class GameScene
{
public:	// �����o�֐�
	void Initialize();	// �X�V
	void Update();		// �X�V
	void Draw();		// �`��
private: // �����o�ϐ�
	// �V�[���؂�ւ�
	int scene = 1;


	int titleX = 0;
	int titleY = 0;
	int gameOverX = 0;
	int gameOverY = 0;
	int gameOverTime = 0;
	int gameOverFlag = 0;
	int gameClearX = 0;
	int gameClearY = 0;
	int gameClearTime = 0;
	int gameClearFlag = 0;
	int spaceX = 300;
	int spaceY = 520;
	int spaceTime = 0;
	int spaceFlag = 0;
	int setumeiX = 0;
	int setumeiY = 0;

	int backGroundGraph = LoadGraph("Resources/backGround.png");
	int titleGraph = LoadGraph("Resources/Title.png");
	int gameOverGraph = LoadGraph("Resources/gameOver_.png");
	int gameClearGraph = LoadGraph("Resources/GameClear_.png");
	int spaceGraph = LoadGraph("Resources/PressSpace.png");
	int setumeiGraph = LoadGraph("Resources/setumei.png");

	int titleBgm = LoadSoundMem("Resources/BGM.mp3");
	int playBgm = LoadSoundMem("Resources/BGM.wav");
	int enemyBulletSe = LoadSoundMem("Resources/laser1.mp3");
	int killSe = LoadSoundMem("Resources/laser2.mp3");

	// �w�i
	int backGroundX[2];
	int backGroundY[2];
	int backGroundSpeed = 3;

	// �X�R�A
	int score = 0;

	// �T�E���h
	int titleBgmFlag = 0;
	int playBgmFlag = 0;

	// �L�[�{�[�h�ϐ�
	char key[256] = { 0 }; //�ŐV�̃L�[�{�[�h���p
	char oldkey[256] = { 0 };//1���[�v�i�t���[���j�O�̃L�[�{�[�h���


	Player* player;
	Enemy* enemy;
	Input* input;
	Map* map;
};