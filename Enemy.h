#pragma once
#include "Player.h"


class Enemy
{
public:	// �����o�֐�
	void enemyInitialize(Player* player_);	// ������
	void enemyUpdate();		// �X�V
	void enemyDraw();		// �`��
	void enemyMove();		// ����
	void enemyBorn();		// ���X�|�[��
	void enemyMoveGraph();	// �O���t�B�b�N
	void enemyReset();		// ���Z�b�g
	int GetenemyX(int i) { return enemy1X[i]; }
	int GetenemyY(int i) { return enemy1Y[i];  }
	int GetenemyFlag(int i) {  return enemy1Flag[i]; }
	int GetenemyReset(int i) { return enemy1Flag[i] = 0;  }
private: // �����o�ϐ�
	int enemy1X[10];		// X��
	int enemy1Y[10];		// Y��
	int enemy1R = 25;	// ���a
	int enemy1Speed[10];	// �X�s�[�h�l
	int enemy1Born[10];	// ���X�|�[��
	int enemy1Flag[10];	// �����t���O
	int enemy1GraphTime[10];
	int enemy1Time[10];

	// �摜
	int enemy1Graph = LoadGraph("Resources/suraimu-kari.png");

	// �|�C���^
	Player* player;
};