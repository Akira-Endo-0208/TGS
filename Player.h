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
	float playerX = 500;		// X��
	float playerY = 300;		// Y��
	int playerR = 20;			// ���a
	float playerFallSpeed = 1;	// �����X�s�[�h�l
	float playerJumpSpeed = 10;	// �W�����v�X�s�[�h�l
	int playerJumpTime = 60;	// �W�����v����
	int playerJumpFlag = 1;		// �W�����v�t���O
	int playerFlag = 1;			// �����t���O
	int playerGraph = LoadGraph("Resources/Player1.png"); // �摜

	// �L�[�{�[�h�ϐ�
	char key[256] = { 0 }; //�ŐV�̃L�[�{�[�h���p
	char oldkey[256] = { 0 };//1���[�v�i�t���[���j�O�̃L�[�{�[�h���

	Input* input;
};