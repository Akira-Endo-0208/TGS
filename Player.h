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
	int playerX = 0;		// X��
	int playerY = 500;		// Y��
	int playerR = 15;		// ���a
	int playerSpeed = 10;	// �X�s�[�h�l
	int playerFlag = 1;		// �����t���O
	int playerGraph = LoadGraph("Resources/Player1.png"); // �摜
	int backGroundGraph = LoadGraph("Resources/backGround.png");

	int playerScreenX = 0;	//�v���C���[�̃��j�^�[���W
	int playerScreenY = 0;	//���݂͎g�p���Ă��Ȃ�

	int scrollX = 0;	//�ړ��ʂ̋L��
	int scrollY = 0;	//���݂͎g�p���Ă��Ȃ�
	int gravity_ = 0;
	int accel_ = 1;
	int canJump = 0;
	// �L�[�{�[�h�ϐ�
	char key[256] = { 0 }; //�ŐV�̃L�[�{�[�h���p
	char oldkey[256] = { 0 };//1���[�v�i�t���[���j�O�̃L�[�{�[�h���

	Input* input;
};