#pragma once
#include "Input.h"


class Player
{
public:	// �����o�֐�
	void playerInitialize();	// ������
	void playerUpdate();		// �X�V
	void playerDraw();			// �`��
	void playerMove();			// ����
	void playerReset();			// ���Z�b�g
private: // �����o�ϐ�
	// �v���C���[�ϐ�
	int playerX = 500;		// X��
	int playerY = 300;		// Y��
	int playerR = 15;		// ���a
	int playerSpeed = 7;	// �X�s�[�h�l
	int playerFlag = 1;		// �����t���O
	int playerGraph = LoadGraph("Resources/Player1.png"); // �摜

	// �L�[�{�[�h�ϐ�
	char key[256] = { 0 }; //�ŐV�̃L�[�{�[�h���p
	char oldkey[256] = { 0 };//1���[�v�i�t���[���j�O�̃L�[�{�[�h���

	Input* input;
};